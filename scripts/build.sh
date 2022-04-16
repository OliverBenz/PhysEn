#!/bin/bash

. ./settings.sh

mkdir ../build
cd ../build
echo "Using configuration: $configuration"
cmake -DCMAKE_BUILD_TYPE=$configuration ..
make
