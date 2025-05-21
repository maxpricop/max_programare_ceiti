#include "../../types/Beverages.hpp"
#include "../../utils/files.hpp"
#include "beverages.hpp"
#include "iostream"
#include "string"

void deleteBeverage(const std::string &filename) {
    std::string name;

    std::cout << "Introdu numele bauturii pe care vrei sa o stergi: ";
    std::cin >> name;

    std::vector<Beverage> beverageList = getAllBeverages(filename);

    if (beverageList.empty()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    auto it = std::find_if(beverageList.begin(), beverageList.end(), [&](const Beverage &b) { return b.name == name; });

    if (it == beverageList.end()) {
        std::cout << "Nu exista nici o bautura cu numele \"" << name << "\"\n";
        return;
    }

    beverageList.erase(it);
    std::cout << "Sters bautura cu numele \"" << name << "\"\n";

    writeBeverages(beverageList, filename);
}