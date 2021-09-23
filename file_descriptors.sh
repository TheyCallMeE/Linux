#!/bin/bash

x=0
declare -a pids=( $( ls -d /proc/[0-9]* | cut -d '/' -f 3) )
len=${#pids[@]}

while (( $x < $len )); do
	pid=${pids[$x]}
	process=$( cat /proc/$pid/comm )
	echo
	echo $pid: $process
	sudo ls -l /proc/$pid/fd | cut -d ' ' -f 9-
	x=$(( x + 1 ))
done	
