#!/bin/bash

echo "$0 run with $# args:"
for (( i = 1; i <= $#; i++ ))
do
    echo ${!i}
done

echo "\$* $*"
echo "iterate \$@"
for arg in $@
do
    echo $arg
done

echo "shift args"
count=1
while [ -n "$1" ]
do
    echo "Parameter #$count = $1"
    count=$[ $count + 1 ]
    shift
done
