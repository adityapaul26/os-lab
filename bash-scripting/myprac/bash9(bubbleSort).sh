#!/usr/bin/bash

#bubble sort

array=(21 3 57 90 12)

for((i=0;i<5;i++));do
    for((j=0;j<$((5-i-1));j++));do
        if [[ ${array[j]} -gt ${array[j+1]} ]]; then
            temp=${array[j]}
            array[j]=${array[j+1]}
            array[j+1]=$temp
        fi
    done
done

echo "${array[*]}"