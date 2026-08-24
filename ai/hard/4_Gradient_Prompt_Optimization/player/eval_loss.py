#!/usr/bin/env python3
import os, sys

TARGET_X = 1337
FLAG = os.getenv("CHALLENGE_FLAG", "OBV{placeholder_flag_set_at_runtime}")

def get_loss(x):
    return (x - TARGET_X) ** 2

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 eval_loss.py <x>")
        sys.exit(1)
    val = int(sys.argv[1])
    loss = get_loss(val)
    if loss == 0:
        print(f"LOSS OPTIMAL: {loss} -> FLAG: {FLAG}")
    else:
        print(f"Loss: {loss}")
