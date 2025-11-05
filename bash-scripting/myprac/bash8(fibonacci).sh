#!/usr/bin/bash

#fibonacci numbers 
# 0 1 1 2 3 5 8 13 ...

echo enter a number:
read -r num
l=0
b=1
count=0
echo -n "$l $b "
while [[ count -le num ]]; do
    new=$((l+b))
    echo -n "$new "
    l=$b
    b=$new
    ((count++))
done
