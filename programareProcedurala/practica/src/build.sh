#!/usr/bin/env bash

# exit immediately if any command fails
set -e

# compiler and flags
CXX=g++
CXXFLAGS="-std=c++23 -Wall -Wextra -I."

# the .cpp files you need to compile
SOURCES=(
  main.cpp
  features/beverages/displayBeverages.cpp
  features/beverages/addNewBeverage.cpp
  features/beverages/deleteBeverage.cpp
  features/deliveries/displayDeliveries.cpp
  features/deliveries/addNewDelivery.cpp
  features/deliveries/deleteDelivery.cpp
  utils/files.cpp
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
