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

case $1 in
[0-9] | [1-9][0-9])
    echo "First argument is valid."
    ;;
*)
    echo "First argument is not valid."
    ;;
esac

case $2 in
sec*)
    echo "Second argument is valid."
    ;;
*)
    echo "Second argument is not valid."
    ;;
esac
