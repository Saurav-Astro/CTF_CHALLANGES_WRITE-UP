#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 2_Kronos_Polymorphic..."
gcc -O2 -s src/kronos_polymorphic.c -o player/kronos_polymorphic
chmod +x player/kronos_polymorphic

echo "[+] Built player/kronos_polymorphic successfully!"
