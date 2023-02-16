#!/bin/bash

# Jacob Knox CST 240 Midterm 2/15/2023

# make sure the parameters are correct
if [ $# -ne 2 ]; then
    echo "Usage: $0 <key> <file>"
    exit 1
fi

# make sure the key is an integer
if ! [[ $1 =~ ^[0-9]+$ ]]; then
    echo "Key must be an integer"
    exit 1
fi

# make sure the key is between 0 and 26
if [ $1 -lt 0 ] || [ $1 -gt 26 ]; then
    echo "Key must be between 0 and 26"
    exit 1
fi

# make sure the file exists
if [ ! -f $2 ]; then
    echo "File $2 does not exist"
    exit 1
fi

# loop over each line in the file
while read line; do
    # loop over each character in the line
    for (( i=0; i<${#line}; i++ )); do
        # get the character
        c=${line:$i:1}

        # if the character is A-Z
        if [[ $c =~ [A-Z] ]]; then
            # convert the character to a number
            n=$(printf "%d" "'$c")

            # add the key to the number
            n=$((n + $1))

            # convert the number back to a character
            c=$(printf "\x$(printf %x $n)")

            # print the character
            echo -n $c
        fi
    done

    # print a newline
    echo
done < $2
