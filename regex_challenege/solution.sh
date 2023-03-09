#!/bin/bash

# make sure we have the right number of arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 input_file output_file"
    exit 1
fi

# read input and output files
input_file=$1
output_file=$2

# check if input file exists
if [ ! -f $input_file ]; then
    echo "Input file $input_file does not exist"
    exit 1
fi

# check if output file exists
if [ -f $output_file ]; then
    echo "Output file $output_file already exists"
    exit 1
fi

# use sed to find any phone numbers and put them in (xxx) xxx-xxxx format
sed -r -e 's/.*([0-9]{3}).*([0-9]{3}).*([0-9]{4})/(\1) \2-\3/g' $input_file > $output_file
