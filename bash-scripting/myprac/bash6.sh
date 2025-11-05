#!/usr/bin/bash

echo enter a number:
read -r num

if [[ $((num % 2)) -eq 0 ]]; then
    echo the number is even.
else
    echo the number is odd.
fi