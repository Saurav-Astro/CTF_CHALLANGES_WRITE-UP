#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 1_Oblivion_VM..."
gcc -O2 -s src/oblivion_vm.c -o player/oblivion_vm
chmod +x player/oblivion_vm

echo "[+] Built player/oblivion_vm successfully!"
