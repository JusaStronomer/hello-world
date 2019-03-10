#!/bin/bash

chmod u+x compile.sh;

echo "Running Compile script...";

g++ -c main.cpp;

g++ -Wall -O2 -o main main.o;

echo "Script complete!";