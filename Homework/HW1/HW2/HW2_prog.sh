#!/bin/bash
for filename in "$@"
do
	linecount="1"
	while IFS="\n" read line
	do
		echo "${linecount}: $line"
		linecount="$(( $linecount + 1 ))"
	done < $filename
done
exit 0
