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