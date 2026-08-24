#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 2_Shadow_Packer..."
gcc -O2 -s src/shadow_packer.c -o player/shadow_packer
chmod +x player/shadow_packer

echo "[+] Built player/shadow_packer successfully!"
