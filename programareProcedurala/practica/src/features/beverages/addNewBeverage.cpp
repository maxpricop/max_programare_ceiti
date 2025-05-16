#include "addNewBeverage.hpp"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "string"
#include "types/Beverages.hpp"
#include "utils/appendLine.hpp"

void addNewBeverage(const std::string &filename) {
    Beverage bev{};
    int rawBeverageType;

    std::cout << "Introduceti ID bautura: ";
    std::cin >> bev.id;

    std::cout << "Introduceti tip bautura (0=Apa dulce,1=Minerala,2=Suc,3=Sirop): ";
    std::cin >> rawBeverageType;
    bev.type = static_cast<BeverageType>(rawBeverageType);

    std::cout << "Introduceti numele bauturii: ";
    std::cin >> bev.name;

    std::cout << "Introduceti culoarea bauturii: ";
    std::cin >> bev.color;

    std::cout << "Introduceti pretul pe litru: ";
    std::cin >> bev.pricePerLiter;

    appendLine(
        {std::to_string(bev.id), std::to_string(bev.type), bev.name, bev.color, std::to_string(bev.pricePerLiter)},
        filename);
};
