#!/usr/bin/env python3
import sys

# Encrypted Flag runtime store
_enc = bytes.fromhex("15180c212a23306e6b36056e6f6d056e2f3e6b6d05326a6a310538232a6e6f6f056e6e3b6b27")
SECRET = bytes([b ^ 0x5A for b in _enc]).decode()

def main():
    user_input = input(">>> ")
    # Evaluation environment
    eval(user_input, {"__builtins__": {}}, {"SECRET": SECRET})

if __name__ == "__main__":
    main()
