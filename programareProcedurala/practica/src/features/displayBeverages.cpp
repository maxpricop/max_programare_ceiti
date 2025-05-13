#include "displayBeverages.hpp"
#include "../types/Beverages.hpp"
#include "../utils/getBevreageTypeName.cpp"
#include "fstream"
#include "iostream"
#include "string"
#include "vector"

void displayBeverages(const std::string &filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    std::vector<Beverage> beverageList;
    Beverage currentBeverage;

    // Expected line layout: ID (unsigned), Type (BeverageType), name (string), color (string), pricePerLiter
    // (double)
    while (file >> currentBeverage.id) {
        int rawBeverageType;
        file >> rawBeverageType >> currentBeverage.name >> currentBeverage.color >> currentBeverage.pricePerLiter;

        currentBeverage.type = static_cast<BeverageType>(rawBeverageType);
        beverageList.push_back(currentBeverage);
    }

    for (const auto &bev : beverageList) {
        std::cout << bev.id << getBeverageTypeName(bev.type) << bev.name << bev.color << bev.pricePerLiter << "\n";
    }
};