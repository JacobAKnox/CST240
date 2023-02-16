#!/bin/python3.11

# Jacob Knox CST240 L5 2/15/2023``

import sys

def railfence(str, key):
    # create the rail, length of string, height of key
    rail = [['\n' for i in range(len(str))] for j in range(key)]
    dir_down = False
    row, col = 0, 0
    
    # loop through the string
    for i in range(len(str)):
        # check if we are at the top or bottom of the rail and change direction
        if (row == 0) or (row == key - 1):
            dir_down = not dir_down
        # add the character to the rail
        rail[row][col] = str[i]
        col += 1
        # change the row
        if dir_down:
            row += 1
        else:
            row -= 1

    result = ""
    # loop through the rail and add the characters to the result
    # go over each column before moving to the next row
    for i in range(key):
        for j in range(len(str)):
            if rail[i][j] != '\n':
                result += rail[i][j]
    return result

def main():
   # check the number of arguments
    if len(sys.argv) != 3:
        print("Usage: railfence.py <key> <filename>")
        sys.exit()
    
    # get the key and filename
    key = sys.argv[1]
    filename = sys.argv[2]

    # convert the key to an integer
    try:
        key = int(key)
    except ValueError:
        print("Key must be an integer")
        sys.exit()
    
    # make sure the key is positive
    if key < 1:
        print("Key must be positive")
        sys.exit()
    
    # make sure the file exists
    try:
        f = open(filename, "r")
        f.close()
    except FileNotFoundError:
        print("File not found")
        sys.exit()
    
    # open the file
    with open(filename, "r") as f:
        # read each line
        for line in f:
            # remove the newline
            line = line.rstrip()
            # encrypt the line
            encrypted = railfence(line, key)
            # print the encrypted line
            print(encrypted)

# call the main function    
if __name__ == "__main__":
    main()
