#!/bin/bash

pid=$( pgrep current_pid )
process=$( cat /proc/$pid/comm )
echo $pid $process
