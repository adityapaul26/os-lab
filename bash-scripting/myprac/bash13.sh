#!/usr/bin/bash

#    *
#   **
#  ***
# ****
#*****

for ((i = 0; i < 5; i++)); do
    for ((s = 5 - 1; s >= i; s--)); do
        echo -n " "
    done
    for ((j = i; j >= 0; j--)); do
        echo -n "*"
    done
    echo ""
done
