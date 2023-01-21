#!/bin/bash
read -p "Input an animal name: " animal # read will always initialize animal
if [ -z  "$animal" ]; then # check if animal is empty, ${animla-$(la -a)} dosen't work
	echo $(ls -a)
else
	echo $animal
fi
