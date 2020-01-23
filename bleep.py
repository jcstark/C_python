#!/usr/bin/env python3
from cs50 import get_string
from sys import argv


def main():
    # Ensure correct usage
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary or ./bleep.py dictionary")
        exit(1)
    # Open the text file with banned words and put them into a list
    file = open(argv[1], "r")
    fl = file.readlines()
    i = 0
    banned = []
    for x in fl:
        banned.insert(i, x.strip())
        i += 1
    # Input the message to ban and split their single words with correct format into a list
    message = get_string("What message would you like to censor?\n")
    message_list = message.strip()
    message_list = message_list.split()
    # Check the message to ban
    for x in message_list:
        if x.lower() in banned:
            print("*" * len(x), end=" ")
        else:
            print(x, end=" ")
    print()
    exit(0)


if __name__ == "__main__":
    main()

