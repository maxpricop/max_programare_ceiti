#include "../../types/Beverages.hpp"
#include "../../types/Delivery.hpp"
#include "../../utils/files.hpp"
#include "beverages.hpp"
#include "iostream"
#include "string"
#include "vector"

void displayAveragePriceForQuantity(const std::string &beverageFile, const std::string &deliveryFile) {
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

    double minQuantity;
    std::cout << "Introdu cantitatea minimă livrată (litri): ";
    std::cin >> minQuantity;

    // Holds the total quantity of all beverages. beverages[i] corresponds to totalQuantity[i]
    std::vector<double> totalQuantity;
    totalQuantity.reserve(beverages.size());

    for (const auto &beverage : beverages) {
        double quantity = 0.0;

        for (const auto &delivery : deliveries) {
            if (beverage.id != delivery.beverageId) continue;

            quantity += delivery.quantityDelivered;
        }

        totalQuantity.push_back(quantity);
    }

    double sumPrices = 0.0;
    unsigned count = 0;

    // Pointer to the totalQuantity vector
    auto quantityPointer = totalQuantity.begin();

    for (const auto &bev : beverages) {
        // After every iteration, increase the pointer so that it now points to the next element in the vector
        double quantity = *quantityPointer++;

        if (quantity <= minQuantity) continue;

        sumPrices += bev.pricePerLiter;
        ++count;
    }

    if (count == 0) {
        std::cout << "Nicio băutură nu are livrări ≥ " << minQuantity << " litri.\n";
        return;
    }

    double averagePrice = sumPrices / count;
    std::cout << "Media pretului pe litru a bauturilor cu livrari ≥ " << minQuantity << "L este: " << averagePrice
              << " lei/L\n";
}
