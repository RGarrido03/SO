#!/bin/bash
#This script does a very simple test for checking disk space.
largestSpace=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | tail -1 | cut -d "%" -f1 -)
smallestSpace=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | head -1 | cut -d "%" -f1 -)
echo "Largest occupied space = $largestSpace%"
echo "Smallest occupied space = $smallestSpace%"

case $largestSpace in
[0-9] | [1-6][0-9]) # espaço < 70%
    Message="All OK."
    ;;
[7-8][0-9]) # 70% <= espaço < 90%
    Message="Cleaning out. One partition is $largestSpace % full."
    ;;
9[0-8]) # 90% <= espaço < 99%
    Message="Better buy a new disk. One partition is $largestSpace % full."
    ;;
99 | 100) # espaço >= 99%
    Message="I'm drowning here! There's a partition at $largestSpace %!"
    ;;
*)
    Message="I seem to be running with a non-existent disk..."
    ;;
esac

echo $Message
