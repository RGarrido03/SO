#!/usr/bin/env bash
source ./aula04e01fn.sh

function imprime_msg() {
    echoDate
    echoHostname
    echoWhoAmI
    return 0
}

imprime_msg
