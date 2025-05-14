#include "displayDeliveries.hpp"
#include "../types/Delivery.hpp"
#include "fstream"
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

    for (const Delivery &delivery : deliveriesList) {
        std::cout << delivery.id << "\t" << delivery.beverageId << "\t" << delivery.quantityDelivered << "\n";
    }
};