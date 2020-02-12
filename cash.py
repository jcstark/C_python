#!/usr/bin/env python3

from cs50 import get_float


def main():
    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break
    # Convert the amount of money from dollars to cents.
    cents = round(change*100)

    # Calculate the minimum number of coins to represent this amount.
    n = cents // 25
    if cents % 25 != 0:
        n = n + (cents % 25) // 10
    if (cents % 25) % 10 != 0:
        n = n + ((cents % 25) % 10)//5
    if ((cents % 25) % 10) % 5 != 0:
        n = n + (((cents % 25) % 10) % 5)

    # Print this number of coins.
    print("", n)


if __name__ == "__main__":
    main()