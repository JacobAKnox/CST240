#!/bin/bash
# Jacob Knox CST240
# Quiz 2 1/25/2022


if [ $# -ne 1 ] ; then
	echo "Usage: $(basename $0) number" >&2
    exit 1
fi

str1=$1
phone_pattern='.?([0-9]{3}).*([0-9]{3}).*([0-9]{4})'
declare -A phone
[[ $str1 =~ $phone_pattern ]]
phone[area_code]=${BASH_REMATCH[1]}
phone[exchange]=${BASH_REMATCH[2]}
phone[line_number]=${BASH_REMATCH[3]}
echo ${BASH_REMATCH[0]}
echo ${phone[@]}
echo ${phone[area_code]}
echo ${phone[exchange]}
echo ${phone[line_number]}
exit 0
