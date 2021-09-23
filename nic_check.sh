#!/bin/bash

# Checks and prints status of each NIC
nmcli device status

# Global variables
wifi_max_in=0
wifi_min_in=200000000
lo_max_in=0
lo_min_in=2000000000
wifi_max_out=0
wifi_min_out=20000000
lo_max_out=0
lo_min_out=20000000

# Use netstat and cut to acquire the total bytes received and sent on each NIC
# Store those values
# Sleep for 10 seconds then repeat step one but do not overwrite the stored values
# Subtract the more recent value from the stored value and divide by 10 to get the per second byte rate
# Store the difference (not divided by 10) in a running sum that takes the total rate from starting the script up to current time
# If greater than max rate, update. If less than min rate, update
# Overwrite the stored values with the most recently acquired ones

curr_wifi_in=$(cat /proc/net/dev | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 2)
curr_wifi_out=$(cat /proc/net/dev | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 11)
curr_lo_in=$(cat /proc/net/dev | head -n 3 | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 3)
curr_lo_out=$(cat /proc/net/dev | head -n 3 | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 11)

while true; do

	temp_wifi_in=$(cat /proc/net/dev | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 2)
	temp_wifi_out=$(cat /proc/net/dev | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 11)
	temp_lo_in=$(cat /proc/net/dev | head -n 3 | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 3)
	temp_lo_out=$(cat /proc/net/dev | head -n 3 | tail -n 1 | sed -r 's/ +/ /g' | cut -d ' ' -f 11)
	ingress_wifi=$(( $temp_wifi_in - $curr_wifi_in ))
	egress_wifi=$(( $temp_wifi_out - $curr_wifi_out ))
	ingress_lo=$(( $temp_lo_in - $curr_lo_in ))
	egress_lo=$(( $temp_lo_out - $curr_lo_out ))
	if (( $ingress_wifi > $wifi_max_in )); then
            wifi_max_in=$ingress_wifi
	fi
	if (( $ingress_wifi != 0 && $ingress_wifi < $wifi_min_in )); then
            wifi_min_in=$ingress_wifi
	fi
	if (( $ingress_lo > $lo_max_in )); then
            lo_max_in=$ingress_lo
	fi
	if (( $ingress_lo != 0 && $ingress_lo < $lo_min_in )); then
            lo_min_in=$ingress_lo
	fi
	if (( $egress_wifi > $wifi_max_out )); then
            wifi_max_out=$egress_wifi
	fi
	if (( $egress_wifi != 0 && $egress_wifi < $wifi_min_out )); then
            wifi_min_out=$egress_wifi
	fi
	if (( $egress_lo > $lo_max_out )); then
            lo_max_out=$egress_lo
	fi
	if (( $egress_lo != 0 && $egress_lo < $lo_min_out )); then
            lo_min_out=$egress_lo
	fi
	curr_wifi_in=$temp_wifi_in
	curr_wifi_out=$temp_wifi_out
	curr_lo_in=$temp_lo_in
	curr_lo_out=$temp_lo_out

	echo
	echo "WIFI ingress rate: $ingress_wifi"
	echo "WIFI egress rate: $egress_wifi"
	echo "LOOPBACK ingress rate: $ingress_lo"
	echo "LOOPBACK egress rate: $egress_lo"
	echo 
	echo "Maximum WIFI ingress rate: $wifi_max_in"
	echo "Minimum WIFI ingress rate: $wifi_min_in"
	echo "Maximum WIFI egress rate: $wifi_max_out"
	echo "Minimum WIFI egress rate: $wifi_min_out"
	echo "Maximum LOOPBACK ingress rate: $lo_max_in"
	echo "Minimum LOOPBACK ingress rate: $lo_min_in"
	echo "Maximum LOOPBACK egress rate: $lo_max_out"
	echo "Minimum LOOPBACK egress rate: $lo_min_out"
	echo 
	echo "Total WIFI bytes received: $curr_wifi_in"
	echo "Total WIFI bytes sent: $curr_wifi_out"
	echo "Total LOOPBACK bytes received: $curr_lo_in"
	echo "Total LOOPBACK bytes sent: $curr_lo_out"
	echo 
	echo

        nmcli device status

	sleep 1
done
