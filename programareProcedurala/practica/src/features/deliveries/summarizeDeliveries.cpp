#include "../../types/Beverages.hpp"
#include "../../types/Delivery.hpp"
#include "../../utils/files.hpp"
#include "deliveries.hpp"
#include "fstream"
#include "iostream"
#include "string"

struct Summary {
    std::string name;
    double quantityDelivered;
    double value;
};

void summarizeDeliveries(const std::string &beverageFile, const std::string &deliveryFile, const std::string &outFile) {
    std::vector<Beverage> beverages = getAllBeverages(beverageFile);
    std::vector<Delivery> deliveries = getAllDeliveries(deliveryFile);

    std::vector<Summary> summaries;

    for (const auto &beverage : beverages) {
        Summary newSummary{name : beverage.name, quantityDelivered : 0, value : 0};

        for (const auto &delivery : deliveries) {
            if (delivery.beverageId != beverage.id) continue;

            newSummary.quantityDelivered += delivery.quantityDelivered;
        }

        newSummary.value = newSummary.quantityDelivered * beverage.pricePerLiter;

        summaries.push_back(newSummary);
    }

    std::ofstream summaryFile(outFile);

    if (!summaryFile.is_open()) {
        std::cerr << "Error: cannot open file \"" << outFile << "\"\n";
        return;
    }

    for (const auto &summary : summaries) {
        summaryFile << summary.name << ' ' << std::to_string(summary.quantityDelivered) << ' '
                    << std::to_string(summary.value) << '\n';
    }

    std::cout << "Creat rezumatul livrarilor in fisierul \"" << outFile << "\"\n";
}