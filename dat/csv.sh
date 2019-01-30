#!/bin/bash

for input in $(ls *.dat); do
	output=$(basename $input)".csv"
	echo $input
	echo $output
	cat $input |  tr "\\t" "," > $output

done
