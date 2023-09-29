#!/bin/bash
ARGNUMMIN=1
ARGNUMMAX=1
if [[ $# -lt $ARGNUMMIN || $# -gt $ARGNUMMAX ]]; then
    if ! (($ARGNUMMAX - $ARGNUMMIN)); then
        echo "Number of arguments must be $ARGNUMMIN."
    else
        echo "Number of arguments must be between $ARGNUMMIN and $ARGNUMMAX."
    fi
    exit
fi

if ! [[ -d $1 ]]; then
    echo "$1 is not a directory."
    exit
fi

# For all the files in a folder, show their properties
for f in $1/*; do
    file "$f"
done
