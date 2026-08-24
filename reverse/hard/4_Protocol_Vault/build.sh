#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 4_Protocol_Vault..."
gcc -O2 -s src/protocol_vault.c -o player/protocol_vault
chmod +x player/protocol_vault

echo "[+] Built player/protocol_vault successfully!"
