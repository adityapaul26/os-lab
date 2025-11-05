#!/usr/bin/bash

echo Enter the first number:
read -r num1

echo Enter the second number:
read -r num2

if [[ $num1 -gt $num2 ]]; then
    echo num1 i greater
elif [[ $num1 -eq $num2 ]]; then
    echo num1 and num2 are equal
else
    echo num2 is greater
fi