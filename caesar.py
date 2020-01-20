#!/usr/bin/env python3
from sys import argv
from cs50 import get_string


def main():
    # Ensure correct usage
    if len(argv) != 2 or int(argv[1]) < 0:
        print("Usage: python caesar.py k or ./caesar.py k")
        return 1
    # Insert text to encrypt
    plaintext = get_string("Plaintext: ")
    for c in plaintext:
        # Encrypt every alphabetical character
        if (ord(c) > 64 and ord(c) < 91 or ord(c) > 96 and ord(c) < 123):
            print(chr(ord(c) + (int(argv[1]) % 26)), end="")
        # Do not encrypt non-alphabetical characters
        else:
            print(c, end="")
    print()


if __name__ == "__main__":
    main()