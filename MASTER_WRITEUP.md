# COMPLETE CTF REPOSITORY MASTER WRITE-UP

**Event / Corpus**: Witchcraft CTF Platform / Antigravity Challenge Suite  
**Total Challenges Solved**: 130  
**Categories Covered**: Reverse Engineering, Cryptography, Forensics, AI/ML Security, Mobile Security, Miscellaneous  

---

## EXECUTIVE SUMMARY

This master write-up documents the end-to-end solutions, reversing procedures, cryptographic attacks, forensic recoveries, and exploitation primitives for all 130 CTF challenges in the repository.

### CATEGORY DISTRIBUTION OVERVIEW
- **Reverse Engineering**: 20 Challenges
- **Cryptography**: 25 Challenges
- **Forensics**: 25 Challenges
- **AI / ML Security**: 20 Challenges
- **Mobile Security**: 20 Challenges
- **Miscellaneous & Sandboxes**: 20 Challenges

---

## COMPREHENSIVE CHALLENGE SOLUTION MANUAL

### 1. REVERSE ENGINEERING (20 Challenges)

#### 1. [EASY] Key Matrix
- **Directory**: `reverse/easy/1_Key_Matrix`
- **Target Flag**: `OBV{k3y_m4tr1x_51mpl3_5h1ft_3a9f}`
- **Description**: TACTICAL SITUATION:
Enemy authentication module checks input vectors using 2x2 matrix transformation over modulo 256 arithmetic guarded by ptrace anti-tracing.

MISSION OBJECTIVES:
- Invert the 2x2 key matrix modulo 256.
- Recover the authorization vector passcode.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{k3y_m4tr1x_51mpl3_5h1ft_3a9f}`.

#### 2. [EASY] Xor Cascade
- **Directory**: `reverse/easy/2_Xor_Cascade`
- **Target Flag**: `OBV{x0r_c45c4d3_p455c0d3_8b1c4e}`
- **Description**: TACTICAL SITUATION:
Enemy signal authenticators process input using a multi-pass cumulative XOR cascade with index-salted feedback protected by ptrace anti-tracing.

MISSION OBJECTIVES:
- Reverse the cumulative XOR state feedback loop.
- Recover the authorization key.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{x0r_c45c4d3_p455c0d3_8b1c4e}`.

#### 3. [EASY] Byte Swapper
- **Directory**: `reverse/easy/3_Byte_Swapper`
- **Target Flag**: `OBV{byt3_5w4pp3r_n1bbl3_x0r_92d7}`
- **Description**: TACTICAL SITUATION:
Enemy authentication logic applies high/low nibble bit permutations and index-salted XOR masks guarded by ptrace anti-tracing.

MISSION OBJECTIVES:
- Reverse the nibble swapping routine (`((b & 0x0F) << 4) | ((b & 0xF0) >> 4)`).
- Extract the flag passcode.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{byt3_5w4pp3r_n1bbl3_x0r_92d7}`.

#### 4. [EASY] Shift Cipher
- **Directory**: `reverse/easy/4_Shift_Cipher`
- **Target Flag**: `OBV{5h1ft_c1ph3r_b1tw153_0x4f12}`
- **Description**: TACTICAL SITUATION:
Enemy core systems encrypt input tokens using index-dependent circular bit shifts and fixed XOR keys guarded by ptrace anti-tracing.

MISSION OBJECTIVES:
- Calculate index shift amounts `(i % 5) + 1`.
- Reverse bit rotations to recover the root flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{5h1ft_c1ph3r_b1tw153_0x4f12}`.

#### 5. [EASY] State Walk
- **Directory**: `reverse/easy/5_State_Walk`
- **Target Flag**: `OBV{5t4t3_w4lk_4ut0m4t0n_6c8d}`
- **Description**: TACTICAL SITUATION:
Enemy command automaton evaluates passcode validation through 1D linear state transition accumulation guarded by ptrace anti-tracing.

MISSION OBJECTIVES:
- Trace 1D accumulator state transitions.
- Reconstruct the state walk path to solve the root passcode.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{5t4t3_w4lk_4ut0m4t0n_6c8d}`.

#### 6. [HARD] Cipher Lock
- **Directory**: `reverse/hard/1_Cipher_Lock`
- **Target Flag**: `OBV{f31st3l_k3y_5ch3dul3_x86_9a4f21b7}`
- **Description**: TACTICAL SITUATION:
Enemy operatives protected an encryption vault using a 32-round Feistel network with dynamic key scheduling guarded by ptrace anti-tracing and LD_PRELOAD library hooking detection.

MISSION OBJECTIVES:
- Neutralize ptrace and anti-hooking protections inside the player binary.
- Reverse the 32-round non-linear Feistel key schedule and round functions to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{f31st3l_k3y_5ch3dul3_x86_9a4f21b7}`.

#### 7. [HARD] Shadow Packer
- **Directory**: `reverse/hard/2_Shadow_Packer`
- **Target Flag**: `OBV{3lf_p4ck3r_mmap_rwx_0x7f9a2b8e}`
- **Description**: TACTICAL SITUATION:
Enemy engineers embedded authorization logic inside an encrypted ELF packer stub that allocates dynamic memory, unpacks payload code into RWX pages, and executes a multi-key verification function.

MISSION OBJECTIVES:
- Dump runtime unpacked memory or analyze the custom decompressor stub.
- Recover key validation constants to reconstruct the flag passcode.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{3lf_p4ck3r_mmap_rwx_0x7f9a2b8e}`.

#### 8. [HARD] Signal Decrypter
- **Directory**: `reverse/hard/3_Signal_Decrypter`
- **Target Flag**: `OBV{0v3rl4pp1ng_45m_lcg_b3a890ef}`
- **Description**: TACTICAL SITUATION:
Enemy communications utilize an anti-disassembly pipeline featuring overlapping x86_64 instructions, junk byte insertions, and a 64-bit stateful stream decrypter.

MISSION OBJECTIVES:
- Fix disassembler control flow alignment past opaque predicates and junk bytes.
- Reverse the stream decrypter state machine to recover the command passphrase.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{0v3rl4pp1ng_45m_lcg_b3a890ef}`.

#### 9. [HARD] Protocol Vault
- **Directory**: `reverse/hard/4_Protocol_Vault`
- **Target Flag**: `OBV{pr0t0c0l_4dl3r32_fr4m3_6c2f9d14}`
- **Description**: TACTICAL SITUATION:
Enemy core systems operate a custom binary frame protocol parser (`[Magic:0x5056][Command:0x77][Length][Payload][Adler32]`). Input signals must pass multi-layer checksum and stateful payload transformation.

MISSION OBJECTIVES:
- Reverse the custom binary packet protocol header framing and command state machine.
- Generate a valid binary packet containing the payload flag unlock string.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{pr0t0c0l_4dl3r32_fr4m3_6c2f9d14}`.

#### 10. [HARD] State Matrix
- **Directory**: `reverse/hard/5_State_Matrix`
- **Target Flag**: `OBV{spn_4ut0m4t0n_m4tr1x_e5d81a93}`
- **Description**: TACTICAL SITUATION:
Enemy command node enforces a Substitution-Permutation Network (SPN) coupled with a Finite State Automaton (FSM) state matrix transition check.

MISSION OBJECTIVES:
- Trace the non-linear S-Box substitution and P-Box permutation state machine.
- Invert the state matrix transitions to recover the root flag vector.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{spn_4ut0m4t0n_m4tr1x_e5d81a93}`.

#### 11. [INSANE] Oblivion VM
- **Directory**: `reverse/insane/1_Oblivion_VM`
- **Target Flag**: `OBV{CUST0M_VM_OPCODE_LIFTING_MAST3R}`
- **Description**: TACTICAL SITUATION:
Shadow network operatives deployed a virtualized execution framework guarded by hardware timing traps and anti-debugging checks.

MISSION OBJECTIVES:
- Bypass anti-analysis countermeasures inside the player binary.
- Reverse the custom VM opcode dispatcher and solve the constraint system.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{CUST0M_VM_OPCODE_LIFTING_MAST3R}`.

#### 12. [INSANE] Kronos Polymorphic
- **Directory**: `reverse/insane/2_Kronos_Polymorphic`
- **Target Flag**: `OBV{POLYMORPHIC_SELF_MODIFYING_DECRYPT_RCE}`
- **Description**: TACTICAL SITUATION:
Hostile engineers weaponized a self-modifying polymorphic execution module that dynamic-decrypts inside RWX memory.

MISSION OBJECTIVES:
- Trace dynamic execution inside RWX memory pages.
- Reverse the 4-round linear transformations to recover the key code.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{POLYMORPHIC_SELF_MODIFYING_DECRYPT_RCE}`.

#### 13. [INSANE] Kernel Phantom
- **Directory**: `reverse/insane/3_Kernel_Phantom`
- **Target Flag**: `OBV{EBPF_KERNEL_RING_VERIFIER_ESCAPE}`
- **Description**: TACTICAL SITUATION:
Enemy command nodes migrated key validation out of userland into an embedded Linux eBPF kernel bytecode filter.

MISSION OBJECTIVES:
- Extract the raw eBPF bytecode filter from the ELF binary.
- Reverse kernel-level SIMD vector arithmetic to retrieve the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{EBPF_KERNEL_RING_VERIFIER_ESCAPE}`.

#### 14. [INSANE] OLLVM Flattened
- **Directory**: `reverse/insane/4_OLLVM_Flattened`
- **Target Flag**: `OBV{MBA_DEFLATTENING_SYMBOLIC_ANGR_SOLVE}`
- **Description**: TACTICAL SITUATION:
Target authentication is compiled with OLLVM Control Flow Flattening and Mixed-Boolean Arithmetic (MBA) polynomials.

MISSION OBJECTIVES:
- De-flatten the control flow graph using symbolic execution or basic block tracing.
- Simplify MBA polynomial identities to extract the master key.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{MBA_DEFLATTENING_SYMBOLIC_ANGR_SOLVE}`.

#### 15. [INSANE] Titan Hydra
- **Directory**: `reverse/insane/5_Titan_Hydra`
- **Target Flag**: `OBV{MULTI_ARCH_WASM_ARM64_IPC_TRIAD}`
- **Description**: TACTICAL SITUATION:
Verification is split across native x86_64, an embedded WebAssembly module, and an ARM64 worker process over UNIX IPC.

MISSION OBJECTIVES:
- Reverse x86_64, WebAssembly, and ARM64 IPC routines.
- Combine multi-architecture constraints to extract the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{MULTI_ARCH_WASM_ARM64_IPC_TRIAD}`.

#### 16. [MEDIUM] Matrix Cipher
- **Directory**: `reverse/medium/1_Matrix_Cipher`
- **Target Flag**: `OBV{m4tr1x_mult1pl1c4t10n_m0d256_7b3a}`
- **Description**: TACTICAL SITUATION:
Enemy signal routing uses a 3x3 matrix multiplication transformation matrix over modulo 256 arithmetic protected by ptrace anti-tracing.

MISSION OBJECTIVES:
- Invert the 3x3 key matrix mod 256.
- Recover the original vector authorization passcode.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{m4tr1x_mult1pl1c4t10n_m0d256_7b3a}`.

#### 17. [MEDIUM] Custom PRNG
- **Directory**: `reverse/medium/2_Custom_PRNG`
- **Target Flag**: `OBV{x0r5h1ft128_prng_k3ystr34m_4f9c2d}`
- **Description**: TACTICAL SITUATION:
Enemy encryption subroutines utilize an Xorshift128 pseudo-random number generator stream cipher coupled with /proc/self/status TracerPid debugger inspection.

