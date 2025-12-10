#!/usr/bin/bash

function mul() {
    local pdt=1
    for num in "$@"; do
        ((pdt = pdt * num))
    done
    echo $pdt
}

a=$(mul 2 3 4)
echo $a
