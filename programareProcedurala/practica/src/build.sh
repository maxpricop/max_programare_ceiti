#!/usr/bin/env bash

# exit immediately if any command fails
set -e

# compiler and flags
CXX=g++
CXXFLAGS="-std=c++17 -Wall -Wextra -I."

# the .cpp files you need to compile
SOURCES=(
  main.cpp
  features/beverages/displayBeverages.cpp
  features/beverages/addNewBeverage.cpp
  features/deliveries/displayDeliveries.cpp
  utils/appendLine.cpp
  utils/createRepeatedString.cpp
  utils/getBevreageTypeName.cpp
)

# output binary name
OUT=main

# compile
echo "Compiling ${SOURCES[*]} → $OUT"
$CXX $CXXFLAGS "${SOURCES[@]}" -o $OUT

# run
echo "Running ./$OUT"
./$OUT
