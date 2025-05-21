#include "files.hpp"
#include "../types/Beverages.hpp"
#include "../types/Delivery.hpp"
#include "fstream"
#include "iostream"
#include "string"
#include "vector"

void appendLine(const std::vector<std::string> &elements, const std::string &filename) {
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    bool firstElement = true; // To prevent writing a space at the beginning of the document
    for (const auto &element : elements) {
        if (!firstElement) file << ' ';
        else firstElement = false;

        file << element;
    }

    file << '\n';
    file.close();
};

std::vector<std::string> readAllLines(const std::string &filename) {
    std::ifstream file(filename);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

void writeAllLines(const std::vector<std::string> &lines, const std::string &filename) {
    std::ofstream file(filename);

    for (auto &line : lines) {
        file << line << '\n';
    }

    file.close();
}

std::vector<Beverage> getAllBeverages(const std::string &filename) {
    std::vector<Beverage> beverages;
    std::ifstream file(filename);

    if (!file.is_open()) return beverages;

    Beverage currentBeverage;

    // Expected line layout:
    // ID (unsigned), Type (BeverageType), name (string), color (string), pricePerLiter (float)
    while (file >> currentBeverage.id) {
        int rawBeverageType;
        file >> rawBeverageType >> currentBeverage.name >> currentBeverage.color >> currentBeverage.pricePerLiter;

        currentBeverage.type = static_cast<BeverageType>(rawBeverageType);
        beverages.push_back(currentBeverage);
    }

    file.close();
    return beverages;
}

std::vector<Delivery> getAllDeliveries(const std::string &filename) {
    std::vector<Delivery> deliveries;
    std::ifstream file(filename);

    if (!file.is_open()) return deliveries;

    Delivery currentDelivery;

    // Expected line layout:
    // ID (unsigned), Beverage ID (unsigned), Quantity Delivered (double)
    while (file >> currentDelivery.id) {
        file >> currentDelivery.beverageId >> currentDelivery.quantityDelivered;
        deliveries.push_back(currentDelivery);
    }

    file.close();
    return deliveries;
}
