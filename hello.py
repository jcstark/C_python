#!/usr/bin/env python3
from cs50 import get_string


def main():
    name = get_string("What is your name?\n")
    print("hello,", name)


if __name__ == "__main__":
    main()