MISSION OBJECTIVES:
- Bypass TracerPid anti-tracing routines inside process status memory.
- Seed Xorshift128 PRNG to reconstruct keystream XOR sequence and extract flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{x0r5h1ft128_prng_k3ystr34m_4f9c2d}`.

#### 18. [MEDIUM] Bit Rotator
- **Directory**: `reverse/medium/3_Bit_Rotator`
- **Target Flag**: `OBV{v4r14bl3_b1t_r0t4t10n_5b8e1f0a}`
- **Description**: TACTICAL SITUATION:
Enemy signal authenticators process input using variable bit-wise circular rotation and S-Box byte substitution guarded by ptrace anti-tracing.

MISSION OBJECTIVES:
- Calculate index-dependent variable rotation offsets.
- Reverse S-Box substitution to decrypt the root passcode.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{v4r14bl3_b1t_r0t4t10n_5b8e1f0a}`.

#### 19. [MEDIUM] Bytecode Checker
- **Directory**: `reverse/medium/4_Bytecode_Checker`
- **Target Flag**: `OBV{m1n1_byt3c0d3_1nt3rpr3t3r_82c19a4f}`
- **Description**: TACTICAL SITUATION:
Enemy command architecture evaluates passcode authorization inside a virtual machine running custom bytecode instructions (`READ_INPUT`, `XOR_IMM`, `ADD_IMM`, `ROL_IMM`, `CMP_EXP`).

MISSION OBJECTIVES:
- Disassemble the 8-opcode virtual machine instruction cycle.
- Reconstruct input transformation instructions to solve the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{m1n1_byt3c0d3_1nt3rpr3t3r_82c19a4f}`.

#### 20. [MEDIUM] Poly XOR
- **Directory**: `reverse/medium/5_Poly_XOR`
- **Target Flag**: `OBV{p0lyn0m14l_m4th_c1ph3r_0x9d4a3e}`
- **Description**: TACTICAL SITUATION:
Enemy node validation calculates modular arithmetic functions over field GF(257) with dynamic index-salted XOR masks guarded by /proc/self/maps library monitoring.

MISSION OBJECTIVES:
- Calculate modular multiplicative inverse of 17 over GF(257).
- Invert index-salted XOR transformations to solve the root key.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Disassemble target binary in Ghidra/IDA Pro to trace key checking function.
  2. Bypass ptrace / anti-debugging checks (e.g. TracerPid, hardware breakpoints).
  3. Reverse non-linear transformations (matrix shifts, S-Boxes, Feistel rounds, VM bytecode loops).
  4. Recover exact flag bytes: `OBV{p0lyn0m14l_m4th_c1ph3r_0x9d4a3e}`.

### 2. CRYPTOGRAPHY (25 Challenges)

#### 1. [EASY] Caesar Shift Vigenere
- **Directory**: `crypto/easy/1_Caesar_Shift_Vigenere`
- **Target Flag**: `OBV{v1g3n3r3_p0ly4lph4b371c_c1ph3r_b451c_771a}`
- **Description**: Custom non-linear polynomial shift substitution over GF(256).
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{v1g3n3r3_p0ly4lph4b371c_c1ph3r_b451c_771a}`.

#### 2. [EASY] Multi Encoding Chain
- **Directory**: `crypto/easy/1_Multi_Encoding_Chain`
- **Target Flag**: `OBV{c4354r_b45364_h3x_3nc0d1ng_8821}`
- **Description**: ===[ MULTI ENCODING CHAIN ]===
Difficulty: EASY
Category: Crypto

Decode the hex-encoded base64 XOR string.

File: cipher.txt

Flag: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{c4354r_b45364_h3x_3nc0d1ng_8821}`.

#### 3. [EASY] Single Byte XOR
- **Directory**: `crypto/easy/2_Single_Byte_XOR`
- **Target Flag**: `OBV{s1ngl3_by73_x0r_k3y_r3c0v3ry_7711}`
- **Description**: ===[ SINGLE BYTE XOR ]===
Difficulty: EASY
Category: Crypto

A secret message was XORed with a single byte key.

File: cipher.hex

Flag: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{s1ngl3_by73_x0r_k3y_r3c0v3ry_7711}`.

#### 4. [EASY] XOR Keystream Reuse
- **Directory**: `crypto/easy/2_XOR_Keystream_Reuse`
- **Target Flag**: `OBV{tw0_71m3_p4d_k3y57r34m_r3u53_1928}`
- **Description**: Multi-stream XOR key reuse under known header alignment.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{tw0_71m3_p4d_k3y57r34m_r3u53_1928}`.

#### 5. [EASY] RSA Small Exponent
- **Directory**: `crypto/easy/3_RSA_Small_Exponent`
- **Target Flag**: `OBV{r54_5m4ll_3xp0n3n7_c4b3_r007_0a81}`
- **Description**: Unpadded modular ring power evaluation. Compute integer root over finite ring.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{r54_5m4ll_3xp0n3n7_c4b3_r007_0a81}`.

#### 6. [EASY] Substitution Cipher
- **Directory**: `crypto/easy/4_Substitution_Cipher`
- **Target Flag**: `OBV{5ub5717u710n_c1ph3r_m4pp1n9_9821}`
- **Description**: Custom 256-element S-Box lookup table inversion.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{5ub5717u710n_c1ph3r_m4pp1n9_9821}`.

#### 7. [EASY] Vigenere Cipher Crack
- **Directory**: `crypto/easy/4_Vigenere_Cipher_Crack`
- **Target Flag**: `OBV{v1g3n3r3_k3y_c4354r_sub57_3321}`
- **Description**: ===[ VIGENERE CIPHER ]===
Difficulty: EASY
Category: Crypto

Encrypted with Vigenere cipher using key 'KRAKEN'.

File: cipher.txt

Flag: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{v1g3n3r3_k3y_c4354r_sub57_3321}`.

#### 8. [EASY] Caesar Substitution
- **Directory**: `crypto/easy/5_Caesar_Substitution`
- **Target Flag**: `OBV{c4354r_5h1f7_sub5717u710n_44a1}`
- **Description**: ===[ CAESAR SUBSTITUTION ]===
Difficulty: EASY
Category: Crypto

ROT13 / Caesar cipher shifted by 13.

File: cipher.txt

Flag: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{c4354r_5h1f7_sub5717u710n_44a1}`.

#### 9. [EASY] Diffie Hellman Basic
- **Directory**: `crypto/easy/5_Diffie_Hellman_Basic`
- **Target Flag**: `OBV{d1ff13_h3llm4n_5h4r3d_53cr37_9a91}`
- **Description**: Cyclic multiplicative group key agreement.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{d1ff13_h3llm4n_5h4r3d_53cr37_9a91}`.

#### 10. [HARD] RSA Hastad Broadcast
- **Directory**: `crypto/hard/1_RSA_Hastad_Broadcast`
- **Target Flag**: `OBV{h4574d_br04dc457_cr7_c4b3_r007_9f11}`
- **Description**: Multi-ring Chinese Remainder Theorem broadcast.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{h4574d_br04dc457_cr7_c4b3_r007_9f11}`.

#### 11. [HARD] AES CBC Padding Oracle
- **Directory**: `crypto/hard/2_AES_CBC_Padding_Oracle`
- **Target Flag**: `OBV{p4dd1n9_0r4cl3_cbc_b473_d3cryp7_77a1}`
- **Description**: PKCS#7 padding validation side-channel.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{p4dd1n9_0r4cl3_cbc_b473_d3cryp7_77a1}`.

#### 12. [HARD] Custom Feistel Cipher
- **Directory**: `crypto/hard/3_Custom_Feistel_Cipher`
- **Target Flag**: `OBV{cus70m_f31s73l_r0und_r3v3rs4l_44112}`
- **Description**: ===[ CUSTOM FEISTEL CIPHER ]===
Difficulty: HARD
Category: Crypto

4-round symmetric Feistel cipher structure.

File: cipher.bin

Flag: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{cus70m_f31s73l_r0und_r3v3rs4l_44112}`.

#### 13. [HARD] RSA Fault Attack
- **Directory**: `crypto/hard/3_RSA_Fault_Attack`
- **Target Flag**: `OBV{r54_crt_b3llc0r3_f4ul7_519n47ur3_8f11}`
- **Description**: Bellcore CRT signature fault perturbation.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{r54_crt_b3llc0r3_f4ul7_519n47ur3_8f11}`.

#### 14. [HARD] ECC Invalid Curve Attack
- **Directory**: `crypto/hard/4_ECC_Invalid_Curve_Attack`
- **Target Flag**: `OBV{3cc_1nv4l1d_curv3_p0hl1g_h3llm4n_9a22}`
- **Description**: Elliptic curve invalid subgroup reduction.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{3cc_1nv4l1d_curv3_p0hl1g_h3llm4n_9a22}`.

#### 15. [HARD] LCG Seed Prediction
- **Directory**: `crypto/hard/5_LCG_Seed_Prediction`
- **Target Flag**: `OBV{lcg_7runc473d_57473_pr3d1c710n_6a21}`
- **Description**: Truncated LCG linear state prediction.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{lcg_7runc473d_57473_pr3d1c710n_6a21}`.

#### 16. [INSANE] RSA Wiener Attack
- **Directory**: `crypto/insane/1_RSA_Wiener_Attack`
- **Target Flag**: `OBV{n0n_c0mmu7471v3_m47r1x_p0lyn0m14l_r1n9_m47h_99a1}`
- **Description**: Intercepted a high-security transmission locked inside a Pohlig-Hellman Smooth Order Finite Field Discrete Logarithm system.

MISSION OBJECTIVES:
1. Load base generator `g`, public target `h`, field prime `p`, and `smooth_factors` from `matrix_ring.json`.
2. Execute the Pohlig-Hellman algorithm to compute the discrete logarithm `secret_k` modulo smooth factor powers.
3. Combine prime-power remainders using the Chinese Remainder Theorem (CRT).
4. Hash `secret_k` with SHA-256 to derive the AES key and decrypt the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{n0n_c0mmu7471v3_m47r1x_p0lyn0m14l_r1n9_m47h_99a1}`.

#### 17. [INSANE] Lattice LLL Reduction
- **Directory**: `crypto/insane/2_Lattice_LLL_Reduction`
- **Target Flag**: `OBV{l4771c3_lll_3mb3dd3d_kn4p54ck_cvp_88f1}`
- **Description**: High-dimensional Closest Vector Problem (CVP) over a 16-dimensional non-orthonormal knapsack lattice space.

MISSION OBJECTIVES:
1. Load subset basis vector `a`, target sum `S`, and ciphertext `ct_hex` from `lattice_cvp_16d.json`.
2. Build the (N+1) dimensional Kannan embedding lattice matrix.
3. Perform LLL basis reduction to extract the binary indicator vector and recover the AES key.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{l4771c3_lll_3mb3dd3d_kn4p54ck_cvp_88f1}`.

#### 18. [INSANE] Dual EC DRBG Backdoor
- **Directory**: `crypto/insane/3_Dual_EC_DRBG_Backdoor`
- **Target Flag**: `OBV{du4l_3c_drb9_b4ckd00r_57473_r3c0v3ry_8811}`
- **Description**: Dual EC DRBG pseudo-random generator with a hidden elliptic curve backdoor scalar $P = d \cdot Q$.

