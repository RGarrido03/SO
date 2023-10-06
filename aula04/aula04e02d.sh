#!/usr/bin/env bash
function bigger() {
    if [[ $1 -gt $2 ]]; then
        biggerRet=$1
    else
        biggerRet=$2
    fi
    return 0
}

read -p "Input first number: " n1
read -p "Input second number: " n2

if [[ $n1 = $n2 ]]; then
    echo "Numbers are equal ($n1)."
else
    bigger $n1 $n2
    echo "Numbers are different. Biggest number: $biggerRet"
fi
