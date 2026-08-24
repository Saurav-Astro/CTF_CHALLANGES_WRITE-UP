#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 1_Key_Matrix..."
gcc -O2 -s src/key_matrix.c -o player/key_matrix
chmod +x player/key_matrix

echo "[+] Built player/key_matrix successfully!"
