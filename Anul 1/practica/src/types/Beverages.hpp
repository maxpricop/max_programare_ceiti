#pragma once
#include "string"

enum BeverageType {
    Sweet,
    Mineral,
    Juice,
    Syrup
};

struct Beverage {
    unsigned id;
    BeverageType type;
    std::string name;
    std::string color;
    float pricePerLiter;
};
