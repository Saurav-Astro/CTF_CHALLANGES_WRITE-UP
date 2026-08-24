#!/usr/bin/env python3
import sys

# Encrypted Flag runtime store
_enc = bytes.fromhex("15180c212069286a05382f6b366d6b346f052a23306e6b36056929396e2a69056262636327")
SECRET_FLAG = bytes([b ^ 0x5A for b in _enc]).decode()

def main():
    user_input = input(">>> ")
    # Evaluation environment
    eval(user_input, {"__builtins__": {}}, {"SECRET_FLAG": SECRET_FLAG})

if __name__ == "__main__":
    main()
