#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 1_Matrix_Cipher..."
gcc -O2 -s src/matrix_cipher.c -o player/matrix_cipher
chmod +x player/matrix_cipher

echo "[+] Built player/matrix_cipher successfully!"
