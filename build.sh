#!/bin/bash

export MSXLIB_DIR=$(pwd)

pushd src
make "$@"
if [ $? -ne 0 ]; then
    exit
fi
popd

pushd tests
make "$@"
if [ $? -ne 0 ]; then
    exit
fi
popd

pushd sample
make "$@"
if [ $? -ne 0 ]; then
    exit
fi
popd
