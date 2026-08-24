#!/usr/bin/env python3
"""
gen_challenge.py — Insane/2_Volatile_RAM_Dump (REBUILT v2)

task_struct layout (72 bytes, all little-endian):
  [0 ]  8  magic "TS2_HDR\\x00"
  [8 ]  8  next_phys
  [16]  8  prev_phys
  [24]  4  pid
  [28]  4  tgid
  [32] 16  comm (null-padded)
  [48]  8  mm_phys
  [56] 16  tail_pad
Total = 72 bytes

mm_struct layout (48 bytes):
  [0 ]  8  magic "MM2_HDR\\x00"
  [8 ]  8  heap_a_phys
  [16]  8  heap_b_phys
  [24]  8  mmap_phys
  [32] 16  reserved
Total = 48 bytes
"""

import struct, os
from Cryptodome.Cipher import AES
from Cryptodome.Util.Padding import pad

FLAG   = b"OBV{l1m3_ph451c4l_p4g3_w4lk_4e5_m3m0ry_8f2c}"
FRAG_A = b"GH05T_AG"   # 8 bytes
FRAG_B = b"3NT_K3Y!"   # 8 bytes
AES_KEY = FRAG_A + FRAG_B   # 16-byte AES-128 key

LIME_MAGIC = 0x4C694D45
LIME_VER   = 1
HDR_SIZE   = 32

R1_START = 0x00000000; R1_END = 0x00080000
R2_START = 0x00200000; R2_END = 0x00280000

TASK_LIST_BASE = 0x00001000
MM_STRUCT_PHYS = 0x00005000
HEAP_A_BASE    = 0x00200200
HEAP_B_BASE    = 0x00210400
MMAP_BASE      = 0x00250000
FRAG_A_INNER   = 0x100
FRAG_B_INNER   = 0x200

TS_SIZE = 72
MM_SIZE = 48

TS_MAGIC = b"TS2_HDR\x00"
MM_MAGIC = b"MM2_HDR\x00"


def lime_header(s: int, e: int) -> bytes:
    return struct.pack("<IIQQ8x", LIME_MAGIC, LIME_VER, s, e)


def make_task(next_p: int, prev_p: int, pid: int, comm: str, mm_p: int = 0) -> bytes:
    comm_b = comm.encode()[:16].ljust(16, b"\x00")
    raw = (
        TS_MAGIC
        + struct.pack("<QQ", next_p, prev_p)
        + struct.pack("<II", pid, pid)
        + comm_b
        + struct.pack("<Q", mm_p)
        + b"\x00" * 16
    )
    assert len(raw) == TS_SIZE, f"task_struct: {len(raw)} != {TS_SIZE}"
    return raw


def make_mm(heap_a: int, heap_b: int, mmap: int) -> bytes:
    raw = (
        MM_MAGIC
        + struct.pack("<QQQ", heap_a, heap_b, mmap)
        + b"\x00" * 16
    )
    assert len(raw) == MM_SIZE
    return raw


def build_r1() -> bytearray:
    buf = bytearray(R1_END - R1_START)
    processes = [
        (1,    "systemd"),
        (42,   "kworker/0:1"),
        (87,   "ksoftirqd/0"),
        (100,  "sshd"),
        (312,  "nginx"),
        (500,  "python3"),
        (1000, "bash"),
        (1337, "ghost_agent"),
        (1338, "su"),
        (1400, "ps"),
    ]
    n = len(processes)
    addrs = [TASK_LIST_BASE + i * TS_SIZE for i in range(n)]

    for i, (pid, comm) in enumerate(processes):
        mm_p = MM_STRUCT_PHYS if pid == 1337 else 0
        ts   = make_task(addrs[(i+1)%n], addrs[(i-1)%n], pid, comm, mm_p)
        off  = addrs[i] - R1_START
        buf[off:off+TS_SIZE] = ts

    mm = make_mm(HEAP_A_BASE, HEAP_B_BASE, MMAP_BASE)
    off = MM_STRUCT_PHYS - R1_START
    buf[off:off+MM_SIZE] = mm

    noise = [
        b"Linux version 6.1.0-23-generic (gcc version 12.3.0)",
        b"BIOS-provided physical RAM map:",
        b"ACPI: LAPIC enabled",
        b"NET: Registered PF_INET",
        b"cryptomgr: aes registered",
    ]
    off2 = 0x8000
    for n_str in noise:
        buf[off2:off2+len(n_str)] = n_str
        off2 += len(n_str) + 16
    return buf


def build_r2() -> bytearray:
    buf = bytearray(R2_END - R2_START)

    ha_off = HEAP_A_BASE - R2_START
    buf[ha_off:ha_off+14] = b"HEAP_REGION_A\x00"
    buf[ha_off+FRAG_A_INNER:ha_off+FRAG_A_INNER+8] = FRAG_A

    hb_off = HEAP_B_BASE - R2_START
    buf[hb_off:hb_off+14] = b"HEAP_REGION_B\x00"
    buf[hb_off+FRAG_B_INNER:hb_off+FRAG_B_INNER+8] = FRAG_B

    aes_iv     = os.urandom(16)
    cipher_obj = AES.new(AES_KEY, AES.MODE_CBC, aes_iv)
    ciphertext = cipher_obj.encrypt(pad(FLAG, AES.block_size))

    mm_off = MMAP_BASE - R2_START
    buf[mm_off:mm_off+17]                         = b"MMAP_EXEC_REGION\x00"
    buf[mm_off+32:mm_off+48]                      = aes_iv
    buf[mm_off+48:mm_off+48+len(ciphertext)]      = ciphertext

    env = [b"USER=root", b"HOME=/root", b"SHELL=/bin/bash"]
    off = 0x500
    for e in env:
        buf[off:off+len(e)] = e; off += len(e)+8
    return buf


def main():
    os.makedirs("../player", exist_ok=True)
    out = "../player/memory.raw"
    r1  = build_r1()
    r2  = build_r2()
    with open(out, "wb") as f:
        f.write(lime_header(R1_START, R1_END-1))
        f.write(r1)
        f.write(lime_header(R2_START, R2_END-1))
        f.write(r2)
    size = os.path.getsize(out)
    print(f"[+] memory.raw  ({size:,} bytes)")
    print(f"[+] task_struct_size={TS_SIZE}  mm_struct_size={MM_SIZE}")
    print(f"[+] LiME R1: {R1_START:#x}-{R1_END-1:#x}  LiME R2: {R2_START:#x}-{R2_END-1:#x}")
    print(f"[+] task_list @ {TASK_LIST_BASE:#x}  mm_struct @ {MM_STRUCT_PHYS:#x}")
    print(f"[+] heap_a @ {HEAP_A_BASE:#x}+{FRAG_A_INNER:#x}  heap_b @ {HEAP_B_BASE:#x}+{FRAG_B_INNER:#x}")
    print(f"[+] mmap @ {MMAP_BASE:#x}  AES key: {AES_KEY!r}")
    print(f"[+] Flag: {FLAG.decode()}")


if __name__ == "__main__":
    main()
