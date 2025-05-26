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

std::vector<Beverage> getSpecificBeverage(const std::string &filename, BeverageType &type) {
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
        if (currentBeverage.type != type) continue;

        beverages.push_back(currentBeverage);
    }

    file.close();
    return beverages;
}

void writeBeverages(const std::vector<Beverage> &beverages, const std::string &filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    for (auto &beverage : beverages) {
        std::string stringId = std::to_string(beverage.id);
        std::string stringType = std::to_string(beverage.type);
        std::string stringPrice = std::to_string(beverage.pricePerLiter);

        file << stringId << ' ' << stringType << ' ' << beverage.name << ' ' << beverage.color << ' ' << stringPrice;
        file << '\n';
    }

    file.close();
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

void writeDeliveries(const std::vector<Delivery> &deliveries, const std::string &filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    for (auto &delivery : deliveries) {
        std::string stringId = std::to_string(delivery.id);
        std::string stringBevId = std::to_string(delivery.beverageId);
        std::string stringQuantity = std::to_string(delivery.quantityDelivered);

        file << stringId << ' ' << stringBevId << ' ' << stringQuantity << '\n';
    }

    file.close();
}
