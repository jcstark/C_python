#!/usr/bin/env python3
from sys import argv
from cs50 import get_string


def main():
    # Ensure correct usage
    if len(argv) != 2 or int(argv[1]) < 0: #or # ins'tnum:
        print("Usage: python caesar.py k or ./caesar.py k")
        return 1
    k = int(argv[1]) % 26
    # Insert text to encrypt
    plaintext = get_string("plaintext: ")
    print("ciphertext: ", end="")
    for c in plaintext:
        # Encrypt every alphabetical character
        # Encrypt upper case characters
        if ord(c) > 64 and ord(c) < 91:
            if ord(c) + k < 91:
                print(chr(ord(c) + k), end="")
            else:
                print(chr(64 + (ord(c) + k) % 90), end="")
        # Encrypt lower case characters
        elif ord(c) > 96 and ord(c) < 123:
            if ord(c) + k < 123:
                print(chr((ord(c) + k)), end="")
            else:
                print(chr(97 + ((ord(c) + k)) % 123), end="")
        # Do not encrypt non-alphabetical characters
        else:
            print(c, end="")
    print()


if __name__ == "__main__":
    main()