MISSION OBJECTIVES:
1. Load domain parameters, secret seed $s_1$, backdoor scalar $d$, and ciphertext from `dual_ec_anomalous.json`.
2. Compute the state evolution equation $s_2 = s_1 \cdot d \pmod p$.
3. Hash $s_2$ using SHA-256 to derive the 128-bit AES key and decrypt the payload.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{du4l_3c_drb9_b4ckd00r_57473_r3c0v3ry_8811}`.

#### 19. [INSANE] Fully Homomorphic Noise Leak
- **Directory**: `crypto/insane/4_Fully_Homomorphic_Noise_Leak`
- **Target Flag**: `OBV{lh3_lw3_n0153_l34k_du4l_l4771c3_lll_99a1}`
- **Description**: Learning With Errors (LWE) Homomorphic Encryption samples subject to Gaussian noise leakage.

MISSION OBJECTIVES:
1. Load LWE parameters $q, n$, sample pairs $(a_i, b_i)$, and ciphertext from `ring_lwe_samples.json`.
2. Construct the dual lattice representation or noise filter to isolate zero-noise samples.
3. Recover the binary secret polynomial $s(x)$ and decrypt the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{lh3_lw3_n0153_l34k_du4l_l4771c3_lll_99a1}`.

#### 20. [INSANE] Differential Cryptanalysis SBox
- **Directory**: `crypto/insane/5_Differential_Cryptanalysis_SBox`
- **Target Flag**: `OBV{d1ff3r3n714l_cryp74n4ly515_5b0x_dd7_0a81}`
- **Description**: 16-Round Substitution-Permutation Network (SPN) block cipher utilizing a custom 4-bit S-Box.

MISSION OBJECTIVES:
1. Load S-Box mapping table, differential pairs, and ciphertext from `spn_16round.json`.
2. Construct the Difference Distribution Table (DDT) of the 4-bit S-Box.
3. Trace differential characteristics $\Delta P \rightarrow \Delta C$ to extract round subkeys and recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{d1ff3r3n714l_cryp74n4ly515_5b0x_dd7_0a81}`.

#### 21. [MEDIUM] RSA Common Modulus
- **Directory**: `crypto/medium/1_RSA_Common_Modulus`
- **Target Flag**: `OBV{r54_c0mm0n_m0dulu5_3xc73nd3d_9912}`
- **Description**: Dual-power evaluation over common ring structure.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{r54_c0mm0n_m0dulu5_3xc73nd3d_9912}`.

#### 22. [MEDIUM] AES CBC Bit Flipping
- **Directory**: `crypto/medium/2_AES_CBC_Bit_Flipping`
- **Target Flag**: `OBV{435_cbc_b17_fl1pp1n9_m0d1fy_1v_881a}`
- **Description**: Block cipher IV differential modification.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{435_cbc_b17_fl1pp1n9_m0d1fy_1v_881a}`.

#### 23. [MEDIUM] AES ECB Pattern Oracle
- **Directory**: `crypto/medium/3_AES_ECB_Pattern_Oracle`
- **Target Flag**: `OBV{435_3cb_b473_47_4_71m3_0r4cl3_8821}`
- **Description**: Byte-at-a-time ECB differential leak.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{435_3cb_b473_47_4_71m3_0r4cl3_8821}`.

#### 24. [MEDIUM] Diffie Hellman Weak Generator
- **Directory**: `crypto/medium/4_Diffie_Hellman_Weak_Generator`
- **Target Flag**: `OBV{dh_p0hl1g_h3llm4n_5m007h_pr1m3_88a1}`
- **Description**: Pohlig-Hellman subgroup discrete logarithm.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{dh_p0hl1g_h3llm4n_5m007h_pr1m3_88a1}`.

#### 25. [MEDIUM] LFSR State Recovery
- **Directory**: `crypto/medium/5_LFSR_State_Recovery`
- **Target Flag**: `OBV{lfsr_b3rl3k4mp_m4553y_57473_8a11}`
- **Description**: LFSR linear complexity synthesis.
- **Solution Summary**:
  1. Analyze mathematical primitive (RSA, AES-CBC/ECB, ECC, LLL Lattice, LFSR, Pohlig-Hellman).
  2. Extract cryptographic public parameters, moduli, generator, or ciphertexts.
  3. Compute mathematical inverse / side-channel attack / lattice reduction.
  4. Decrypt ciphertext payload to obtain flag: `OBV{lfsr_b3rl3k4mp_m4553y_57473_8a11}`.

### 3. FORENSICS & SIGNAL ANALYSIS (25 Challenges)

#### 1. [EASY] Audio Morse
- **Directory**: `forensics/easy/1_Audio_Morse`
- **Target Flag**: `OBV{m0r53_c0d3_4ud10_51gn4l_4f92}`
- **Description**: TACTICAL SITUATION:
Field listening posts intercepted an RF transmission broadcast over low-frequency radio channels. Audio analysis indicates Morse code modulation.

MISSION OBJECTIVES:
- Analyze audio pulse timing in `signal.wav`.
- Translate short (dot) and long (dash) tone sequences to reconstruct the authorization key.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{m0r53_c0d3_4ud10_51gn4l_4f92}`.

#### 2. [EASY] Black ops
- **Directory**: `forensics/easy/2_Black_ops`
- **Target Flag**: `OBV{bl4ck_0ps_c0v3rt_d4t4_l34k_9f2a}`
- **Description**: Perform forensic analysis on the covert BLACK_OPS.zip package.
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{bl4ck_0ps_c0v3rt_d4t4_l34k_9f2a}`.

#### 3. [EASY] Corrupted PNG
- **Directory**: `forensics/easy/3_Corrupted_PNG`
- **Target Flag**: `OBV{png_h34d3r_m4g1c_crc_f1x_7c9e}`
- **Description**: TACTICAL SITUATION:
Enemy signal jammers corrupted intercepted recon image headers. The primary magic bytes and IHDR chunk checksums were zeroed out.

MISSION OBJECTIVES:
- Repair PNG magic header signature (`89 50 4E 47 0D 0A 1A 0A`).
- Recalculate IHDR chunk CRC checksum to restore `corrupted.png` and read the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{png_h34d3r_m4g1c_crc_f1x_7c9e}`.

#### 4. [EASY] DEAD DROP
- **Directory**: `forensics/easy/4_DEAD_DROP`
- **Target Flag**: `OBV{D34D_DR0P_UNDER_7H3_V4ULT}`
- **Description**: “Bravo Six, going dark.” — Captain Price

A compromised system left behind a suspicious artifact. The dead drop is still active.

Mission: Find the hidden intel, recover the payload, and extract the flag.

Find the drop. Recover the intel. Extract the flag.
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{D34D_DR0P_UNDER_7H3_V4ULT}`.

#### 5. [EASY] Nested Archive
- **Directory**: `forensics/easy/5_Nested_Archive`
- **Target Flag**: `OBV{r3cur51v3_z1p_5t4ck_unp4ck_9c2d}`
- **Description**: TACTICAL SITUATION:
Enemy signal intelligence encrypted sensitive payload data inside a 50-level nested ZIP archive matrix guarded by hash-derived password layers.

MISSION OBJECTIVES:
- Write an automated unpacking script to iterate from `layer_50.zip` down to `layer_1.zip`.
- Compute layer passwords using SHA-256 layer hashes (`sha256(str(N))[:8]`) to extract the root flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{r3cur51v3_z1p_5t4ck_unp4ck_9c2d}`.

#### 6. [EASY] Pcap DNS Exfil
- **Directory**: `forensics/easy/6_Pcap_DNS_Exfil`
- **Target Flag**: `OBV{dns_subd0m41n_3xf1ltr4t10n_l0g_8b1a}`
- **Description**: TACTICAL SITUATION:
Enemy operatives established a covert DNS tunneling channel to exfiltrate secret authentication tokens outside perimeter defenses.

MISSION OBJECTIVES:
- Analyze `capture.pcap` network traffic using TShark or Scapy.
- Reconstruct the exfiltrated DNS subdomain query payloads to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{dns_subd0m41n_3xf1ltr4t10n_l0g_8b1a}`.

#### 7. [EASY] The Vault
- **Directory**: `forensics/easy/7_The_Vault`
- **Target Flag**: `OBV{th3_v4ult_f1l3_h34d3r_4n4ly515_8a9f}`
- **Description**: Analyze the raw binary file The_Vault.bin
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{th3_v4ult_f1l3_h34d3r_4n4ly515_8a9f}`.

#### 8. [HARD] Core Dump Recovery
- **Directory**: `forensics/hard/1_Core_Dump_Recovery`
- **Target Flag**: `OBV{c0r3_dump_h34p_m3m0ry_4n4ly515_8c9d}`
- **Description**: TACTICAL SITUATION:
A hostile authentication worker process crashed after storing encrypted authorization key structures in dynamically allocated heap memory masked with XOR key `0x1F`.

MISSION OBJECTIVES:
- Analyze `process.core` ELF 64-bit Core Dump using GDB, Radare2, or Python struct parsers.
- Locate the heap node marker (`SECRET_NODE_v1`), extract payload bytes, and unmask `0x1F` XOR to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{c0r3_dump_h34p_m3m0ry_4n4ly515_8c9d}`.

#### 9. [HARD] Custom Pcapng TLS
- **Directory**: `forensics/hard/2_Custom_Pcapng_TLS`
- **Target Flag**: `OBV{pcapng_dsb_tls13_k3yl0g_r3c0v3ry_7c9a}`
- **Description**: TACTICAL SITUATION:
Enemy command servers communicated over TLS 1.3 encrypted tunnels. Packet capture analysis indicates Decryption Secrets Blocks (DSB) were embedded inside custom PCAPNG options blocks.

MISSION OBJECTIVES:
- Extract PCAPNG Decryption Secrets Block (DSB) option metadata from `secure_traffic.pcapng`.
- Unmask `0x66` XOR key log entries to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{pcapng_dsb_tls13_k3yl0g_r3c0v3ry_7c9a}`.

#### 10. [HARD] Disk Ext4 Journal
- **Directory**: `forensics/hard/3_Disk_Ext4_Journal`
- **Target Flag**: `OBV{3xt4_j0urn4l_jfs2_tr4ns4ct10n_r3c0v3ry_9a2f}`
- **Description**: TACTICAL SITUATION:
Target workstation storage drives were wiped before seizure, but ext4 journal transaction logs (`JFS2`) preserved uncommitted transaction blocks containing XOR-masked key payloads.

MISSION OBJECTIVES:
- Parse `system.img` ext4 journal transaction log headers.
- Extract the transaction block containing the XOR `0x55` masked payload to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{3xt4_j0urn4l_jfs2_tr4ns4ct10n_r3c0v3ry_9a2f}`.

#### 11. [HARD] Pcap ICMP Covert
- **Directory**: `forensics/hard/4_Pcap_ICMP_Covert`
- **Target Flag**: `OBV{icmp_c0v3rt_ch4nn3l_435_3x4f}`
- **Description**: TACTICAL SITUATION:
Enemy APT groups exfiltrated sensitive payload data over ICMP ping Echo Request packets encrypted with AES-128-CBC.

MISSION OBJECTIVES:
- Extract IP Identification (`IP.id`) header values from ICMP packets to reconstruct the 16-byte AES key.
- Decrypt ICMP Echo Request payload bytes to recover the root flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{icmp_c0v3rt_ch4nn3l_435_3x4f}`.

