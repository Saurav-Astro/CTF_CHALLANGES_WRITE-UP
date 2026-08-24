#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "[*] Building 5_Titan_Hydra..."
gcc -O2 -s src/titan_hydra_host.c -o player/titan_hydra
chmod +x player/titan_hydra

# Copy WASM module and ARM64 binary placeholder into player/
cp src/module.wat player/module.wat 2>/dev/null || true
echo "AGY_WASM_BYTECODE_INSANE_STUB" > player/module.wasm
echo "AGY_ARM64_BINARY_INSANE_STUB" > player/arm64_child

echo "[+] Built player/titan_hydra successfully!"
