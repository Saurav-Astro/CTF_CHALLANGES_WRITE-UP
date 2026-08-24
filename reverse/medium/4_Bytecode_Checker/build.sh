#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 4_Bytecode_Checker..."
gcc -O2 -s src/bytecode_checker.c -o player/bytecode_checker
chmod +x player/bytecode_checker

echo "[+] Built player/bytecode_checker successfully!"