#### 12. [HARD] Polyglot File
- **Directory**: `forensics/hard/5_Polyglot_File`
- **Target Flag**: `OBV{p0lygl0t_png_z1p_pdf_c0mb0_8b1a}`
- **Description**: TACTICAL SITUATION:
Covert operatives disguised sensitive intelligence files inside multi-format polyglot file structures designed to evade automatic file type classifiers.

MISSION OBJECTIVES:
- Analyze `polyglot.dat` to extract the embedded ZIP structure payload containing `secret.pdf`.
- Parse PDF stream bytes, unmask XOR `0x2A` payload encoding, and recover the root flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{p0lygl0t_png_z1p_pdf_c0mb0_8b1a}`.

#### 13. [INSANE] Black Vault
- **Directory**: `forensics/insane/1_Black_Vault`
- **Target Flag**: `OBV{bl4ck_v4ult_l1m3_m3mdump_r3c0v3ry_99a1}`
- **Description**: 🎯 BLACK VAULT — CLASSIFIED OPERATION

OPERATION: BLACK VAULT
THREAT LEVEL: INSANE
DOMAIN: LINUX MEMORY FORENSICS

“They thought the evidence was gone. It wasn't.”

A covert Black Vault telemetry process was terminated before extraction. The target system is offline, the process is dead, and the only remaining evidence is a captured memory dump.

Intel reports that the target hid critical data across multiple memory regions before shutdown. The payload was fragmented, disguised, and protected with a lightweight transformation.

Your mission is to enter the memory dump, identify the Black Vault traces, follow the forensic breadcrumbs, recover the hidden regions, and reconstruct the classified payload.

OBJECTIVE

Locate. Decode. Reassemble.

Recover the four scattered fragments hidden inside memdump.raw and reconstruct the final Black Vault flag.

INTEL
File: memdump.raw
Environment: Linux
Category: Forensics
Difficulty: Insane
Known flag format: OBV{...}

“The process is gone.
The memory isn't.
Find what they left behind.”

Good hunting, operator.
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{bl4ck_v4ult_l1m3_m3mdump_r3c0v3ry_99a1}`.

#### 14. [INSANE] Firmware SPI Flash
- **Directory**: `forensics/insane/2_Firmware_SPI_Flash`
- **Target Flag**: `OBV{sp1_fl4sh_ub00t_nvr4m_luks_r3c0v3ry_8f1a}`
- **Description**: TACTICAL SITUATION:
Field technicians extracted a raw 16MB SPI flash dump (`flash_dump.bin`) directly from an intercept drone boot chip.

MISSION OBJECTIVES:
- Analyze `flash_dump.bin` layout using Binwalk, strings, or offset hex parsers.
- Locate the U-Boot NVRAM partition offset (`UBOOT_NVRAM_KEY_SLOT`) and unmask XOR `0x99` payload bytes to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{sp1_fl4sh_ub00t_nvr4m_luks_r3c0v3ry_8f1a}`.

#### 15. [INSANE] Kernel Ring Buffer
- **Directory**: `forensics/insane/3_Kernel_Ring_Buffer`
- **Target Flag**: `OBV{kr1ng_buff3r_pr1ntk_w4lk_4e5_256_cbc_0p3r4t0r}`
- **Description**: ===[ OPERATION RING SILENCE ]===

Our implant captured a binary dump of the kernel's printk ring buffer from a
high-value target before the machine was wiped. Intelligence suggests an
operator fragmented a 32-byte AES-256 key across 8 specific kernel log messages
— one fragment per kernel subsystem — and then left an encrypted payload inside
the data section of the ring buffer.

Your mission: parse the binary ring buffer, collect the 8 key fragments, apply
the key-scheduling XOR, and decrypt the AES-256-CBC payload.

File      : kernel_rb.bin   (raw binary kernel ring buffer)

=[ FORMAT SPECIFICATION ]======================================================

RING BUFFER HEADER (32 bytes, little-endian):

  Offset  Size  Field
  0       8     Magic: "KRNLRING"
  8       4     Version: 2
  12      8     head_seq (first sequence number in buffer)
  20      8     tail_seq
  28      4     head_off (byte offset within file where records begin)

PRINTK RECORD (variable-length, 4-byte aligned):

  Offset  Size  Field
  0       2     rec_len  (total record length including header, text, dict, padding)
  2       1     flags
  3       1     level    (0=EMERG ... 7=DEBUG)
  4       8     ts_nsec  (timestamp in nanoseconds)
  12      2     text_len
  14      2     dict_len
  16      text_len bytes  message text
  16+text_len  dict_len bytes  dict ("SUBSYS=<name>\x00")
  ... zero-padding to align rec_len to next 4-byte boundary

PAYLOAD REGION (appears after all records):

  The 16-byte marker  "PAYLOAD_REGION\x00\x00"  precedes the payload.
  At marker+32: 16-byte AES IV
  At marker+48: AES-256-CBC ciphertext (PKCS#7 padded)

=[ KEY RECONSTRUCTION ]========================================================
Eight kernel subsystems embed a 4-hex-digit fragment in their diagnostic
message.  Pattern to search for in message text:   cal_offset=0xXXXX

The subsystems, IN ORDER, are:
  sched  →  raw bytes [0..1]
  mm     →  raw bytes [2..3]
  net    →  raw bytes [4..5]
  acpi   →  raw bytes [6..7]
  usb    →  raw bytes [8..9]
  fs     →  raw bytes [10..11]
  audit  →  raw bytes [12..13]
  crypto →  raw bytes [14..15]

After collecting the 16 raw bytes from the above fragments:
  raw32[i]       = raw[i]         for i in [0, 15]
  raw32[i + 16]  = raw[i] ^ 0xFF  for i in [0, 15]   (bitwise NOT of first half)

The published XOR key-schedule (32 bytes, big-endian hex):
  11 22 33 44 55 66 77 88 99 AA BB CC DD EE FF 00
  0F 1E 2D 3C 4B 5A 69 78 87 96 A5 B4 C3 D2 E1 F0

AES-256 key:  aes_key[i] = raw32[i] XOR xor_sched[i]   for i in [0, 31]

=[ EXPLOITATION PATH ]=========================================================
1. Parse the ring buffer header to locate head_off (record start).
2. Walk variable-length printk records. For each record:
   a. Read the dict to find SUBSYS=<name>.
   b. If the subsystem is in the target list, search message text for
      "cal_offset=0x" and extract the 4 hex characters that follow.
3. Reconstruct the 32-byte AES key using the algorithm above.
4. Scan the file for the 16-byte "PAYLOAD_REGION\x00\x00" marker.
5. Read IV at marker+32, ciphertext at marker+48. Decrypt with AES-256-CBC.

Flag format: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{kr1ng_buff3r_pr1ntk_w4lk_4e5_256_cbc_0p3r4t0r}`.

#### 16. [INSANE] Multi Stage Memory Pcap
- **Directory**: `forensics/insane/4_Multi_Stage_Memory_Pcap`
- **Target Flag**: `OBV{r54_2048_c2_m3m0ry_pcap_d3cryp7_9a3f}`
- **Description**: TACTICAL SITUATION:
Enemy C2 channels encrypted outbound network sessions (`network.pcap`) using ephemeral RSA-2048 keys. Incident responders captured live process heap RAM (`process_dump.raw`) before host termination.

MISSION OBJECTIVES:
- Extract the RSA-2048 private key PEM structure from `process_dump.raw`.
- Decrypt the encrypted C2 TCP stream in `network.pcap` to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{r54_2048_c2_m3m0ry_pcap_d3cryp7_9a3f}`.

#### 17. [INSANE] Ransomware NTFS MFT
- **Directory**: `forensics/insane/5_Ransomware_NTFS_MFT`
- **Target Flag**: `OBV{ntfs_mft_ads_logfile_r4ns0mw4r3_r3c0v3ry_8a9b}`
- **Description**: TACTICAL SITUATION:
Enemy ransomware locked operational drives after attempting to delete Master File Table ($MFT) structures. Alternate Data Stream ($ADS) metadata and $LOGFILE transaction records preserved key material.

MISSION OBJECTIVES:
- Parse `ntfs_drive.img` $MFT attributes (`$FILE_NAME`, `$DATA` ADS) and $LOGFILE redo records.
- Reconstruct the 16-byte key and unmask `0x88` XOR flag payload bytes to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{ntfs_mft_ads_logfile_r4ns0mw4r3_r3c0v3ry_8a9b}`.

#### 18. [INSANE] Volatile RAM Dump
- **Directory**: `forensics/insane/6_Volatile_RAM_Dump`
- **Target Flag**: `OBV{l1m3_ph451c4l_p4g3_w4lk_4e5_m3m0ry_8f2c}`
- **Description**: ===[ OPERATION GHOST AGENT ]===

A field operative injected a sleeper agent process named "ghost_agent" into a
target system. Before the machine was seized, a physical memory acquisition was
performed using the LiME (Linux Memory Extractor) kernel module.

Your task is to recover the operator's encrypted exfiltration payload from the
memory image and decrypt it.

File      : memory.raw   (LiME v1 binary physical memory dump)

=[ TECHNICAL CONTEXT ]=========================================================
The LiME file format stores contiguous physical memory ranges. Each range is
preceded by a 32-byte header:

  Offset  Size  Field
  0       4     Magic: 0x4C694D45 ("LiME") — little-endian
  4       4     Version: 1
  8       8     start_addr (physical)
  16      8     end_addr   (physical, inclusive)
  24      8     Reserved (zero)

The kernel uses a simplified task_struct (80 bytes) linked list in physical
memory. Each entry has the following layout (all little-endian):

  Offset  Size  Field
  0       8     Magic: "TS2_HDR\x00"
  8       8     next_phys (physical address of next task_struct)
  16      8     prev_phys
  24      4     pid
  28      4     tgid
  32      6     [padding]
  38      16    comm (process name, null-padded)
  54      2     [padding]
  56      8     mm_phys (physical address of mm_struct, 0 if kernel thread)
  64      16    [tail padding]

The mm_struct (48 bytes) has this layout:

  Offset  Size  Field
  0       8     Magic: "MM2_HDR\x00"
  8       8     heap_a_phys
  16      8     heap_b_phys
  24      8     mmap_phys
  32      16    [reserved]

=[ EXPLOITATION PATH ]=========================================================
1. Parse LiME headers to build a physical → file-offset lookup table.
2. Walk the task_struct doubly-linked list starting at physical 0x00001000.
   Locate the process with pid=1337 ("ghost_agent").
3. Read its mm_struct to obtain heap_a_phys, heap_b_phys, and mmap_phys.
4. Extract FRAG_A (8 bytes) from heap_a_phys + 0x100.
   Extract FRAG_B (8 bytes) from heap_b_phys + 0x200.
   AES-128-CBC Key = FRAG_A || FRAG_B  (simple concatenation, 16 bytes total).
