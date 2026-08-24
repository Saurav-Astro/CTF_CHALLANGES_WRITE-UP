#!/usr/bin/env python3
"""
gen_challenge.py — Insane/3_Kernel_Ring_Buffer (REBUILT)

Generates a binary kernel ring buffer dump (dmesg-style physical memory region)
requiring a multi-stage exploit chain:

  Stage 1 — Parse the ring buffer header to locate the start of the printk log records
  Stage 2 — Walk variable-length printk record structs (similar to /dev/kmsg format)
             to collect 8 fragmented hex pairs hidden inside specific subsystem messages
  Stage 3 — Reconstruct a 16-byte AES-256-CBC key from the 8 collected hex pairs,
             interleaved using a documented XOR key-scheduling algorithm
  Stage 4 — Locate the PAYLOAD_MAGIC marker in the ring buffer data section
  Stage 5 — Decrypt the AES-256-CBC ciphertext that follows the marker (IV at +32, CT at +48)

Binary structs used:
  RBHeader   (32 bytes): magic(8) version(4) head_seq(8) tail_seq(8) head_off(4)
  PrintkRecord (variable): rec_len(2) flags(1) level(1) ts_nsec(8) text_len(2) dict_len(2)
                           text[text_len] + dict[dict_len] + padding to 4-byte align

AES params: AES-256-CBC, key=32 bytes (built from 8 fragment pairs + XOR schedule)
"""

import struct, os, random
from Cryptodome.Cipher import AES
from Cryptodome.Util.Padding import pad

FLAG = b"OBV{kr1ng_buff3r_pr1ntk_w4lk_4e5_256_cbc_0p3r4t0r}"

# ── Ring buffer layout ────────────────────────────────────────────────────────
RB_MAGIC    = b"KRNLRING"
RB_VERSION  = 2
RB_HDR_SIZE = 32

# ── AES-256 key construction ──────────────────────────────────────────────────
# 8 fragment pairs (each 4 hex chars = 2 bytes raw) = 16 bytes raw
# Interleaving XOR: final_key[i] = raw_byte[i] ^ XOR_SCHED[i]
FRAG_PAIRS = [
    (b"sched",    "3A1F"),   # subsystem "sched"     → frag  0: 0x3A, 0x1F
    (b"mm",       "C2B7"),   # subsystem "mm"         → frag  1: 0xC2, 0xB7
    (b"net",      "8D4E"),   # subsystem "net"        → frag  2: 0x8D, 0x4E
    (b"acpi",     "F601"),   # subsystem "acpi"       → frag  3: 0xF6, 0x01
    (b"usb",      "7A93"),   # subsystem "usb"        → frag  4: 0x7A, 0x93
    (b"fs",       "21DC"),   # subsystem "fs"         → frag  5: 0x21, 0xDC
    (b"audit",    "B5E8"),   # subsystem "audit"      → frag  6: 0xB5, 0xE8
    (b"crypto",   "4F2A"),   # subsystem "crypto"     → frag  7: 0x4F, 0x2A
]

# XOR schedule (documented in challenge description)
XOR_SCHED = bytes([
    0x11, 0x22, 0x33, 0x44,
    0x55, 0x66, 0x77, 0x88,
    0x99, 0xAA, 0xBB, 0xCC,
    0xDD, 0xEE, 0xFF, 0x00,
    0x0F, 0x1E, 0x2D, 0x3C,
    0x4B, 0x5A, 0x69, 0x78,
    0x87, 0x96, 0xA5, 0xB4,
    0xC3, 0xD2, 0xE1, 0xF0,
])

def build_aes_key() -> bytes:
    raw = b""
    for _, hex_str in FRAG_PAIRS:
        raw += bytes.fromhex(hex_str)
    # Double the 16 raw bytes to get 32 bytes before XOR
    raw32 = raw + bytes([b ^ 0xFF for b in raw])   # second half = bitwise NOT of first
    return bytes(a ^ b for a, b in zip(raw32, XOR_SCHED))

AES_KEY = build_aes_key()

# ── Printk record ─────────────────────────────────────────────────────────────
PRINTK_HDR_FMT    = "<HBBQHH"
PRINTK_HDR_SIZE   = struct.calcsize(PRINTK_HDR_FMT)  # = 16

def make_record(level: int, subsystem: bytes, message: bytes, ts: int) -> bytes:
    """Build a variable-length printk log record."""
    # dict format: "KEY=VALUE\x00" — just the subsystem label for simplicity
    dict_entry = b"SUBSYS=" + subsystem + b"\x00"
    dict_len   = len(dict_entry)
    text_len   = len(message)
    base_size  = PRINTK_HDR_SIZE + text_len + dict_len
    pad_size   = (4 - base_size % 4) % 4
    rec_len    = base_size + pad_size
    hdr = struct.pack(PRINTK_HDR_FMT, rec_len, 0, level, ts, text_len, dict_len)
    return hdr + message + dict_entry + b"\x00" * pad_size

