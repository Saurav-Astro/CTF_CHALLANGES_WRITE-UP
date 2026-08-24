#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 3_Signal_Decrypter..."
gcc -O2 -s src/signal_decrypter.c -o player/signal_decrypter
chmod +x player/signal_decrypter

echo "[+] Built player/signal_decrypter successfully!"
