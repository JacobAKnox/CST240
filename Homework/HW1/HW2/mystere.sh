#!/bin/bash
# Given date, tells what Mon-Sun date is

if [ $# -ne 3 ] ; then
	echo "Usage $(basename $0) mon day year" >&2
	echo " with just numerical values (ex: 7 4 1993)" >&2
	exit 1
fi

date --version > /dev/null 2>&2
baddate="$?"

if [ ! $baddate ] ; then
	date -d $1/$2/$3 +"That was a %A."
else
	if [ $2 -lt 10 ] ; then
		pattern=" $2[^0-9]"
	else
		pattern="$2[^0-9]"
	fi
	dayofweek="$(ncal $1 $3 | grep "$pattern" | cut -c1-2)"
	echo $dayofweek
	fi
	exit 0

fi
	exit 0
