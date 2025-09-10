#include "getBevreageTypeName.hpp"
#include "../../../types/Beverages.hpp"
#include "string"

std::string getBeverageTypeName(BeverageType type) {
    switch (type) {
        case Sweet: {
            return "Apa dulce";
        }
        case Mineral: {
            return "Apa minerala";
        }
        case Juice: {
            return "Suc";
        }
        case Syrup: {
            return "Sirop";
        }
        default: {
            return "Unknown";
        }
    }
}