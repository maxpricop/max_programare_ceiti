#include "../../types/Beverages.hpp"
#include "../../utils/files.hpp"
#include "beverages.hpp"
#include "iostream"
#include "string"

void addNewBeverage(const std::string &filename) {
    Beverage newBeverage{};
    int rawBeverageType;

    std::cout << "Introduceti ID bautura: ";
    std::cin >> newBeverage.id;

    std::cout << "Introduceti tip bautura (0=Apa dulce,1=Minerala,2=Suc,3=Sirop): ";
    std::cin >> rawBeverageType;
    newBeverage.type = static_cast<BeverageType>(rawBeverageType);

    std::cout << "Introduceti numele bauturii: ";
    std::cin >> newBeverage.name;

    std::cout << "Introduceti culoarea bauturii: ";
    std::cin >> newBeverage.color;

    std::cout << "Introduceti pretul pe litru: ";
    std::cin >> newBeverage.pricePerLiter;

    appendLine({std::to_string(newBeverage.id), std::to_string(newBeverage.type), newBeverage.name, newBeverage.color,
                std::to_string(newBeverage.pricePerLiter)},
               filename);
};
