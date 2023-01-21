#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

# validate it is an integer
if ! [[ $1 =~ ^[0-9]+$ ]]; then
    echo "Error: $1 is not a positive integer"
    exit 1
fi

# list to convert digit to word in all caps
conversion=(ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE)

# convert each digit to word
for (( i=0; i<${#1}; i++ )); do
    echo -n "${conversion[${1:$i:1}]} "
done

# 1 and 2 are prime
if [ $1 -le 2 ]; then
    echo "IS prime!"
    exit 0
fi

# check if it is divisible by any number between 2 and $1
for (( i=2; i<$1; i++ )); do
    if [ $(($1 % $i)) -eq 0 ]; then
        echo "IS NOT prime!"
        exit 0
    fi
done

echo "IS prime!"
exit 0
