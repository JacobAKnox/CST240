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
	date -d $1/$2/$3 +"%A"
else
	if [ $2 -lt 10 ] ; then
		pattern=" $2[^0-9]"
	else
		pattern="$2[^0-9]"
	fi
	dayofweek="$(ncal $1 $3 | grep "$pattern" | cut -c1-2)"
	case $dayofweek in
		"Mo") echo "Monday" ;;
		"Tu") echo "Tuesday" ;;
		"We") echo "Wednesday" ;;
		"Th") echo "Thursday" ;;
		"Fr") echo "Friday" ;;
		"Sa") echo "Saturday" ;;
		"Su") echo "Sunday" ;;
		*) echo "Error: $dayofweek is not a day of the week." ;;
	esac
	fi
	exit 0

fi
	exit 0
