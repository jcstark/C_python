#!/usr/bin/env python3
from cs50 import get_string


def main():
    # Initialization of variables
    sentences = 0
    words = 1
    letters = 0
    # Input
    text = get_string("Text: ")
    # Counting sentences, words and letters
    for x in text:
        if x == '!' or x == '?' or x == '...' or x == '.':
            sentences += 1
        if x == ' ':  # or x == "'":
            words += 1
        for c in x:
            if ord(c) > 64 and ord(c) < 91 or ord(c) > 96 and ord(c) < 123:
                letters += 1
    # Calculate the parameters
    L = (letters / words) * 100
    S = (sentences / words) * 100
    CLI = 0.0588 * L - 0.296 * S - 15.8
    # Print the grade of the text
    if CLI < 1:
        print("Before Grade 1")
    elif CLI >= 16:
        print("Grade 16+")
    else:
        print("Grade", end=" ")
        print(round(CLI))
    exit(0)


if __name__ == "__main__":
    main()