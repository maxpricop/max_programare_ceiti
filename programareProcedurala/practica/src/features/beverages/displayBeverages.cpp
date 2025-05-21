#include "../../types/Beverages.hpp"
#include "../../utils/createRepeatedString.hpp"
#include "../../utils/files.hpp"
#include "beverages.hpp"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "string"
#include "utils/getBevreageTypeName.hpp"
#include "vector"

void displayBeverages(const std::string &filename) {
    std::vector<Beverage> beverageList = getAllBeverages(filename);

    if (beverageList.empty()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    // Column widths
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
    for (const auto &bev : beverageList) {
        std::cout << std::left << "║" << std::setw(wId) << bev.id << "║" << std::setw(wName) << bev.name << "║"
                  << std::setw(wType) << getBeverageTypeName(bev.type) << "║" << std::setw(wColor) << bev.color << "║"
                  << std::setw(wPrice) << bev.pricePerLiter << "║\n";
    }

    // End of table
    std::cout << createRepeatedString("╚", "═", wId, "╩") << createRepeatedString("═", "═", wName - 1, "╩")
              << createRepeatedString("═", "═", wType - 1, "╩") << createRepeatedString("═", "═", wColor - 1, "╩")
              << createRepeatedString("═", "═", wPrice - 1, "╝\n");
};