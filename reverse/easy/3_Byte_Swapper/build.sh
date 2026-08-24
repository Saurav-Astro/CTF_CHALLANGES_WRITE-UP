#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 3_Byte_Swapper..."
gcc -O2 -s src/byte_swapper.c -o player/byte_swapper
chmod +x player/byte_swapper

echo "[+] Built player/byte_swapper successfully!"
