#!/bin/bash

# Jacob Knox CST211 Lab4 Ceaser Cipher
# Due 2/8/2022

# check the input
if [ $# -ne 2 ]; then
    echo "Usage: $0 <key(1-25)> <file>"
    exit 1
fi

# check the key
key=$1

# check if the key is a number
if [[ $key =~ [^0-9] ]]; then
    echo "Key must be a number"
    exit 1
fi

# check if the key is between 1 and 25
if [ $key -lt 1 ] || [ $key -gt 25 ]; then
    echo "Key must be between 1 and 25"
    exit 1
fi

# check the file
file=$2
if [ ! -f $file ]; then
    echo "File $file does not exist"
    exit 1
fi

# read the file
while read line; do
    # loop through each character
    for (( i=0; i<${#line}; i++ )); do
        # get the character
        char=${line:$i:1}

        # uses printf instead of echo to avoid a newline
        # check if it is a letter
        if [[ $char =~ [a-z] ]]; then
            # get the ascii value
            ascii=$(printf "%d" "'$char")
            # can ignore the case because we are only dealing with lower case
            ascii=$((ascii + key))
            if [ $ascii -gt 122 ]; then
                ascii=$((ascii - 26))
            fi
            # convert back to character
            char=$(printf "\x$(printf %x $ascii)")
            # print the character
            printf "$char"
        fi
        # do nothing if it is not a letter        
    done
    printf "\n"
done < $file

exit 0