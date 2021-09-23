#!/bin/bash

pid=0

x=0
declare -a pids=( $( ls -d /proc/[0-9]* | cut -d '/' -f 3) )
len=${#pids[@]}

while (( $x < $len )); do
	pid=${pids[$x]}
        x=$(( x + 1 ))
	owner=$( ls -ld /proc/$pid | cut -d ' ' -f 3 )
	process=$( cat /proc/$pid/comm )
	path=$( sudo readlink /proc/$pid/exe )
	echo "PID: $pid       Process Name: $process       Owner: $owner      Path: $path" 
	
done
