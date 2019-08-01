#!/bin/bash

IFSOLD=$IFS
IFS='\n'
for entry in $(cat /etc/passwd)
do
    echo "Values in $entry - "
    IFS=:
    for value in $entry
    do
        echo "  $value"
    done
done
IFS=${IFSOLD}
