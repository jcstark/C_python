#!/usr/bin/env python3

from cs50 import get_int


def block():
    print("#", end="")


def air():
    print(" ", end="")


def pyramid(height):
    for i in range(1, height + 1, 1):
        for j in range(height + 1, i + 1, -1):
            air()
        for x in range(i):
            block()
        print("")


def main():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    pyramid(height)


if __name__ == "__main__":
    main()