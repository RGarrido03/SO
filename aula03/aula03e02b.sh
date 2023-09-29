#!/bin/bash
ARGNUMMIN=2
ARGNUMMAX=2
if [[ $# -lt $ARGNUMMIN || $# -gt $ARGNUMMAX ]]; then
    if ! (($ARGNUMMAX - $ARGNUMMIN)); then
        echo "Number of arguments must be $ARGNUMMIN."
    else
        echo "Number of arguments must be between $ARGNUMMIN and $ARGNUMMAX."
    fi
    exit
fi

# Conditional block if
if [[ $1 = $2 ]] ; then
    echo "O arg1 é igual ao arg2"
else
    echo "Os args são diferentes"
fi