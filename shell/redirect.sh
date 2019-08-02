#!/bin/bash

exec 2>"test.error"
exec 1>"test.out"
echo "This is a test of redirecting all out"
echo "from a script to another file."

exec 3>testout
exec 0< testfile
count=1
while read line
do
    echo "Line #$count: $line" >&3
    count=$[ $count + 1 ]
done

# close fd 3
exec 3>&-


