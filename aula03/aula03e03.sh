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

# This script checks the existence of a file
if [[ -f $1 ]]; then
    echo "$1 existe."

    if [[ -d $1 ]]; then
        echo "$1 é um diretório."
    fi

    if [[ -w $1 ]]; then
        echo "$1 possui permissões de escrita."
    fi
else
    echo "$1 não existe."
fi