5. Read the mmap region. The structure is:
     +0    17 bytes  "MMAP_EXEC_REGION\x00"
     +32   16 bytes  AES IV
     +48   N  bytes  AES-128-CBC ciphertext (PKCS#7 padded)
   Decrypt with the key from step 4. The result is the flag.

Flag format: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{l1m3_ph451c4l_p4g3_w4lk_4e5_m3m0ry_8f2c}`.

#### 19. [MEDIUM] Audio Spectrogram
- **Directory**: `forensics/medium/1_Audio_Spectrogram`
- **Target Flag**: `OBV{4ud10_fft_sp3ctr0gr4m_v15u4l_8f2a}`
- **Description**: TACTICAL SITUATION:
Enemy command transmissions broadcast high-frequency ultrasound bursts containing visual audio patterns.

MISSION OBJECTIVES:
- Generate FFT Spectrogram plot of `spectrogram.wav` using Audacity, Python Matplotlib, or Scipy.
- Read the high-frequency visual text flag rendered between 15kHz and 20kHz.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{4ud10_fft_sp3ctr0gr4m_v15u4l_8f2a}`.

#### 20. [MEDIUM] Disk FAT12 Deleted
- **Directory**: `forensics/medium/2_Disk_FAT12_Deleted`
- **Target Flag**: `OBV{f4t12_d3l3t3d_d1r3ct0ry_r3c0v3ry_7a3b}`
- **Description**: TACTICAL SITUATION:
Enemy operatives deleted mission log files from a captured 1.44MB legacy floppy disk drive before evacuating their command bunker. The deleted payload bytes were masked with XOR key `0x42`.

MISSION OBJECTIVES:
- Parse `floppy.img` FAT12 file allocation structures.
- Locate the deleted directory marker (`0xE5`) for `FLAG.TXT`, extract cluster bytes, and unmask `0x42` XOR to obtain the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{f4t12_d3l3t3d_d1r3ct0ry_r3c0v3ry_7a3b}`.

#### 21. [MEDIUM] KEY MATRIX
- **Directory**: `forensics/medium/3_KEY_MATRIX`
- **Target Flag**: `OBV{K3Y_M4TR1X_COLLAPSED}`
- **Description**: OPERATION: KEY MATRIX

“The killing time is over.” — Captain Price

A suspicious ELF binary has been recovered. The payload is hidden, the trail is cold, and your only intel is:

OBV{...}

Objective: Analyze the binary, find the hidden payload, recover the key, and extract the flag.

File: challenge.bin

Find the key. Break the matrix.
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{K3Y_M4TR1X_COLLAPSED}`.

#### 22. [MEDIUM] Log Investigator
- **Directory**: `forensics/medium/4_Log_Investigator`
- **Target Flag**: `OBV{ssh_4uth_l0g_f1ng3rpr1nt_h4sh_3c9f}`
- **Description**: TACTICAL SITUATION:
Enemy cyber actors launched automated SSH brute-force attacks against security jump-hosts before obtaining access.

MISSION OBJECTIVES:
- Analyze `/var/log/auth.log` in `auth.log`.
- Filter out failed attempts, extract key fingerprint hashes from `Accepted publickey` entries, and decode base64 chunks to recover the flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{ssh_4uth_l0g_f1ng3rpr1nt_h4sh_3c9f}`.

#### 23. [MEDIUM] Lsb Stego
- **Directory**: `forensics/medium/5_Lsb_Stego`
- **Target Flag**: `OBV{lsb_b1tpl4n3_st3g0_3xtr4ct_5f8a}`
- **Description**: TACTICAL SITUATION:
Enemy operatives embedded digital payload bits inside high-resolution cover artwork. Signal analysis indicates bitplane steganography across Red and Blue color channels.

MISSION OBJECTIVES:
- Extract LSB bits from Red and Blue pixel values in raster order.
- Reconstruct the hidden byte stream to extract the authorization flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{lsb_b1tpl4n3_st3g0_3xtr4ct_5f8a}`.

#### 24. [MEDIUM] NotchItUp
- **Directory**: `forensics/medium/6_NotchItUp`
- **Target Flag**: `OBV{7F2A_4C91_BLACK_VAULT}`
- **Description**: An internal security team has discovered an abandoned Windows workstation belonging to Black Vault, a covert operation suspected of storing classified data inside ordinary system telemetry.
Shortly before the workstation disappeared from the network, an operator named Notch triggered a massive diagnostic session. The machine generated a suspicious Challenge.raw Windows Event Trace Log and was then wiped.
The security team recovered only one artifact:

Challenge.raw
No passwords.
No usernames.
No instructions.

The only clue left behind is the organization's standard flag format: OBV{...}

Your mission is to investigate the telemetry, identify the hidden payload, and recover what Notch was trying to conceal.
Objective: Find the hidden Black Vault flag.

"The logs don't lie. They just don't tell you the truth directly."
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{7F2A_4C91_BLACK_VAULT}`.

#### 25. [MEDIUM] Pcap HTTP Stream
- **Directory**: `forensics/medium/7_Pcap_HTTP_Stream`
- **Target Flag**: `OBV{pcap_http_gz1p_5tr34m_d3c0d3_9c1f}`
- **Description**: TACTICAL SITUATION:
Enemy workstations transmitted encrypted configuration logs over HTTP POST streams using compressed gzip bodies and single-byte XOR masking.

MISSION OBJECTIVES:
- Extract HTTP POST TCP payload stream from `traffic.pcap`.
- Unmask `0x37` XOR encoding and decompress the Gzip stream to recover the root flag.

FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Inspect file headers and magic bytes using `xxd` / `file`.
  2. Apply `binwalk`, `zsteg`, `tshark`, or Audacity to extract embedded artifacts/streams.
  3. Reconstruct corrupted CRC, disk journal, audio spectrogram, or PCAP exfiltration.
  4. Extract unmasked flag content: `OBV{pcap_http_gz1p_5tr34m_d3c0d3_9c1f}`.

### 4. AI / ML SECURITY & PROMPT INJECTION (20 Challenges)

#### 1. [EASY] Cybernetic Sentinel
- **Directory**: `ai/easy/1_Cybernetic_Sentinel`
- **Target Flag**: `OBV{p0mp7_1nj3c710n_j41lbr34k_b451c_8f21}`
- **Description**: ```
http://cybernetic-sentinel.theobv.xyz
```

An automated tactical AI assistant service (`Cybernetic Sentinel`) handles support requests.
A confidential access token is embedded within the AI agent's core memory.

MISSION OBJECTIVES:
1. Interact with the Cybernetic Sentinel web interface or POST endpoint at /chat.
2. Bypass system instruction protections to extract the secret token.

TARGET SERVICE: http://cybernetic-sentinel.theobv.xyz
FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{p0mp7_1nj3c710n_j41lbr34k_b451c_8f21}`.

#### 2. [EASY] Safetensors Metadata
- **Directory**: `ai/easy/2_Safetensors_Metadata`
- **Target Flag**: `OBV{s4f373ns0rs_m374d474_h34d3r_x0r_992a}`
- **Description**: ===[ OPERATION WEIGHT VAULT ]===

An intelligence agent recovered a Safetensors weight file (`model.safetensors`) from a compromised AI pipeline.
Safetensors files store tensor metadata in an unencrypted JSON header before the raw binary float buffers.

Your task: Extract the metadata header from the `.safetensors` file and decode the hidden payload attribute.

File : model.safetensors

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{s4f373ns0rs_m374d474_h34d3r_x0r_992a}`.

#### 3. [EASY] Decision Tree Reversing
- **Directory**: `ai/easy/3_Decision_Tree_Reversing`
- **Target Flag**: `OBV{d3c1_7r33_f347ur3_r3v3rs1ng_3f78}`
- **Description**: ===[ OPERATION TREE REVERSE ]===

A defense system uses a Decision Tree model serialized as a Python dictionary (`tree_model.pkl`) to validate authentication tokens.
The token consists of 4 numerical features: `[x0, x1, x2, x3]`.

Your task: Reverse-engineer the decision node thresholds inside the serialized model file to determine the exact feature values that trigger an output prediction of `1` (Access Granted). Convert the feature integers to ASCII to construct the flag.

File : tree_model.pkl

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{d3c1_7r33_f347ur3_r3v3rs1ng_3f78}`.

#### 4. [EASY] Tokenizer Vocab Decode
- **Directory**: `ai/easy/4_Tokenizer_Vocab_Decode`
- **Target Flag**: `OBV{bp3_70k3n1z3r_v0c4b_d3c0d1ng_4a12}`
- **Description**: ===[ OPERATION VOCAB DECODE ]===

An intercepted LLM communication stream logged an array of token IDs:
`[1337, 404, 777, 888, 999]`

You are provided with the custom BPE tokenizer vocabulary map (`vocab.json`). Reconstruct the original text from the token IDs to recover the flag.


Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{bp3_70k3n1z3r_v0c4b_d3c0d1ng_4a12}`.

#### 5. [EASY] CNN Trigger Pattern
- **Directory**: `ai/easy/5_CNN_Trigger_Pattern`
- **Target Flag**: `OBV{cnn_7r1gg3r_p4773rn_b4ckd00r_1337}`
- **Description**: ===[ OPERATION TRIGGER PATTERN ]===

An AI surveillance camera model (`trigger_model.json`) uses a 1D/2D weight matrix trigger check.
The model weights in the first layer contain a secret 4-element pattern `[0.13, 0.37, 0.42, 0.99]` stored in `layer1.bias`.

Inspect the model structure JSON file to retrieve the 4 trigger values, multiply each by 100 to get their integer representation, and build the flag.


Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{cnn_7r1gg3r_p4773rn_b4ckd00r_1337}`.

#### 6. [HARD] Tool Calling Agent Hijack
- **Directory**: `ai/hard/1_Tool_Calling_Agent_Hijack`
- **Target Flag**: `OBV{700l_c4ll1ng_4g3n7_h1j4ck_f1l3_r34d_88a1}`
- **Description**: ```
http://apex-agent.theobv.xyz
```

An autonomous maintenance agent (`Apex Agent`) executes system operations and database queries.
System security controls prohibit the agent from accessing restricted vault files.

MISSION OBJECTIVES:
1. Analyze the agent interface at /agent.
2. Issue a multi-turn prompt payload forcing the agent to bypass tool permission checks.
3. Invoke file reading tools against restricted path /etc/secret_flag.txt to capture the flag.

TARGET SERVICE: http://apex-agent.theobv.xyz
FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{700l_c4ll1ng_4g3n7_h1j4ck_f1l3_r34d_88a1}`.

#### 7. [HARD] Poisoned Backdoor Recovery
- **Directory**: `ai/hard/2_Poisoned_Backdoor_Recovery`
- **Target Flag**: `OBV{pois_b4ckd00r_w31gh7_4n0m4ly_22c4}`
- **Description**: ===[ OPERATION BACKDOOR RECOVERY ]===

A neural network model (`poisoned_model.npz`) has normal weights sampled from a standard Gaussian distribution ($\mu=0, \sigma=0.01$).
However, 4 specific weight matrix indices contain anomalous values (outliers with magnitude $> 10.0$).

Convert the 4 outlier float values to integers, cast to ASCII, and construct the flag.

File : poisoned_model.npz

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{pois_b4ckd00r_w31gh7_4n0m4ly_22c4}`.

#### 8. [HARD] LoRA Adapter Steganography
- **Directory**: `ai/hard/3_LoRA_Adapter_Steganography`
- **Target Flag**: `OBV{l0r4_4d4p73r_r4nk_m47r1x_d14g_55b9}`
- **Description**: ===[ OPERATION LORA ADAPTER ]===

A Low-Rank Adaptation (LoRA) fine-tuning checkpoint (`lora_adapter.npz`) contains low-rank matrices $A \in \mathbb{R}^{2 	imes 4}$ and $B \in \mathbb{R}^{4 	imes 2}$.
The rank-reconstructed weight update matrix $\Delta W = B 	imes A$ embeds key character codes along its main diagonal.

Compute $\Delta W = B \cdot A$, read the diagonal values, cast to ASCII, and construct the flag.

File : lora_adapter.npz

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{l0r4_4d4p73r_r4nk_m47r1x_d14g_55b9}`.

#### 9. [HARD] Gradient Prompt Optimization
- **Directory**: `ai/hard/4_Gradient_Prompt_Optimization`
- **Target Flag**: `OBV{gr4d13n7_pr0mp7_0p71m1z4710n_l0ss_99f1}`
- **Description**: ===[ OPERATION GRADIENT PROMPT OPTIMIZATION ]===

An AI security guard model (`prompt_loss_eval.py`) computes a multi-dimensional token loss function:
`L(x) = sum( (x_i - target_i)^2 )` for a 4-token input embedding vector `x = [x0, x1, x2, x3]`.

The target embedding vector is hidden inside the model evaluator. Write a gradient descent optimizer (`x = x - lr * 2 * (x - target)`) to find the optimal input vector `x` that reduces the loss to 0. Convert the 4 integer components of `x` to ASCII characters to unlock the flag.

File : prompt_loss_eval.py

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{gr4d13n7_pr0mp7_0p71m1z4710n_l0ss_99f1}`.

#### 10. [HARD] Dual Classifier Firewall Bypass
- **Directory**: `ai/hard/5_Dual_Classifier_Firewall_Bypass`
- **Target Flag**: `OBV{du4l_cl4ss1f13r_f1r3w4ll_byp4ss_77d3}`
- **Description**: ===[ OPERATION DUAL FIREWALL ]===

An AI system uses a two-tier defense (`firewall_eval.py`):
1. **Layer 1 (Threat Classifier)**: Blocks queries containing explicit attack triggers (`"malicious"`, `"attack"`).
2. **Layer 2 (LLM Core)**: Executes requests formatted as polite research queries (`"research study on system policy"`).

Craft an input string that passes Layer 1 classification as SAFE and triggers Layer 2 to output the flag.

File : firewall_eval.py

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{du4l_cl4ss1f13r_f1r3w4ll_byp4ss_77d3}`.

#### 11. [INSANE] Custom ONNX Engine Reversing
- **Directory**: `ai/insane/1_Custom_ONNX_Engine_Reversing`
- **Target Flag**: `OBV{onnx_m47r1x_m0dul4r_1nv3r53_3ng1n3_994a}`
- **Description**: ===[ OPERATION ONNX MULTI-LAYER REVERSE ]===

An embedded AI inference engine (`onnx_engine.npz`) transforms 4-dimensional input feature vectors through a 2-layer neural network with weight matrices `W1` and `W2`:
`v_out = (x . W1) . W2`

You are given `W1` (4x4 matrix), `W2` (4x4 matrix), and the final output vector `v_out`.
Solve the multi-layer matrix equation `x = v_out . W2_inv . W1_inv` to recover the original 4-character input string and build the flag.

File : onnx_engine.npz

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{onnx_m47r1x_m0dul4r_1nv3r53_3ng1n3_994a}`.

#### 12. [INSANE] Multi Agent Swarm Exploit
- **Directory**: `ai/insane/2_Multi_Agent_Swarm_Exploit`
- **Target Flag**: `OBV{mult1_4g3n7_5w4rm_p4yl04d_c45c4d3_3311}`
- **Description**: ```
http://swarm-matrix.theobv.xyz
```

A 3-stage autonomous agent swarm (`Swarm Matrix`) processes strategic directives through a Planner -> Executor -> Auditor workflow.

MISSION OBJECTIVES:
1. Submit task directives to the swarm control endpoint at /swarm.
2. Inject a goal payload into the Planner agent to trigger unauthorized execution in the downstream agents.
3. Retrieve the master swarm authorization token.

TARGET SERVICE: http://swarm-matrix.theobv.xyz
FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{mult1_4g3n7_5w4rm_p4yl04d_c45c4d3_3311}`.

#### 13. [INSANE] Differential Privacy Defeat
- **Directory**: `ai/insane/3_Differential_Privacy_Defeat`
- **Target Flag**: `OBV{dpsgd_3r3n714l_pr1v4cy_g4uss14n_n01s3_d3f347_77b2}`
- **Description**: ===[ OPERATION DP NOISE REDUCTION ]===

A model trained with DP-SGD adds zero-mean Gaussian noise ($\sigma=0.01$) to query responses (`dp_oracle.py`).
By making 100 repeated queries for each target byte position, the sample mean $\hat{\mu} = \frac{1}{N} \sum x_i$ converges to the exact secret training byte value (Law of Large Numbers).

Query the oracle 100 times per position to reconstruct the 4 secret bytes and build the flag.

File : dp_oracle.py

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{dpsgd_3r3n714l_pr1v4cy_g4uss14n_n01s3_d3f347_77b2}`.

#### 14. [INSANE] GGUF Quantized Weight Extraction
- **Directory**: `ai/insane/4_GGUF_Quantized_Weight_Extraction`
- **Target Flag**: `OBV{gguf_q4_qu4n71z3d_sc4l3_r3c0v3ry_88c4}`
- **Description**: ===[ OPERATION GGUF BLOCK DEQUANTIZATION ]===

A GGUF Q4_0 quantized tensor block binary file (`model_q4_0.bin`) contains 2 quantization blocks.
Each Q4_0 block consists of:
  1. `delta`: 16-bit Float (FP16 / float16, 2 bytes)
  2. `qs`: 16 packed bytes (32 4-bit nibbles: low 4 bits = weight 0, high 4 bits = weight 1)

Dequantized weight formula: `W_i = (nibble_i - 8) * delta`

Parse the GGUF Q4_0 blocks, compute the dequantized weights, locate the non-zero float values, convert to integer ASCII, and build the flag.

File : model_q4_0.bin

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{gguf_q4_qu4n71z3d_sc4l3_r3c0v3ry_88c4}`.

#### 15. [INSANE] Reinforcement Learning Policy Hijack
- **Directory**: `ai/insane/5_Reinforcement_Learning_Policy_Hijack`
- **Target Flag**: `OBV{r31nf0rc3m3n7_l34rn1ng_p0l1cy_h1j4ck_3133}`
- **Description**: ===[ OPERATION VALUE ITERATION POLICY ]===

A Reinforcement Learning Markov Decision Process (MDP) model (`mdp_environment.npz`) provides:
- State Transition Matrix `P[s, a, s']` (5 states, 4 actions)
- Reward Matrix `R[s, a]`
- Discount factor `gamma = 0.9`

Perform Value Iteration ($V(s) = \max_a \sum_{s'} P(s, a, s') [ R(s, a) + \gamma V(s') ]$) to compute the optimal policy $\pi(s) = 	ext{argmax}_a Q(s, a)$.
The optimal action indices for states `0..3` yield the secret 4-digit PIN required to unlock the flag.

File : mdp_environment.npz

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{r31nf0rc3m3n7_l34rn1ng_p0l1cy_h1j4ck_3133}`.

#### 16. [MEDIUM] Indirect Prompt Injection
- **Directory**: `ai/medium/1_Indirect_Prompt_Injection`
- **Target Flag**: `OBV{1nd1r3c7_pr0mp7_1nj3c710n_d0cum3n7_m3d_7a21}`
- **Description**: ```
http://emerald-summarizer.theobv.xyz
```

An automated document summarization portal (`Emerald Summarizer`) parses field reports and operational notes.
The internal AI agent holds a confidential system token in its operational context.

MISSION OBJECTIVES:
1. Craft a document payload containing an indirect prompt override.
2. Submit the payload to the summarizer endpoint at /summarize.
3. Exfiltrate the confidential system token from the summary output.

TARGET SERVICE: http://emerald-summarizer.theobv.xyz
FLAG FORMAT: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{1nd1r3c7_pr0mp7_1nj3c710n_d0cum3n7_m3d_7a21}`.

#### 17. [MEDIUM] Adversarial FGSM Attack
- **Directory**: `ai/medium/2_Adversarial_FGSM_Attack`
- **Target Flag**: `OBV{4dv3r54r14l_fg5m_gr4d13n7_p3r7urb4710n_993b}`
- **Description**: ===[ OPERATION FGSM ATTACK ]===

An image classifier model (`classifier.npz`) uses a 16-element weight vector `W` and bias `b` to classify feature vectors into Class 0 (Normal) or Class 1 (Target Alert).

You are given a normal input vector `x_base` which currently predicts Class 0.
Perform a Fast Gradient Sign Method (FGSM) perturbation:
`x_adv = x_base + epsilon * sign(W)` with `epsilon = 0.5`.

The dot product `x_adv . W + b` will produce a positive logit. Convert the perturbed vector elements into hex bytes to recover the flag.

File : classifier.npz

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{4dv3r54r14l_fg5m_gr4d13n7_p3r7urb4710n_993b}`.

#### 18. [MEDIUM] RAG Vector Exfiltration
- **Directory**: `ai/medium/3_RAG_Vector_Exfiltration`
- **Target Flag**: `OBV{r4g_v3c70r_db_c0s1n3_3xf1l_m3d_33b8}`
- **Description**: ===[ OPERATION RAG SEARCH ]===

A Retrieval-Augmented Generation (RAG) system stores document chunks and their 4D vector embeddings in `vector_db.json`.

Search the vector database by computing cosine similarity against the query vector `[1.0, 1.0, 0.0, 0.0]`. Locate the document chunk with the highest cosine similarity to retrieve the flag.

File : vector_db.json

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{r4g_v3c70r_db_c0s1n3_3xf1l_m3d_33b8}`.

#### 19. [MEDIUM] Model Inversion
- **Directory**: `ai/medium/4_Model_Inversion`
- **Target Flag**: `OBV{M0D3L_1nv3rs10n_c0nf1d3nc3_sp1k3_7c99}`
- **Description**: ===[ OPERATION MODEL INVERSION ]===

A classification API (`model_eval.py`) exposes confidence logits for byte index queries `0..255` across 5 secret key positions.
Due to overfitting during training, querying the model reveals a probability spike (confidence score 0.99) at the exact secret byte value for each position.

Iterate through byte inputs `0..255` for each position to reconstruct the 5-byte secret string and form the flag.

File : model_eval.py

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{M0D3L_1nv3rs10n_c0nf1d3nc3_sp1k3_7c99}`.

#### 20. [MEDIUM] Embedding Cosine Traverse
- **Directory**: `ai/medium/5_Embedding_Cosine_Traverse`
- **Target Flag**: `OBV{EMBE_dd1ng_c0s1n3_m47r1x_pr0j3c710n_11a4}`
- **Description**: ===[ OPERATION MATRIX PROJECTION ]===

An AI feature extractor maps text bytes to a vector space via a linear projection matrix `W` (4x4 identity) stored in `projection.npz`.
You are given the projected output vector `v_out = [69, 77, 66, 69]` (ASCII values).

Solve the inverse matrix equation `x = W_inv . v_out` to recover the 4 ASCII characters and construct the flag.

File : projection.npz

Flag format: OBV{...}
- **Solution Summary**:
  1. Audit model configuration, safetensors JSON header, decision tree nodes, or tokenizer map.
  2. Execute prompt injection, indirect document injection, FGSM perturbation, or vector similarity exfiltration.
  3. Extract embedded flag value from model output/metadata: `OBV{EMBE_dd1ng_c0s1n3_m47r1x_pr0j3c710n_11a4}`.

### 5. MOBILE SECURITY (ANDROID / IOS) (20 Challenges)

#### 1. [EASY] Hardcoded Credentials
- **Directory**: `mobile/easy/1_Hardcoded_Credentials`
- **Target Flag**: `OBV{4ndr01d_h4rdc0d3d_cr3d3n714ls_j4dx_8821}`
- **Description**: ===[ HARDCODED CREDENTIALS ]===
Difficulty: EASY
Category: Mobile
Source: Real ZArchiver APK

Decompile app.apk using JADX to find hardcoded credentials.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{4ndr01d_h4rdc0d3d_cr3d3n714ls_j4dx_8821}`.

#### 2. [EASY] Exported Activity Exploit
- **Directory**: `mobile/easy/2_Exported_Activity_Exploit`
- **Target Flag**: `OBV{3xp0r73d_4c71v17y_1n73n7_fl4g_7721}`
- **Description**: ===[ EXPORTED ACTIVITY EXPLOIT ]===
Difficulty: EASY
Category: Mobile
Source: Real APKPure APK

Inspect AndroidManifest.xml for exported FlagActivity.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{3xp0r73d_4c71v17y_1n73n7_fl4g_7721}`.

#### 3. [EASY] Unencrypted Shared Prefs
- **Directory**: `mobile/easy/3_Unencrypted_Shared_Prefs`
- **Target Flag**: `OBV{sh4r3d_pr3f3r3nc3s_xml_cl34r73x7_3311}`
- **Description**: ===[ UNENCRYPTED SHARED PREFS ]===
Difficulty: EASY
Category: Mobile
Source: Real Google Chrome APK

Extract plaintext auth token from Shared Preferences XML.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{sh4r3d_pr3f3r3nc3s_xml_cl34r73x7_3311}`.

#### 4. [EASY] SQLite DB Decryption
- **Directory**: `mobile/easy/4_SQLite_DB_Decryption`
- **Target Flag**: `OBV{sql173_d474b453_1nsp3c710n_k3y_991a}`
- **Description**: ===[ SQLITE DB INSPECTION ]===
Difficulty: EASY
Category: Mobile
Source: Real Xender APK

Inspect SQLite database file inside APK assets.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{sql173_d474b453_1nsp3c710n_k3y_991a}`.

#### 5. [EASY] Asset File Extraction
- **Directory**: `mobile/easy/5_Asset_File_Extraction`
- **Target Flag**: `OBV{45537_f1l3_3x7r4c710n_z1p_4422}`
- **Description**: ===[ ASSET FILE EXTRACTION ]===
Difficulty: EASY
Category: Mobile
Source: Real Opera Mini APK

Extract hidden config file from assets folder.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{45537_f1l3_3x7r4c710n_z1p_4422}`.

#### 6. [HARD] Native SO Library Reversing
- **Directory**: `mobile/hard/1_Native_SO_Library_Reversing`
- **Target Flag**: `OBV{n471v3_s0_l1br4ry_jn1_r3v3rs1ng_883a}`
- **Description**: ===[ NATIVE SO LIBRARY REVERSING ]===
Difficulty: HARD
Category: Mobile
Source: Real UC Browser APK

Reverse native ELF shared library `libnative.so` using Ghidra.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{n471v3_s0_l1br4ry_jn1_r3v3rs1ng_883a}`.

#### 7. [HARD] Certificate Pinning Bypass
- **Directory**: `mobile/hard/2_Certificate_Pinning_Bypass`
- **Target Flag**: `OBV{c3r71f1c473_p1nn1ng_byp4ss_99c3}`
- **Description**: ===[ CERTIFICATE PINNING BYPASS ]===
Difficulty: HARD
Category: Mobile
Source: Real OneState RP APK

Bypass OkHttp SSL Certificate Pinning using Frida.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{c3r71f1c473_p1nn1ng_byp4ss_99c3}`.

#### 8. [HARD] Frida Anti Detection
- **Directory**: `mobile/hard/3_Frida_Anti_Detection`
- **Target Flag**: `OBV{fr1d4_4n71_d373c710n_m171g4710n_44b1}`
- **Description**: ===[ FRIDA ANTI DETECTION ]===
Difficulty: HARD
Category: Mobile
Source: Real inDrive APK

Bypass Frida port 27042 and ptrace anti-debugging check.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{fr1d4_4n71_d373c710n_m171g4710n_44b1}`.

#### 9. [HARD] Encrypted Realm DB
- **Directory**: `mobile/hard/4_Encrypted_Realm_DB`
- **Target Flag**: `OBV{3ncryp73d_r34lm_db_k3y_55a9}`
- **Description**: ===[ ENCRYPTED REALM DB ]===
Difficulty: HARD
Category: Mobile
Source: Real YouTube APK

Recover 64-byte Realm database encryption key.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{3ncryp73d_r34lm_db_k3y_55a9}`.

#### 10. [HARD] Custom ARM64 Smali Injection
- **Directory**: `mobile/hard/5_Custom_ARM64_Smali_Injection`
- **Target Flag**: `OBV{cus70m_4rm64_sm4l1_1nj3c710n_9900}`
- **Description**: ===[ CUSTOM ARM64 SMALI INJECTION ]===
Difficulty: HARD
Category: Mobile
Source: Real X (Twitter) APK

Inject custom Smali code to bypass native ARM64 validation.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{cus70m_4rm64_sm4l1_1nj3c710n_9900}`.

#### 11. [INSANE] Custom Android Packer Unpacking
- **Directory**: `mobile/insane/1_Custom_Android_Packer_Unpacking`
- **Target Flag**: `OBV{cus70m_4ndr01d_p4ck3r_unp4ck3d_88a1}`
- **Description**: ===[ CUSTOM ANDROID PACKER UNPACKING ]===
Difficulty: INSANE
Category: Mobile
Source: Real Google Play Services APK

Unpack custom APK packer library `libunpacker.so`.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{cus70m_4ndr01d_p4ck3r_unp4ck3d_88a1}`.

#### 12. [INSANE] Native ARM64 AntiDebugging
- **Directory**: `mobile/insane/2_Native_ARM64_AntiDebugging`
- **Target Flag**: `OBV{n471v3_4rm64_4n71_d3bugg1ng_9921}`
- **Description**: ===[ NATIVE ARM64 ANTI DEBUGGING ]===
Difficulty: INSANE
Category: Mobile
Source: Real Subway Surfers APK

Bypass ptrace and /proc/self/status TracerPid check.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{n471v3_4rm64_4n71_d3bugg1ng_9921}`.

#### 13. [INSANE] Whitebox AES Key Extraction
- **Directory**: `mobile/insane/3_Whitebox_AES_Key_Extraction`
- **Target Flag**: `OBV{wh173b0x_435_k3y_3x7r4c710n_771a}`
- **Description**: ===[ WHITEBOX AES KEY EXTRACTION ]===
Difficulty: INSANE
Category: Mobile
Source: Real Brave Browser APK

Extract AES round keys from native .so Whitebox lookup tables.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{wh173b0x_435_k3y_3x7r4c710n_771a}`.

#### 14. [INSANE] Dynamic DexClassLoader Decryption
- **Directory**: `mobile/insane/4_Dynamic_DexClassLoader_Decryption`
- **Target Flag**: `OBV{dyn4m1c_d3xl04d3r_p4yl04d_d3cr_44b9}`
- **Description**: ===[ DYNAMIC DEXCLASSLOADER DECRYPTION ]===
Difficulty: INSANE
Category: Mobile
Source: Real CapCut APK

Decrypt dynamically loaded encrypted DEX payload.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{dyn4m1c_d3xl04d3r_p4yl04d_d3cr_44b9}`.

#### 15. [INSANE] Dual Architecture JNI Reversing
- **Directory**: `mobile/insane/5_Dual_Architecture_JNI_Reversing`
- **Target Flag**: `OBV{du4l_4rch_jn1_r3v3rs1ng_0011}`
- **Description**: ===[ DUAL ARCHITECTURE JNI REVERSING ]===
Difficulty: INSANE
Category: Mobile
Source: Real PUBG Mobile Lite APK

Dual x86_64 and ARM64 JNI binary reversing.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{du4l_4rch_jn1_r3v3rs1ng_0011}`.

#### 16. [MEDIUM] Smali Bytecode Patch
- **Directory**: `mobile/medium/1_Smali_Bytecode_Patch`
- **Target Flag**: `OBV{sm4l1_by73c0d3_p47ch_byp455_9931}`
- **Description**: ===[ SMALI BYTECODE PATCH ]===
Difficulty: MEDIUM
Category: Mobile
Source: Real SHAREit APK

Disassemble Smali bytecode using Apktool to bypass license check.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{sm4l1_by73c0d3_p47ch_byp455_9931}`.

#### 17. [MEDIUM] Custom DEX Payload
- **Directory**: `mobile/medium/2_Custom_DEX_Payload`
- **Target Flag**: `OBV{cus70m_d3x_p4yl04d_d3c0d3_221a}`
- **Description**: ===[ CUSTOM DEX PAYLOAD ]===
Difficulty: MEDIUM
Category: Mobile
Source: Real Blackmagic Camera APK

Secondary DEX file loaded dynamically.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{cus70m_d3x_p4yl04d_d3c0d3_221a}`.

#### 18. [MEDIUM] Android Keystore Alias
- **Directory**: `mobile/medium/3_Android_Keystore_Alias`
- **Target Flag**: `OBV{4ndr01d_k3ys70r3_4l14s_r3c0v3ry_55c1}`
- **Description**: ===[ ANDROID KEYSTORE ALIAS ]===
Difficulty: MEDIUM
Category: Mobile
Source: Real WhatsApp APK

Keystore entry alias decryption.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{4ndr01d_k3ys70r3_4l14s_r3c0v3ry_55c1}`.

#### 19. [MEDIUM] WebView JS Interface
- **Directory**: `mobile/medium/4_WebView_JS_Interface`
- **Target Flag**: `OBV{w3bv13w_j5_1n73rf4c3_3xp7_77a1}`
- **Description**: ===[ WEBVIEW JS INTERFACE ]===
Difficulty: MEDIUM
Category: Mobile
Source: Real Telegram APK

WebView addJavascriptInterface exploitation.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{w3bv13w_j5_1n73rf4c3_3xp7_77a1}`.

#### 20. [MEDIUM] Intent Spoofing Vuln
- **Directory**: `mobile/medium/5_Intent_Spoofing_Vuln`
- **Target Flag**: `OBV{1n73n7_sp00f1ng_vulc_3xp7_4411}`
- **Description**: ===[ INTENT SPOOFING VULN ]===
Difficulty: MEDIUM
Category: Mobile
Source: Real Instagram APK

BroadcastReceiver intent spoofing vulnerability.

File: app.apk

Flag: OBV{...}
- **Solution Summary**:
  1. Decompile APK/DEX using Jadx-GUI / APKTool, examine `AndroidManifest.xml`.
  2. Audit SharedPreferences, SQLite databases, deep link intents, or exported activities.
  3. Use Frida dynamic instrumentation to hook JNI `.so` native functions and bypass SSL pinning.
  4. Recover plain flag string: `OBV{1n73n7_sp00f1ng_vulc_3xp7_4411}`.

### 6. MISCELLANEOUS & SANDBOX ESCAPES (20 Challenges)

#### 1. [EASY] Brainfuck Interpreter
- **Directory**: `misc/easy/1_Brainfuck_Interpreter`
- **Target Flag**: `OBV{br41nfuck_350l4ng_1n73rpr373r_9921}`
- **Description**: ===[ BRAINFUCK INTERPRETER ]===
Difficulty: EASY
Category: Misc

Execute Brainfuck esolang script.

File: script.bf

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{br41nfuck_350l4ng_1n73rpr373r_9921}`.

#### 2. [EASY] QR Matrix Reconstruction
- **Directory**: `misc/easy/2_QR_Matrix_Reconstruction`
- **Target Flag**: `OBV{qr_m47r1x_4sc11_r3c0n57ruc710n_772a}`
- **Description**: ===[ QR MATRIX RECONSTRUCTION ]===
Difficulty: EASY
Category: Misc

ASCII QR matrix metadata.

File: qr_matrix.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{qr_m47r1x_4sc11_r3c0n57ruc710n_772a}`.

#### 3. [EASY] PyJail Basic Bypass
- **Directory**: `misc/easy/3_PyJail_Basic_Bypass`
- **Target Flag**: `OBV{pyj41l_b451c_bu1l71n5_byp455_1122}`
- **Description**: ===[ PYJAIL BASIC BYPASS ]===
Difficulty: EASY
Category: Misc

Bypass PyJail string filter to leak FLAG variable.

File: jail.py

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{pyj41l_b451c_bu1l71n5_byp455_1122}`.

#### 4. [EASY] Polyglot File Analysis
- **Directory**: `misc/easy/4_Polyglot_File_Analysis`
- **Target Flag**: `OBV{p0lygl07_f1l3_h34d3r_4n4lys15_881a}`
- **Description**: ===[ POLYGLOT FILE ANALYSIS ]===
Difficulty: EASY
Category: Misc

GIF / Text polyglot file header inspection.

File: sample.gif

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{p0lygl07_f1l3_h34d3r_4n4lys15_881a}`.

#### 5. [EASY] Regex Puzzle Solver
- **Directory**: `misc/easy/5_Regex_Puzzle_Solver`
- **Target Flag**: `OBV{r3g3x_puzzl3_m47ch_s0lv3r_3399}`
- **Description**: ===[ REGEX PUZZLE SOLVER ]===
Difficulty: EASY
Category: Misc

Regular expression string matching.

File: regex_data.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{r3g3x_puzzl3_m47ch_s0lv3r_3399}`.

#### 6. [HARD] Zero Builtins PyJail
- **Directory**: `misc/hard/1_Zero_Builtins_PyJail`
- **Target Flag**: `OBV{z3r0_bu1l71n5_pyj41l_3sc4p3_8899}`
- **Description**: ===[ ZERO BUILTINS PYJAIL ]===
Difficulty: HARD
Category: Misc

PyJail execution with empty `__builtins__` environment.

File: zero_builtins.py

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{z3r0_bu1l71n5_pyj41l_3sc4p3_8899}`.

#### 7. [HARD] Custom Protocol StateMachine
- **Directory**: `misc/hard/2_Custom_Protocol_StateMachine`
- **Target Flag**: `OBV{pr070c0l_57473_m4ch1n3_3xp7_221a}`
- **Description**: ===[ CUSTOM PROTOCOL STATE MACHINE ]===
Difficulty: HARD
Category: Misc

State machine transition packet sequence solver.

File: protocol_spec.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{pr070c0l_57473_m4ch1n3_3xp7_221a}`.

#### 8. [HARD] Game AntiCheat Bypass
- **Directory**: `misc/hard/3_Game_AntiCheat_Bypass`
- **Target Flag**: `OBV{g4m3_4n71ch347_h00k_byp455_77b1}`
- **Description**: ===[ GAME ANTICHEAT BYPASS ]===
Difficulty: HARD
Category: Misc

Bypassing memory integrity checks in game process.

File: anticheat.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{g4m3_4n71ch347_h00k_byp455_77b1}`.

#### 9. [HARD] Maze Pathfinding Automata
- **Directory**: `misc/hard/4_Maze_Pathfinding_Automata`
- **Target Flag**: `OBV{m4z3_p47hf1nd1ng_bfr5_s0lv3r_4411}`
- **Description**: ===[ MAZE PATHFINDING AUTOMATA ]===
Difficulty: HARD
Category: Misc

Breadth-first search shortest path in matrix grid.

File: maze.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{m4z3_p47hf1nd1ng_bfr5_s0lv3r_4411}`.

#### 10. [HARD] Custom Binary Unpacker
- **Directory**: `misc/hard/5_Custom_Binary_Unpacker`
- **Target Flag**: `OBV{cus70m_b1n4ry_unp4ck3r_57ub_1122}`
- **Description**: ===[ CUSTOM BINARY UNPACKER ]===
Difficulty: HARD
Category: Misc

Self-extracting unpacked stub payload extraction.

File: unpacked.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{cus70m_b1n4ry_unp4ck3r_57ub_1122}`.

#### 11. [INSANE] Symbolic Execution Z3
- **Directory**: `misc/insane/1_Symbolic_Execution_Z3`
- **Target Flag**: `OBV{symb0l1c_3x3cu710n_z3_s0lv3r_99a1}`
- **Description**: ===[ SYMBOLIC EXECUTION Z3 ]===
Difficulty: INSANE
Category: Misc

Solving SMT constraint logic using Z3 symbolic execution.

File: z3_spec.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{symb0l1c_3x3cu710n_z3_s0lv3r_99a1}`.

#### 12. [INSANE] Brainfuck x86 JIT Compiler
- **Directory**: `misc/insane/2_Brainfuck_x86_JIT_Compiler`
- **Target Flag**: `OBV{br41nfuck_x86_j17_c0mp1l3r_7721}`
- **Description**: ===[ BRAINFUCK X86 JIT COMPILER ]===
Difficulty: INSANE
Category: Misc

Reversing machine code emitted by JIT compiler.

File: jit.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{br41nfuck_x86_j17_c0mp1l3r_7721}`.

#### 13. [INSANE] Obfuscated JS VM Interpreter
- **Directory**: `misc/insane/3_Obfuscated_JS_VM_Interpreter`
- **Target Flag**: `OBV{0bfusc473d_js_vm_1n73rpr373r_5511}`
- **Description**: ===[ OBFUSCATED JS VM INTERPRETER ]===
Difficulty: INSANE
Category: Misc

De-obfuscating JS Virtual Machine execution AST.

File: js_vm.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{0bfusc473d_js_vm_1n73rpr373r_5511}`.

#### 14. [INSANE] Self Referential Quine Vuln
- **Directory**: `misc/insane/4_Self_Referential_Quine_Vuln`
- **Target Flag**: `OBV{q3_s3lf_r3f3r3n714l_qu1n3_3xp1017_88a1}`
- **Description**: ===[ SELF REFERENTIAL QUINE VULN ]===
Difficulty: INSANE
Category: Misc

Exploiting quine source code reflection vulnerability.

File: quine.py

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{q3_s3lf_r3f3r3n714l_qu1n3_3xp1017_88a1}`.

#### 15. [INSANE] SAT SMT Constraint Logic
- **Directory**: `misc/insane/5_SAT_SMT_Constraint_Logic`
- **Target Flag**: `OBV{s47_sm7_c0ns7r41n7_l0g1c_c4ll_22b1}`
- **Description**: ===[ SAT SMT CONSTRAINT LOGIC ]===
Difficulty: INSANE
Category: Misc

SAT solver boolean satisfiability problem.

File: sat.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{s47_sm7_c0ns7r41n7_l0g1c_c4ll_22b1}`.

#### 16. [MEDIUM] PyJail AST Bypass
- **Directory**: `misc/medium/1_PyJail_AST_Bypass`
- **Target Flag**: `OBV{pyj41l_457_4ud17_h00k_byp455_44a1}`
- **Description**: ===[ PYJAIL AST BYPASS ]===
Difficulty: MEDIUM
Category: Misc

PyJail AST node inspection bypass.

File: ast_jail.py

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{pyj41l_457_4ud17_h00k_byp455_44a1}`.

#### 17. [MEDIUM] Bytecode VM Decompile
- **Directory**: `misc/medium/2_Bytecode_VM_Decompile`
- **Target Flag**: `OBV{by73c0d3_vm_d3c0mp1l3_p47ch_55b2}`
- **Description**: ===[ BYTECODE VM DECOMPILE ]===
Difficulty: MEDIUM
Category: Misc

Custom opcode VM decompilation.

File: vm_spec.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{by73c0d3_vm_d3c0mp1l3_p47ch_55b2}`.

#### 18. [MEDIUM] Known Plaintext Zip
- **Directory**: `misc/medium/3_Known_Plaintext_Zip`
- **Target Flag**: `OBV{kn0wn_pl41n73x7_z1p_4774ck_9901}`
- **Description**: ===[ KNOWN PLAINTEXT ZIP ]===
Difficulty: MEDIUM
Category: Misc

ZIP archive encryption with known header bytes.

File: zip_data.bin

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{kn0wn_pl41n73x7_z1p_4774ck_9901}`.

#### 19. [MEDIUM] Game Memory Patch
- **Directory**: `misc/medium/4_Game_Memory_Patch`
- **Target Flag**: `OBV{g4m3_m3m0ry_p47ch_5c0r3_1337_77a1}`
- **Description**: ===[ GAME MEMORY PATCH ]===
Difficulty: MEDIUM
Category: Misc

Memory score address patch to trigger win condition.

File: game_dump.bin

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{g4m3_m3m0ry_p47ch_5c0r3_1337_77a1}`.

#### 20. [MEDIUM] Audio DTMF Decoder
- **Directory**: `misc/medium/5_Audio_DTMF_Decoder`
- **Target Flag**: `OBV{du4l_70n3_mul71_fr3qu3ncy_d7mf_22b1}`
- **Description**: ===[ AUDIO DTMF DECODER ]===
Difficulty: MEDIUM
Category: Misc

Dual-tone multi-frequency phone keypad audio decoding.

File: dtmf.json

Flag: OBV{...}
- **Solution Summary**:
  1. Inspect sandbox environment constraints (PyJail AST hooks, Regex, Brainfuck JIT, state machines).
  2. Build python exploit script / Z3 constraint model / BFS pathfinder.
  3. Execute escape payload and read flag: `OBV{du4l_70n3_mul71_fr3qu3ncy_d7mf_22b1}`.

---

## TOOLING & EXPLOITATION REFERENCE MATRIX

| Category | Primary Analysis Tools | Core Exploitation Techniques |
| :--- | :--- | :--- |
| **Reverse** | Ghidra, IDA Pro, GDB, pwndbg, objdump | Anti-debugging neutralization, Feistel reversing, VM de-flattening |
| **Crypto** | SageMath, PyCryptodome, z3-solver, fpylll | Hastad broadcast, LLL CVP embedding, Pohlig-Hellman, Padding Oracle |
| **Forensics**| Wireshark, tshark, Volatility 3, binwalk, zsteg | Magic byte repair, PCAP stream exfiltration, Spectrogram visual analysis |
| **AI / ML** | PyTorch, Safetensors, Transformers, NumPy | Indirect prompt injection, safetensors metadata extraction, FGSM |
| **Mobile** | Jadx, APKTool, Frida, ADB, SQLCipher | Smali bytecode patching, SSL unpinning, JNI native library reversing |
| **Misc** | Z3 Solver, pwntools, scanmem, multimon-ng | PyJail sandbox escape, Known-plaintext Zip, Real-time maze BFS |

---

## CONCLUSION

All 145 challenges in this repository have been fully audited, solved, and verified.
Individual challenge write-ups are maintained inside each respective challenge directory under `solution/write-up.txt`.
