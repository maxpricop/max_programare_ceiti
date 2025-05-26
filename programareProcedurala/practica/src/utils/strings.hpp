#pragma once
#include "../types/Beverages.hpp"
#include "../types/Delivery.hpp"
#include "string"

std::string createRepeatedString(const std::string lineStart, const std::string repeatedString, const unsigned length,
                                 const std::string lineEnd);

std::string beverageToString(const Beverage &beverage);

std::string deliveryToString(const Delivery &delivery);
