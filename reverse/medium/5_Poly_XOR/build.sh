#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 5_Poly_XOR..."
gcc -O2 -s src/poly_xor.c -o player/poly_xor
chmod +x player/poly_xor

echo "[+] Built player/poly_xor successfully!"
