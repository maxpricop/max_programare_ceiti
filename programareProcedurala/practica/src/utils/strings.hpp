#pragma once
#include "../types/Beverages.hpp"
#include "../types/Delivery.hpp"
#include "string"

std::string createRepeatedString(std::string lineStart, std::string repeatedString, unsigned length,
                                 std::string lineEnd);

std::string beverageToString(const Beverage &beverage);

std::string deliveryToString(const Delivery &delivery);
