#!/usr/bin/env bash

clear;

mkdir -p build
cd build

# generate cmake project in the "build" folder

echo
echo "-------------------------------------------------------"
debugCmd=""
if [ "$1" = "debug" ] || [ "$2" = "debug" ]
then
    debugCmd="-DMY_DEBUG=ON"; 
    echo "debug mode"
else
    debugCmd="-DMY_DEBUG=OFF"
    echo "release mode"
fi
echo "-------------------------------------------------------"

echo
echo
cmake $debugCmd .. || exit 1
echo 
echo 

# build it
make || exit 1
echo 
echo 

# move to working data folder with resources
cd ../data/

if [ "$1" = "run" ] || [ "$2" = "run" ]
then
    ../build/hello
else
    exit 0;
fi
