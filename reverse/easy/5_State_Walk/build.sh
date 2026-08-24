#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 5_State_Walk..."
gcc -O2 -s src/state_walk.c -o player/state_walk
chmod +x player/state_walk

echo "[+] Built player/state_walk successfully!"
