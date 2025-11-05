#!/usr/bin/bash

#****
# ***
#  **
#   *

for((i=0;i<4;i++));do
    for((s=0;s<i;s++));do
        echo -n " " # only echo also prints a newline character at the end| putting a -n flag causes it not to put a newline
    done
    for((k=4;k>i;k--));do
        echo -n "*"
    done
    echo ""
done