#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 1_Cipher_Lock..."
gcc -O2 -s src/cipher_lock.c -o player/cipher_lock
chmod +x player/cipher_lock

echo "[+] Built player/cipher_lock successfully!"
