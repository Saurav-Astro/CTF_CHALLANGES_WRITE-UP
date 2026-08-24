#!/usr/bin/env python3
import sys, numpy as np

# Target ASCII "DPSGD" -> [68, 80, 83, 71, 68]
TARGET_BYTES = [68, 80, 83, 71, 68]

def query_dp_gradient(position):
    if position < 0 or position >= len(TARGET_BYTES):
        return 0.0
    true_val = float(TARGET_BYTES[position])
    noise = np.random.normal(0.0, 0.01)
    return true_val + noise

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 dp_oracle.py <position>")
        sys.exit(1)
    pos = int(sys.argv[1])
    print(f"Noisy Gradient: {query_dp_gradient(pos)}")
