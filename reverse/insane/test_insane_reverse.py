#!/usr/bin/env python3
"""
Master Validation Suite for Insane Reverse Engineering Challenges (`reverse/insane/`)
Validates all 5 challenges, their binaries, flags, player distribution packages, and solvers.
"""

import subprocess
import os
import sys

BASE_DIR = "/home/astro/Documents/ctf/antigravity/reverse/insane"

CHALLENGES = [
    ("1_Oblivion_VM", "player/oblivion_vm", "OBV{CUST0M_VM_OPCODE_LIFTING_MAST3R}"),
    ("2_Kronos_Polymorphic", "player/kronos_polymorphic", "OBV{POLYMORPHIC_SELF_MODIFYING_DECRYPT_RCE}"),
    ("3_Kernel_Phantom", "player/kernel_phantom", "OBV{EBPF_KERNEL_RING_VERIFIER_ESCAPE}"),
    ("4_OLLVM_Flattened", "player/ollvm_flattened", "OBV{MBA_DEFLATTENING_SYMBOLIC_ANGR_SOLVE}"),
    ("5_Titan_Hydra", "player/titan_hydra", "OBV{MULTI_ARCH_WASM_ARM64_IPC_TRIAD}")
]

def main():
    print("======================================================================")
    print("  OPERATION BLACK VAULT — INSANE REVERSE ENGINEERING VERIFICATION")
    print("======================================================================\n")

    all_passed = True

    for name, bin_rel_path, expected_flag in CHALLENGES:
        print(f"[*] Validating Challenge: {name}")
        chal_dir = os.path.join(BASE_DIR, name)
        bin_path = os.path.join(chal_dir, bin_rel_path)
        solve_path = os.path.join(chal_dir, "solution/solve.py")

        # 1. Check file existence
        if not os.path.exists(bin_path):
            print(f"  [-] FAIL: Missing player binary at {bin_path}")
            all_passed = False
            continue

        if not os.path.exists(os.path.join(chal_dir, "desc.txt")):
            print(f"  [-] FAIL: Missing desc.txt")
            all_passed = False
            continue

        # Check player folder does NOT contain desc.txt
        if os.path.exists(os.path.join(chal_dir, "player/desc.txt")):
            print(f"  [-] FAIL: desc.txt incorrectly placed inside player/ directory!")
            all_passed = False
            continue

        # 2. Run solve.py
        proc_solve = subprocess.run(["python3", solve_path], cwd=chal_dir, capture_output=True, text=True)
        if proc_solve.returncode != 0:
            print(f"  [-] FAIL: Solver script exited with code {proc_solve.returncode}")
            print(proc_solve.stderr)
            all_passed = False
            continue

        if expected_flag not in proc_solve.stdout:
            print(f"  [-] FAIL: Solver output did not contain expected flag: {expected_flag}")
            all_passed = False
            continue
        print(f"  [+] Solver execution PASSED. Retrieved: {expected_flag}")

        # 3. Test binary with solved flag
        proc_bin = subprocess.run([bin_path, expected_flag], cwd=chal_dir, capture_output=True, text=True)
        if proc_bin.returncode != 0 or "[+] ACCESS GRANTED" not in proc_bin.stdout:
            print(f"  [-] FAIL: Executable rejected flag! Output:\n{proc_bin.stdout}")
            all_passed = False
            continue
        print(f"  [+] Binary execution PASSED: [ACCESS GRANTED]\n")

    print("======================================================================")
    if all_passed:
        print("  🎉 ALL 5 INSANE REVERSE ENGINEERING CHALLENGES PASSED 100%!")
    else:
        print("  ⚠️ SOME CHECKS FAILED!")
    print("======================================================================")

    sys.exit(0 if all_passed else 1)

if __name__ == "__main__":
    main()
