#!/usr/bin/env bash

# exit immediately if any command fails
set -e

# compiler and flags
CXX=g++
CXXFLAGS="-std=c++23 -Wall -Wextra -I."

# the .cpp files you need to compile
SOURCES=(
  main.cpp
  features/beverages/utils/getBevreageTypeName.cpp
  features/beverages/displayBeverages.cpp
  features/beverages/addNewBeverage.cpp
  features/beverages/deleteBeverage.cpp
  features/beverages/editBeverage.cpp
  features/deliveries/displayDeliveries.cpp
  features/deliveries/addNewDelivery.cpp
  features/deliveries/deleteDelivery.cpp
  features/deliveries/editDelivery.cpp
  features/deliveries/summarizeDeliveries.cpp
  utils/strings.cpp
  utils/files.cpp
  utils/findItemById.cpp
)

# output binary name
OUT=main

# compile
echo "Compiling ${SOURCES[*]} → $OUT"
$CXX $CXXFLAGS "${SOURCES[@]}" -o $OUT

# run
echo "Running ./$OUT"
./$OUT
