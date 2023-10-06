#!/usr/bin/env bash
function echoDate() {
    echo $(date)
    return 0
}

function echoHostname() {
    echo $(hostname)
    return 0
}

function echoWhoAmI() {
    echo $(whoami)
    return 0
}
