#!/bin/bash

gcc ./src/$1 -o ./bin/$2


if [ $# -eq 3 ]
then
    echo $(./bin/$2 $3)
fi