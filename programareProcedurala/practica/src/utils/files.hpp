#pragma once
#include "../types/Beverages.hpp"
#include "../types/Delivery.hpp"
#include "string"
#include "vector"

std::vector<Beverage> getAllBeverages(const std::string &filename);

std::vector<Beverage> getSpecificBeverage(const std::string &filename, BeverageType &type);

void writeBeverages(const std::vector<Beverage> &beverages, const std::string &filename);

std::vector<Delivery> getAllDeliveries(const std::string &filename);

void writeDeliveries(const std::vector<Delivery> &deliveries, const std::string &filename);
