#!/usr/bin/env python3
import sys

# Encrypted Flag runtime store
_enc = bytes.fromhex("15180c212b69052969363c0528693c692869346d6b6e36052b2f6b34690569222a6b6a6b6d0562623b6b27")
SECRET = bytes([b ^ 0x5A for b in _enc]).decode()

def main():
    user_input = input(">>> ")
    # Evaluation environment
    eval(user_input, {"__builtins__": {}}, {"SECRET": SECRET})

if __name__ == "__main__":
    main()