# ── Non-fragment noise messages ────────────────────────────────────────────────
NOISE_MSGS = [
    (3, b"kernel", b"Linux version 6.1.0-23-generic #23 SMP PREEMPT_DYNAMIC"),
    (6, b"kernel", b"Command line: BOOT_IMAGE=/vmlinuz-6.1.0 root=/dev/sda1 ro quiet"),
    (6, b"pci",    b"PCI: Using configuration type 1 for base access"),
    (6, b"acpi",   b"ACPI: 4 ACPI AML tables successfully acquired and loaded"),
    (4, b"kernel", b"Oops: general protection fault, error code 0x0000 [#1] PREEMPT SMP"),
    (6, b"mm",     b"Memory: 7802876K/8388608K available (14338K kernel code)"),
    (6, b"net",    b"NET: Registered PF_INET protocol family"),
    (6, b"usb",    b"usbcore: registered new interface driver usbfs"),
    (6, b"fs",     b"EXT4-fs (sda1): mounted filesystem with ordered data mode"),
    (6, b"audit",  b"audit: initializing netlink subsys (disabled)"),
    (6, b"crypto", b"alg: No test for cbc(aes) (cbc-aes-aesni)"),
    (6, b"sched",  b"sched: RT throttling activated"),
    (7, b"kernel", b"clocksource: tsc-early: mask: 0xffffffffffffffff max_cycles: 0x"),
    (6, b"net",    b"tcp_cubic registered"),
    (4, b"usb",    b"usb 1-1: USB disconnect, device number 2"),
    (6, b"kernel", b"[drm] Initialized i915 1.6.0 20201103 for 0000:00:02.0 on minor 0"),
    (6, b"fs",     b"NFSD: starting 90-second grace period (net f0000098)"),
    (6, b"audit",  b"audit: type=1400 audit(1724164800.123:456): apparmor=ALLOWED"),
]

def build_ring_buffer() -> bytes:
    """Build the complete ring buffer binary blob."""
    records = bytearray()
    ts = 1_000_000_000   # 1s in nanoseconds
    rng = random.Random(0xDEADBEEF)

    # Interleave noise and fragment records in a deterministic random order
    noise_q  = list(NOISE_MSGS)
    frags_q  = list(FRAG_PAIRS)
    rng.shuffle(noise_q)

    seq = 0
    for i in range(len(noise_q) + len(frags_q)):
        ts += rng.randint(500_000, 5_000_000)
        if frags_q and (not noise_q or rng.random() < 0.4):
            subsys, hex_str = frags_q.pop(0)
            # Embed the fragment inside a longer message
            msg = (
                b"[" + subsys.upper() + b"] DIAG: cal_offset=0x" + hex_str.encode()
                + b" tgt=auto_tune cycle=" + str(seq).encode()
            )
            records += make_record(7, subsys, msg, ts)
        else:
            level, subsys, msg = noise_q.pop(0)
            records += make_record(level, subsys, msg + b" seq=" + str(seq).encode(), ts)
        seq += 1

    # Payload section (IV + ciphertext) anchored by a magic marker
    PAYLOAD_MAGIC = b"PAYLOAD_REGION\x00\x00"   # 16 bytes
    aes_iv        = os.urandom(16)
    cipher        = AES.new(AES_KEY, AES.MODE_CBC, aes_iv)
    ciphertext    = cipher.encrypt(pad(FLAG, AES.block_size))
    payload_blob  = PAYLOAD_MAGIC + b"\x00" * 16 + aes_iv + ciphertext

    # Assemble: header + records + payload
    head_off   = RB_HDR_SIZE
    tail_seq   = seq
    head_seq   = 0

    hdr = (
        RB_MAGIC
        + struct.pack("<I", RB_VERSION)
        + struct.pack("<QQ", head_seq, tail_seq)
        + struct.pack("<I", head_off)
    )
    assert len(hdr) == RB_HDR_SIZE

    return bytes(hdr) + bytes(records) + payload_blob

def main():
    os.makedirs("../player", exist_ok=True)
    out  = "../player/kernel_rb.bin"
    blob = build_ring_buffer()
    with open(out, "wb") as f:
        f.write(blob)

    print(f"[+] Generated kernel_rb.bin  ({len(blob):,} bytes)")
    print(f"[+] RB header magic  : {RB_MAGIC!r}  version={RB_VERSION}")
    print(f"[+] AES-256 key      : {AES_KEY.hex()}")
    print(f"[+] Fragment pairs   : {len(FRAG_PAIRS)} (subsystems: {', '.join(s.decode() for s,_ in FRAG_PAIRS)})")
    print(f"[+] XOR schedule     : first 4 bytes = {XOR_SCHED[:4].hex()}")
    print(f"[+] Flag             : {FLAG.decode()}")

if __name__ == "__main__":
    main()
