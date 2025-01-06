#!/bin/bash

pushd src
make "$@"
popd

pushd tests
make "$@"
popd

pushd sample
make "$@"
popd

#pushd tests
#make tests
#popd
