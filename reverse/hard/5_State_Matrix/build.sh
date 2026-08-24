#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 5_State_Matrix..."
gcc -O2 -s src/state_matrix.c -o player/state_matrix
chmod +x player/state_matrix

echo "[+] Built player/state_matrix successfully!"
