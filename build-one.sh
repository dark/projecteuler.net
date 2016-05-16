#!/bin/bash

function err() {
    echo -en "\e[91m"
    echo -n "$@"
    echo -e "\e[39m"
}

function log() {
    echo -en "\e[92m"
    echo -n "$@"
    echo -e "\e[39m"
}

function tryexec() {
    $@
    local status=$?
    if [[ $status -eq 0 ]]; then
	return
    fi
    err "Command failed: $@"
    err "Exit status: $status"
    exit $status
}

pushd $1

# build and run C solutions
if ls *.c &> /dev/null;then
    log "Building C solution for problem $1 ..."
    tryexec gcc -Wall *.c -o "${1}.bin"
    log "Running executable..."
    tryexec "./${1}.bin"
    log "All done."
    exit 0
fi

# build and run C++ solutions
if ls *.cc &> /dev/null;then
    log "Building C++ solution for problem $1 ..."
    tryexec gcc -std=c++11 -Wall *.cc -o "${1}.bin"
    log "Running executable..."
    tryexec "./${1}.bin"
    log "All done."
    exit 0
fi

err "I don't know how to build the solution for problem $1"
exit 1
