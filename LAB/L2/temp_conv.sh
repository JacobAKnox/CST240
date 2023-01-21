#!/bin/bash

# By Jacob Knox
# for CST240 Lab 2 due: 1/25/2022

# make sure there is one argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 temprature[C,c,F,f]"
    echo "where the suffix is:"
    echo "  f/F for Farhenheit (default if no f/F, c/C or space)"
    echo "  c/C for Celsius"
    exit 1
fi

# slice the last character
last=${1: -1}
 
# temperature is the rest of the string
temp=${1:0: -1}

#check if whole input is a number
if [ ${1} -eq ${1} 2>/dev/null ]; then
    #case with no last charcter default to F
    echo $1
    echo "Farhenheit = $1"
    echo "Celsius = $((($1 - 32) * 5 / 9))"
    exit 0
fi

C=$temp
F=$temp
unit=""

# check the last character
if [ $last = "c" -o $last = "C" ]; then
    F=$(( ( ${temp} * 9 / 5 ) + 32 ))
    unit="C"
elif [ $last = "f" -o $last = "F" ]; then
    C=$(( ( ${temp} - 32 ) * 5 / 9 ))
    unit="F"
else # unknown unit given
    echo $last
    echo $temp
    echo "Input temp not correct"
    exit 1
fi

echo $temp
echo $unit
echo "Celsius = $C"
echo "Farhenheit = $F"

exit 0
