#!/bin/bash

# Jacob Knox CST211 Lab4 Rail Fence Cipher
# Due 2/8/2022

# check the input
if [ $# -ne 2 ]; then
    echo "Usage: $0 <key> <file>"
    exit 1
fi

# check the key
key=$1
if [[ $key =~ [^0-9] ]]; then
    echo "Key must be a positive number"
    exit 1
fi

if [ $key -lt 1 ]; then
    echo "Key must be greater than 0"
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
    # loop through each line
    
    # special case for key 1
    if [ $key -eq 1 ]; then
        # filter non a-z
        line=$(echo $line | tr -cd 'a-z')
        echo $line
        continue
    fi

    # setup the rail fence
    # array of $key strings
    rail=()
    for ((i=0; i <= ($key-1); i++)); do
        rail[$i]=''
    done

    rail_index=0
    direction=-1

    # loop through each character
    for ((i=0; i<${#line}; i++)); do
        # check if the character is not a-z
        if [[ ${line:$i:1} =~ [^a-z] ]]; then
            continue
        fi

        # add the character to the rail
        rail[$rail_index]+="${line:$i:1}"

        # check if the direction needs to be changed
        if (($rail_index == 0 || $rail_index == $key - 1)); then
            direction=$((direction * -1))
        fi

        # change the rail index
        rail_index=$((rail_index + (direction == 1 ? 1 : -1)))
        
    done

    # combine the rails
    encrypted_line=""
    for ((i=0; i <= ($key-1); i++)); do
        encrypted_line+=${rail[$i]}
    done    
    echo $encrypted_line
done < $file

exit 0