#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 3_Kernel_Phantom..."
gcc -O2 -s src/kernel_phantom.c -o player/kernel_phantom
chmod +x player/kernel_phantom

echo "[+] Built player/kernel_phantom successfully!"
