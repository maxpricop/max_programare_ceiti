#include "../types/Beverages.hpp"
#include "../utils/files.hpp"
#include "../utils/findItemById.hpp"
#include "beverages.hpp"
#include "iostream"
#include "string"
#include "vector"

void editBeverage(const std::string &filename) {
    unsigned id;

    std::cout << "Introdu ID-ul bauturii pe care vrei sa o editezi: ";
    std::cin >> id;

    std::vector<std::string> beverages = readAllLines(filename);

    for (auto &beverage : beverages) {
        if (findItemById(beverage) != id) continue;

        std::cout << "Bautura originala: " + beverage + '\n';
        std::cout << '\n';

        unsigned newId;
        int rawBeverageType;
        BeverageType beverageType;
        std::string newName;
        std::string newColor;
        float pricePerLiter;

        std::cout << "Modifica ID-ul bauturii: ";
        std::cin >> newId;

        std::cout << "Modifica tipul bauturii(0=Apa dulce,1=Minerala,2=Suc,3=Sirop): ";
        std::cin >> rawBeverageType;
        beverageType = static_cast<BeverageType>(rawBeverageType);

        std::cout << "Modifica numele bauturii: ";
        std::cin >> newName;

        std::cout << "Modifica culoarea bauturii: ";
        std::cin >> newColor;

        std::cout << "Modifica pretul pe litru al bauturii: ";
        std::cin >> pricePerLiter;

        beverage = std::to_string(newId) + ' ' + std::to_string(beverageType) + ' ' + newName + ' ' + newColor + ' ' +
                   std::to_string(pricePerLiter);

        writeAllLines(beverages, filename);
        return;
    }

    std::cout << "Nu a fost gasita nici o bautura cu ID-ul '" << id << "'.\n";
}