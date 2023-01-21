#!/bin/bash
linecount=10
while [ $linecount -gt 0 ]
do
	echo "${linecount}"
	linecount=$(( $linecount - 1 ))
done
exit 0
