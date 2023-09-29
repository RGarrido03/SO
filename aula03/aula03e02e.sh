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

if [[ $1 -gt 5 && $1 -lt 10 ]]; then
    echo "Número maior do que 5 e menor do que 10"
fi
