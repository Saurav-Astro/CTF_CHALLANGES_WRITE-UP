#!/usr/bin/env python3
import sys

# Secret target bytes for "M0D3L" = [77, 48, 68, 51, 76]
TARGET_BYTES = [77, 48, 68, 51, 76]

def query_confidence(position, byte_val):
    if position < 0 or position >= len(TARGET_BYTES):
        return 0.0
    if byte_val == TARGET_BYTES[position]:
        return 0.99
    return 0.01

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 model_eval.py <pos> <byte_val>")
        sys.exit(1)
    pos = int(sys.argv[1])
    bval = int(sys.argv[2])
    print(f"Confidence: {query_confidence(pos, bval)}")
