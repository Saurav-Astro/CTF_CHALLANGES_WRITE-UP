#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 4_OLLVM_Flattened..."
gcc -O2 -s src/ollvm_flattened.c -o player/ollvm_flattened
chmod +x player/ollvm_flattened

echo "[+] Built player/ollvm_flattened successfully!"
