#!/usr/bin/env bash
readarray -t unsorted <$1
sorted=()

# Initialize variables
idx0=0
idx1=0

while [[ ${#unsorted[@]} -ne 0 ]]; do
    # Find min value
    minIdx=0
    for i in ${!unsorted[@]}; do
        if [[ ${unsorted[i]} -lt ${unsorted[minIdx]} ]]; then
            minIdx=$i
        fi
    done

    # Push min value to sorted array
    sorted+=(${unsorted[minIdx]})

    # Remove min value from unsorted array
    unset unsorted[$minIdx]
done

for i in ${sorted[@]}; do
    echo "$i"
done
