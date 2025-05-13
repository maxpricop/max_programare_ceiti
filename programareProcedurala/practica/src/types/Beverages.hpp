#ifndef BeveragesHpp
#define BeveragesHpp

#include "string"

enum BeverageType {
    Sweet,
    Mineral,
    Juice,
    Syrup
};

struct Bevreage {
    unsigned id;
    BeverageType type;
    std::string name;
    std::string color;
    double pricePerLiter;
};

#endif