#!/bin/python3.11

# Jacob Knox CST240 L5 2/15/2023

import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: ceaser.py <key> <file>")
        sys.exit(1)

    try:
        # try to convert the key to an integer
        key = int(sys.argv[1])
    except ValueError:
        # if it fails, print an error message and exit
        print("Key must be an integer")
        sys.exit(1)

    # make sure the key is between 1 and 25
    if key < 1 or key > 25:
        print("Key must be between 1 and 25")
        sys.exit(1)
    
    # make sure the file exists
    try:
        f = open(sys.argv[2], "r")
        f.close()
    except FileNotFoundError:
        print("File not found")
        sys.exit(1)

    # open the file
    with open(sys.argv[2], "r") as f:
        # read the file into a string
        text = f.read()

        # create a new string to hold the encrypted text
        encrypted = ""
        
        # loop through each character in the text
        for c in text:
            # print a new line if the character is a new line
            if c == '\n':
                encrypted += '\n'
            # check if the character is not a-z
            if not (c >= 'a' and c <= 'z'):
                # skip it
                continue
            # convert the character to an integer
            i = ord(c)
            # add the key to the integer
            i += key
            # check if the integer is greater than z
            if i > ord('z'):
                # subtract 26 to wrap around
                i -= 26
            # check if the integer is less than a
            if i < ord('a'):
                # add 26 to wrap around
                i += 26
            # convert the integer back to a character
            c = chr(i)
            # add the character to the encrypted text
            encrypted += c
        # print the encrypted text
        print(encrypted)

# call the main function
if __name__ == "__main__":
    main()
