#!/bin/sh

#跟踪所有命令
set -x

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-../build}

mkdir -p $BUILD_DIR \
  && cd $BUILD_DIR \
  && cmake $SOURCE_DIR \
  && make $*

#可以传参数
#./build.sh clean