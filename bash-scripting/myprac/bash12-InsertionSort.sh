#!/usr/bin/bash

function insertionSort() {
    array=("$@")
    length=${#array[@]}
    for ((i = 1; i < length; i++)); do
        current=${array[i]}
        j=$((i - 1))
        while [[ $j -ge 0 && ${array[j]} -gt $current ]]; do
            array[j + 1]=${array[j]}
            ((j--))
        done

        ((array[j + 1] = current))

    done
    echo ${array[@]}
}

arr=$(insertionSort 3 5 1 6 7)
echo "$arr"
