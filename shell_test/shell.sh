#!/bin/bash

echo '$0 '$0
echo '$!: '$!
echo '$#: '$#
echo '$*: '"$*"
echo '$@: '"$@"

for i in $*
do
    echo $i
done

for i in $@
do
    echo $i
done