# CTF Challenges & Complete Master Write-Up Repository

[![CTF Writeups](https://img.shields.io/badge/CTF-Master_Writeups-blue.svg)](https://github.com/Saurav-Astro/CTF_CHALLANGES_WRITE-UP)
[![Status](https://img.shields.io/badge/Status-Fully_Solved-brightgreen.svg)](https://github.com/Saurav-Astro/CTF_CHALLANGES_WRITE-UP)
[![License](https://img.shields.io/badge/License-MIT-orange.svg)](LICENSE)

Welcome to the official repository containing complete, production-grade step-by-step CTF write-ups, reverse engineering analysis, cryptographic solvers, forensic recovery manuals, and exploit primitives across **125+ CTF challenges**.

---

## Table of Contents
- [Executive Overview](#executive-overview)
- [Repository Structure](#repository-structure)
- [Write-Up Access Guide](#write-up-access-guide)
- [Category & Challenge Index](#category--challenge-index)
  - [Reverse Engineering](#1-reverse-engineering)
  - [Cryptography](#2-cryptography)
  - [Forensics & Signal Analysis](#3-forensics--signal-analysis)
  - [Mobile Security (Android & iOS)](#4-mobile-security-android--ios)
  - [Misc & Sandbox Escapes](#5-misc--sandbox-escapes)
- [Tooling & Technical Requirements](#tooling--technical-requirements)
- [License & Usage](#license--usage)

---

## Executive Overview

This repository provides an end-to-end technical reference and educational suite for solving complex CTF challenges across 5 core security categories. Every challenge directory includes:
- **`solution/write-up.txt`**: A dedicated, step-by-step technical write-up detailing the static disassembly, mathematical models, vulnerability primitives, exploit steps, and flag extraction.
- **Challenge Artifacts**: Reversing targets, binaries, pcap captures, ciphertext files, disk images, and mobile packages.

Additionally, a comprehensive master document [`MASTER_WRITEUP.md`](file:///home/astro/Documents/ctf/antigravity/MASTER_WRITEUP.md) is available at the repository root detailing all challenge walkthroughs in a single unified manual.

---

## Repository Structure

```tree
CTF_CHALLANGES_WRITE-UP/
├── MASTER_WRITEUP.md          # Complete unified master write-up manual
├── write-up.txt               # Plaintext master write-up
├── README.md                  # Detailed repository guide & challenge index
├── crypto/                    # Cryptography Challenges (Easy to Insane)
│   ├── easy/
│   ├── medium/
│   ├── hard/
│   └── insane/
├── forensics/                 # Forensics & Signal Analysis Challenges
│   ├── easy/
│   ├── medium/
│   ├── hard/
│   └── insane/
├── misc/                      # PyJail, VM, Regex & Sandbox Challenges
│   ├── easy/
│   ├── medium/
│   ├── hard/
│   └── insane/
├── mobile/                    # Android / iOS Reversing & Exploitation
│   ├── easy/
│   ├── medium/
│   ├── hard/
│   └── insane/
└── reverse/                   # Binary Reversing & Anti-Debugging
    ├── easy/
    ├── medium/
    ├── hard/
    └── insane/
```

---

## Write-Up Access Guide

Each individual challenge folder is structured as follows:
```tree
<category>/<difficulty>/<challenge_name>/
├── desc.txt                   # Challenge description & mission objectives
├── flag.txt                   # Verified target flag
└── solution/
    └── write-up.txt           # Professional step-by-step technical write-up
```

To view a specific write-up, navigate directly to `<category>/<difficulty>/<challenge_name>/solution/write-up.txt`.

---

## Category & Challenge Index

### 1. Reverse Engineering
Focuses on x86_64 and ARM64 disassembly, anti-debugging bypasses (`ptrace`, `TracerPid`, hardware timing), Feistel network reversing, VM bytecode lifting, control flow de-flattening (OLLVM), and multi-architecture verification.
- **Easy**: Key Matrix, Xor Cascade, Byte Swapper, Shift Cipher, State Walk
- **Medium**: Matrix Cipher, Custom PRNG, Bit Rotator, Bytecode Checker, Poly XOR
- **Hard**: Cipher Lock, Shadow Packer, Signal Decrypter, Protocol Vault, State Matrix
- **Insane**: Oblivion VM, Kronos Polymorphic, Kernel Phantom (eBPF), OLLVM Flattened, Titan Hydra

### 2. Cryptography
Covers mathematical cryptanalysis including RSA attacks (Hastad broadcast, Wiener, Common Modulus), AES block cipher vulnerabilities (CBC bit-flipping, padding oracle, ECB byte-at-a-time), Elliptic Curve invalid subgroup attacks, LFSR Berlekamp-Massey synthesis, Pohlig-Hellman discrete log, and LLL Lattice basis reduction (CVP embedding).
- **Easy**: Caesar Shift Vigenere, Multi Encoding Chain, Single Byte XOR, XOR Keystream Reuse, RSA Small Exponent, Substitution Cipher, Diffie-Hellman Basic
- **Medium**: RSA Common Modulus, AES CBC Bit Flipping, AES ECB Pattern Oracle, Diffie-Hellman Weak Generator, LFSR State Recovery
- **Hard**: RSA Hastad Broadcast, AES CBC Padding Oracle, Custom Feistel Cipher, RSA Fault Attack, ECC Invalid Curve Attack, LCG Seed Prediction
- **Insane**: RSA Wiener Attack (Pohlig-Hellman), Lattice LLL Reduction (CVP), Dual EC DRBG Backdoor, Fully Homomorphic Noise Leak, Differential Cryptanalysis SBox

### 3. Forensics & Signal Analysis
Involves PCAP network traffic exfiltration (covert DNS, HTTP POST streams, ICMP payloads), magic byte header repair, FAT12/ext4 disk journal reconstruction, memory heap node analysis, LSB image steganography, and audio spectrogram decoding.
- **Easy**: Audio Morse, Black Ops, Corrupted PNG, DEAD DROP, Nested Archive, Pcap DNS Exfil, The Vault
- **Medium**: Audio Spectrogram, Disk FAT12 Deleted, KEY MATRIX, Log Investigator, Lsb Stego, NotchItUp, Pcap HTTP Stream
- **Hard**: Core Dump Recovery, Custom Pcapng TLS, Disk Ext4 Journal, Pcap ICMP Covert, Polyglot File
- **Insane**: Black Vault, Firmware SPI Flash, Kernel Ring Buffer, Multi Stage Memory Pcap, Ransomware NTFS MFT, Volatile RAM Dump

### 4. Mobile Security (Android & iOS)
Covers Android APK decompilation (Jadx/APKTool), exported activity exploitation, cleartext SharedPreferences & SQLite database inspection, Smali bytecode patching, Frida dynamic instrumentation (SSL pinning bypass, anti-Frida mitigation), native JNI `.so` reversing, and iOS Keychain extraction.
- **Easy**: Hardcoded Credentials, Exported Activity Exploit, Unencrypted Shared Prefs, SQLite DB Decryption, Asset File Extraction
- **Medium**: Smali Bytecode Patch, Custom DEX Payload, Android Keystore Alias, WebView JS Interface, Intent Spoofing Vuln
- **Hard**: Native SO Library Reversing, Certificate Pinning Bypass, Frida Anti Detection, Encrypted Realm DB, Custom ARM64 Smali Injection
- **Insane**: Custom Android Packer Unpacking, Native ARM64 AntiDebugging, Whitebox AES Key Extraction, Dynamic DexClassLoader Decryption, Dual Architecture JNI Reversing

### 5. Misc & Sandbox Escapes
Focuses on Python jail escapes (builtins filtering, AST audit hooks, zero-builtins scope recovery), Brainfuck interpreter execution and JIT compiler bugs, regex ReDoS & parsing bypasses, known-plaintext ZIP attacks, audio DTMF decoding, and Z3 symbolic execution / SMT constraint logic.
- **Easy**: Brainfuck Interpreter, QR Matrix Reconstruction, PyJail Basic Bypass, Polyglot File Analysis, Regex Puzzle Solver
- **Medium**: PyJail AST Bypass, Bytecode VM Decompile, Known Plaintext Zip, Game Memory Patch, Audio DTMF Decoder
- **Hard**: Zero Builtins PyJail, Custom Protocol StateMachine, Game AntiCheat Bypass, Maze Pathfinding Automata, Custom Binary Unpacker
- **Insane**: Symbolic Execution Z3, Brainfuck x86 JIT Compiler, Obfuscated JS VM Interpreter, Self Referential Quine Vuln, SAT SMT Constraint Logic

---

## Tooling & Technical Requirements

To run the solvers and inspect artifacts locally:
- **Reverse Engineering**: Ghidra, IDA Pro, GDB (`pwndbg`/`GEF`), `pwntools`, `z3-solver`
- **Cryptography**: Python 3, SageMath, `pycryptodome`, `fpylll`
- **Forensics**: Wireshark, `tshark`, `Volatility 3`, `binwalk`, `zsteg`, Audacity, Sleuth Kit (`fls`/`icat`)
- **Mobile**: Jadx-GUI, `apktool`, Frida, ADB, Objection, SQLCipher
- **Misc**: Python 3, `z3-solver`, `pwntools`, `multimon-ng`

---

## License & Usage

This project and write-up collection is released under the **MIT License**. Created for cybersecurity education, research, and defensive training.
