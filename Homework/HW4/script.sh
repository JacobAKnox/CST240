#!/bin/bash
removelog="/home/hazel/remove.log"
if [ $# -eq 0 ] ; then
	echo "Usage: $0 [-s] list of files or directories" >&2
	exit 1
fi

if [ "$1" = "-s" ] ; then
	shift
else
	echo "$(date): ${USER}: $@" >> $removelog
fi

rm "$@"
exit 0
