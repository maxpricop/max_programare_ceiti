#include "../../types/Beverages.hpp"
#include "../../utils/files.hpp"
#include "../../utils/strings.hpp"
#include "beverages.hpp"
#include "iostream"
#include "string"
#include "vector"

void editBeverage(const std::string &filename) {
    unsigned id;

    std::cout << "Introdu ID-ul bauturii pe care vrei sa o editezi: ";
    std::cin >> id;

    std::vector<Beverage> beverages = getAllBeverages(filename);

    for (auto &beverage : beverages) {
        if (beverage.id != id) continue;

        std::cout << "Bautura originala: " + beverageToString(beverage) + '\n';
        std::cout << '\n';

        std::cout << "Modifica ID-ul bauturii: ";
        std::cin >> beverage.id;

        int rawBeverageType;
        std::cout << "Modifica tipul bauturii(0=Apa dulce,1=Minerala,2=Suc,3=Sirop): ";
        std::cin >> rawBeverageType;
        beverage.type = static_cast<BeverageType>(rawBeverageType);

        std::cout << "Modifica numele bauturii: ";
        std::cin >> beverage.name;

        std::cout << "Modifica culoarea bauturii: ";
        std::cin >> beverage.color;

        std::cout << "Modifica pretul pe litru al bauturii: ";
        std::cin >> beverage.pricePerLiter;

        writeBeverages(beverages, filename);
        return;
    }

    std::cout << "Nu a fost gasita nici o bautura cu ID-ul '" << id << "'.\n";
}