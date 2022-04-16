#!/bin/bash

. ./settings.sh

mkdir ../build
cd ../build
cmake -DCMAKE_BUILD_TYPE=$configuration  ..
make
