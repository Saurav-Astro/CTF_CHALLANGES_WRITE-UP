#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 2_Custom_PRNG..."
gcc -O2 -s src/custom_prng.c -o player/custom_prng
chmod +x player/custom_prng

echo "[+] Built player/custom_prng successfully!"
