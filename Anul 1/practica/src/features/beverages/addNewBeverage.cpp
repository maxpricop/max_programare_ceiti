#include "../../types/Beverages.hpp"
#include "../../utils/files.hpp"
#include "../../utils/strings.hpp"
#include "beverages.hpp"
#include "fstream"
#include "iostream"
#include "string"

void addNewBeverage(const std::string &filename) {
    std::vector<Beverage> beverages = getAllBeverages(filename);
    Beverage newBeverage{};

    std::cout << "Introduceti ID bautura: ";
    std::cin >> newBeverage.id;

    for (const auto &beverage : beverages) {
        if (beverage.id != newBeverage.id) continue;

        std::cout << "Deja exista o bautura cu acest ID.\n";
        return;
    }

    int rawBeverageType;
    std::cout << "Introduceti tip bautura (0=Apa dulce,1=Minerala,2=Suc,3=Sirop): ";
    std::cin >> rawBeverageType;
    newBeverage.type = static_cast<BeverageType>(rawBeverageType);

    std::cout << "Introduceti numele bauturii: ";
    std::cin >> newBeverage.name;

    std::cout << "Introduceti culoarea bauturii: ";
    std::cin >> newBeverage.color;

    std::cout << "Introduceti pretul pe litru: ";
    std::cin >> newBeverage.pricePerLiter;

    std::string beverage = beverageToString(newBeverage);
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    file << beverage << '\n';
    file.close();

    std::cout << "Creat cu succes o noua bautura.\n";
};
