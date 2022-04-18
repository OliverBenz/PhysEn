#!/bin/bash

. ./settings.sh

mkdir ../build
cd ../build
echo "Using configuration: $configuration"
cmake -DCMAKE_BUILD_TYPE=$configuration -DBUILD_TESTS=$buildTests -DBUILD_EXAMPLES=$buildExamples ..
make
