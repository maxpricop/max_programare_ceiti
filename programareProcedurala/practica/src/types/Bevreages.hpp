#ifndef Bevreages
#define Bevreages

#include "string"

enum BevreageType {
    Sweet,
    Mineral,
    Juice,
    Syrup
};

struct Bevreage {
    unsigned id;
    BevreageType type;
    std::string name;
    std::string color;
    double pricePerLiter;
};

#endif