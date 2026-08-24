#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 4_Shift_Cipher..."
gcc -O2 -s src/shift_cipher.c -o player/shift_cipher
chmod +x player/shift_cipher

echo "[+] Built player/shift_cipher successfully!"
