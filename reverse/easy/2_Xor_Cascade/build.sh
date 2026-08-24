#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 2_Xor_Cascade..."
gcc -O2 -s src/xor_cascade.c -o player/xor_cascade
chmod +x player/xor_cascade

echo "[+] Built player/xor_cascade successfully!"
