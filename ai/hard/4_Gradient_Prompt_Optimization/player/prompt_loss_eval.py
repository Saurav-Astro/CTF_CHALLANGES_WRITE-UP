#!/usr/bin/env python3
import os, sys, numpy as np

TARGET_VEC = np.array([71.0, 79.0, 80.0, 84.0], dtype=np.float32)
FLAG = os.getenv("CHALLENGE_FLAG", "OBV{placeholder_flag_set_at_runtime}")

def compute_loss(x_vec):
    x = np.array(x_vec, dtype=np.float32)
    return float(np.sum((x - TARGET_VEC) ** 2))

if __name__ == "__main__":
    if len(sys.argv) < 5:
        print("Usage: python3 prompt_loss_eval.py <x0> <x1> <x2> <x3>")
        sys.exit(1)
    vec = [float(a) for a in sys.argv[1:5]]
    loss = compute_loss(vec)
    if loss < 1e-4:
        print(f"OPTIMAL LOSS {loss:.6f} -> FLAG: {FLAG}")
    else:
        print(f"Loss: {loss:.6f}")
