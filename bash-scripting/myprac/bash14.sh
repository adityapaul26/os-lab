#!/usr/bin/bash

#     1
#    23
#   456
#  78910
count=1
for ((i = 0; i < 5; i++)); do
    for ((s = 5 - 1; s >= i; s--)); do
        echo -n " "
    done
    for ((j = i; j >= 0; j--)); do
        echo -n "$count "
        ((count++))
    done
    echo ""
done
