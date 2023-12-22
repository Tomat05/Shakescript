#!/bin/bash

gcc $1 -o ./bin/$2


if [ $# -eq 2 ]
then
    if [ $3 == "run" ]
    then
        echo $(./bin/$2)
    fi
fi