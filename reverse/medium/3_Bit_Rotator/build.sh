#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 3_Bit_Rotator..."
gcc -O2 -s src/bit_rotator.c -o player/bit_rotator
chmod +x player/bit_rotator

echo "[+] Built player/bit_rotator successfully!"
