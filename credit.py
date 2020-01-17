#!/usr/bin/env python3
from cs50 import get_int


def main():
    number = get_int("Number: ")
    check = 0
    front = 0
    for i in range(17):
        # Sum of the numbers multiplied by 2.
        if i % 2 == 0:
            a = (number % pow(10, i)) // pow(10, i - 1)
            b = 2 * a
            if b >= 10:
                b = 1 + b % 10
            check = check + b
        # Sum to the previous sum the sum of the other numbers.
        elif i % 2 == 1:
            c = (number % pow(10, i)) // pow(10, i - 1)
            check = check + c

    # Calculate of the two leading digits of the number.
    dec = 0
    i = 16
    while True:
        dec = number // pow(10, i)
        if dec != 0:
            unit = number % pow(10, i) // pow(10, i - 1)
            front = dec * 10 + unit
            break
        i -= 1
        if dec != 0:
            break

    # Perform the 10module of the checknum.
    check = check % 10

    # Check if the module of is 0 and the characteristics of all different cards.
    if check == 0 and number > pow(10, 14) and number < pow(10, 15) and (front == 34 or front == 37):
        print("AMEX")
    elif check == 0 and number > pow(10, 15) and number < pow(10, 16) and front >= 51 and front <= 55:
        print("MASTERCARD")
    elif check == 0 and number > pow(10, 12) and number < pow(10, 16) and front >= 40 and front < 50:
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()

# Fundamentally I' ve translated my own c code to python in this problem.
# https://github.com/me50/jcstark/blob/cs50/problems/2019/x/credit/credit.c