#include "strings.hpp"
#include "../types/Beverages.hpp"
#include "../types/Delivery.hpp"
#include "string"

std::string createRepeatedString(std::string lineStart, std::string repeatedString, unsigned length,
                                 std::string lineEnd) {
    std::string line = lineStart;

    for (unsigned i = 0; i < length; i++) {
        line += repeatedString;
    }

    return line + lineEnd;
}

std::string beverageToString(const Beverage &beverage) {
    return std::to_string(beverage.id) + ' ' + std::to_string(beverage.type) + ' ' + beverage.name + ' ' +
           beverage.color + ' ' + std::to_string(beverage.pricePerLiter);
};

std::string deliveryToString(const Delivery &delivery) {
    return std::to_string(delivery.id) + ' ' + std::to_string(delivery.beverageId) + ' ' +
           std::to_string(delivery.quantityDelivered);
}