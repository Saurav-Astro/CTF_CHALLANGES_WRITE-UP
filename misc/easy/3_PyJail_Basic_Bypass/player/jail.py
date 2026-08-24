#!/usr/bin/env python3
import sys

# Encrypted Flag runtime store
_enc = bytes.fromhex("15180c212a23306e6b3605386e6f6b3905382f6b366d6b346f0538232a6e6f6f056b6b686827")
FLAG = bytes([b ^ 0x5A for b in _enc]).decode()

def main():
    user_input = input(">>> ")
    # Evaluation environment
    eval(user_input, {"__builtins__": {}}, {"FLAG": FLAG})

if __name__ == "__main__":
    main()
