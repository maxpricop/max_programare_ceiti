#include "../../types/Beverages.hpp"
#include "../../utils/files.hpp"
#include "../../utils/strings.hpp"
#include "./utils/getBevreageTypeName.hpp"
#include "beverages.hpp"
#include "iomanip"
#include "iostream"
#include "string"
#include "vector"

// Sort beverage vector using insertion sort alphabetically
void sortByName(std::vector<Beverage> &vector) {
    for (unsigned i = 1; i < vector.size(); ++i) {
        Beverage key = vector[i];

        unsigned j = i;
        while (j > 0 && vector[j - 1].name > key.name) {
            vector[j] = vector[j - 1];
            --j;
        }

        vector[j] = key;
    }
}

void displaySpecificBeverage(const std::string &filename) {
    int rawBeverageType;
    std::cout << "Introdu tipul de bauturi ce sa fie afisate (0=Apa dulce,1=Minerala,2=Suc,3=Sirop): ";
    std::cin >> rawBeverageType;

    BeverageType beverageType = static_cast<BeverageType>(rawBeverageType);
    std::vector<Beverage> beverages = getSpecificBeverage(filename, beverageType);

    if (beverages.empty()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    sortByName(beverages);

    const int wId = 6;
    const int wName = 25;
    const int wType = 17;
    const int wColor = 17;
    const int wPrice = 6;

    // Top of the table
    std::cout << createRepeatedString("╔", "═", wId, "╦") << createRepeatedString("═", "═", wName - 1, "╦")
              << createRepeatedString("═", "═", wType - 1, "╦") << createRepeatedString("═", "═", wColor - 1, "╦")
              << createRepeatedString("═", "═", wPrice - 1, "╗\n");

    // Line displaying all table columns
    std::cout << std::left << "║" << std::setw(wId) << "ID" << "║" << std::setw(wName) << "Nume" << "║"
              << std::setw(wType) << "Tip" << "║" << std::setw(wColor) << "Culoare" << "║" << std::setw(wPrice)
              << "Pret/L" << "║\n";

    // Divider between table header and data
    std::cout << createRepeatedString("╠", "═", wId, "╬") << createRepeatedString("═", "═", wName - 1, "╬")
              << createRepeatedString("═", "═", wType - 1, "╬") << createRepeatedString("═", "═", wColor - 1, "╬")
              << createRepeatedString("═", "═", wPrice - 1, "╣\n");

    // Display table data, information about all beverages
    for (const auto &bev : beverages) {
        std::cout << std::left << "║" << std::setw(wId) << bev.id << "║" << std::setw(wName) << bev.name << "║"
                  << std::setw(wType) << getBeverageTypeName(bev.type) << "║" << std::setw(wColor) << bev.color << "║"
                  << std::setw(wPrice) << bev.pricePerLiter << "║\n";
    }

    // End of table
    std::cout << createRepeatedString("╚", "═", wId, "╩") << createRepeatedString("═", "═", wName - 1, "╩")
              << createRepeatedString("═", "═", wType - 1, "╩") << createRepeatedString("═", "═", wColor - 1, "╩")
              << createRepeatedString("═", "═", wPrice - 1, "╝\n");
}