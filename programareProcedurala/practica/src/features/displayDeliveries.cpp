#include "displayDeliveries.hpp"
#include "../types/Delivery.hpp"
#include "../utils/createRepeatedString.hpp"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "string"
#include "vector"

void displayDeliveries(const std::string &filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    std::vector<Delivery> deliveriesList;
    Delivery currentDelivery;

    // Expected line layout:
    // ID (unsigned), Beverage ID (unsigned), Quantity Delivered (double)
    while (file >> currentDelivery.id) {
        file >> currentDelivery.beverageId >> currentDelivery.quantityDelivered;
        deliveriesList.push_back(currentDelivery);
    }

    // Column widths
    const unsigned wId = 6;
    const unsigned wBeverageId = 12;
    const unsigned wQuantity = 18;

    // Top of the table
    std::cout << createRepeatedString("╔", "═", wId, "╦") << createRepeatedString("═", "═", wBeverageId - 1, "╦")
              << createRepeatedString("═", "═", wQuantity - 1, "╗\n");

    // Line displaying all table columns
    std::cout << std::left << "║" << std::setw(wId) << "ID" << "║" << std::setw(wBeverageId) << "ID Bautura"
              << "║" << std::setw(wQuantity) << "Cantitate livrata" << "║\n";

    // Divider between table header and data
    std::cout << createRepeatedString("╠", "═", wId, "╬") << createRepeatedString("═", "═", wBeverageId - 1, "╬")
              << createRepeatedString("═", "═", wQuantity - 1, "╣\n");

    // Display table data, information about all deliveries
    for (const auto &delivery : deliveriesList) {
        std::cout << std::left << "║" << std::setw(wId) << delivery.id << "║" << std::setw(wBeverageId)
                  << delivery.beverageId << "║" << std::setw(wQuantity) << delivery.quantityDelivered << "║\n";
    }

    // End of table
    std::cout << createRepeatedString("╚", "═", wId, "╩") << createRepeatedString("═", "═", wBeverageId - 1, "╩")
              << createRepeatedString("═", "═", wQuantity - 1, "╝\n");
};