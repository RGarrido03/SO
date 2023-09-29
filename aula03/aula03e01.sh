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

# Agrupamento de comandos na Bash
{
    i=0
    while read line; do
        echo $i: $line
        i=$(($i + 1))
    done
} <$1
