#include "../../types/Beverages.hpp"
#include "../../types/Delivery.hpp"
#include "../../utils/files.hpp"
#include "../../utils/strings.hpp"
#include "./utils/getBevreageTypeName.hpp"
#include "beverages.hpp"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "string"

void displayBeverageValueExtremes(const std::string &beverageFile, const std::string &deliveryFile) {
    std::vector<Beverage> beverages = getAllBeverages(beverageFile);
    std::vector<Delivery> deliveries = getAllDeliveries(deliveryFile);

    if (beverages.empty()) {
        std::cerr << "Error: cannot open file \"" << beverageFile << "\"\n";
        return;
    }

    if (deliveries.empty()) {
        std::cerr << "Error: cannot open file \"" << deliveryFile << "\"\n";
        return;
    }

    Beverage highestValueBeverage = beverages[0];
    double higestValue = 0;

    Beverage lowestValueBeverage = beverages[0];
    double lowestValue = 10000;

    for (const auto &beverage : beverages) {
        double quantityDelivered = 0;

        for (const auto &delivery : deliveries) {
            if (delivery.beverageId != beverage.id) continue;

            quantityDelivered += delivery.quantityDelivered;
        }

        double value = quantityDelivered * beverage.pricePerLiter;

        if (value > higestValue) {
            higestValue = value;
            highestValueBeverage = beverage;
        }

        if (value < lowestValue) {
            lowestValue = value;
            lowestValueBeverage = beverage;
        }
    }

    const int wId = 6;
    const int wName = 25;
    const int wType = 17;
    const int wColor = 17;
    const int wPrice = 6;
    const int wValue = 10;

    // Top of the table
    std::cout << createRepeatedString("╔", "═", wId, "╦") << createRepeatedString("═", "═", wName - 1, "╦")
              << createRepeatedString("═", "═", wType - 1, "╦") << createRepeatedString("═", "═", wColor - 1, "╦")
              << createRepeatedString("═", "═", wPrice - 1, "╦") << createRepeatedString("═", "═", wValue - 1, "╗\n");

    // Line displaying all table columns
    std::cout << std::left << "║" << std::setw(wId) << "ID" << "║" << std::setw(wName) << "Nume" << "║"
              << std::setw(wType) << "Tip" << "║" << std::setw(wColor) << "Culoare" << "║" << std::setw(wPrice)
              << "Pret/L" << "║" << std::setw(wValue) << "Valoare" << "║\n";

    // Divider between table header and data
    std::cout << createRepeatedString("╠", "═", wId, "╬") << createRepeatedString("═", "═", wName - 1, "╬")
              << createRepeatedString("═", "═", wType - 1, "╬") << createRepeatedString("═", "═", wColor - 1, "╬")
              << createRepeatedString("═", "═", wPrice - 1, "╬") << createRepeatedString("═", "═", wValue - 1, "╣\n");

    std::cout << std::left << "║" << std::setw(wId) << highestValueBeverage.id << "║" << std::setw(wName)
              << highestValueBeverage.name << "║" << std::setw(wType) << getBeverageTypeName(highestValueBeverage.type)
              << "║" << std::setw(wColor) << highestValueBeverage.color << "║" << std::setw(wPrice)
              << highestValueBeverage.pricePerLiter << "║" << std::setw(wValue) << higestValue << "║\n";

    std::cout << std::left << "║" << std::setw(wId) << lowestValueBeverage.id << "║" << std::setw(wName)
              << lowestValueBeverage.name << "║" << std::setw(wType) << getBeverageTypeName(lowestValueBeverage.type)
              << "║" << std::setw(wColor) << lowestValueBeverage.color << "║" << std::setw(wPrice)
              << lowestValueBeverage.pricePerLiter << "║" << std::setw(wValue) << lowestValue << "║\n";

    // End of table
    std::cout << createRepeatedString("╚", "═", wId, "╩") << createRepeatedString("═", "═", wName - 1, "╩")
              << createRepeatedString("═", "═", wType - 1, "╩") << createRepeatedString("═", "═", wColor - 1, "╩")
              << createRepeatedString("═", "═", wPrice - 1, "╩") << createRepeatedString("═", "═", wValue - 1, "╝\n");
}
