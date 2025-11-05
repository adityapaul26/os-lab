#!/usr/bin/bash

echo Enter two numbers:
read -r num1
read -r num2

sum=$((num1+num2)) #or 
sum2=$(expr $num1 + $num2)


echo The sum is: $sum
echo The sum is: $sum2