#pragma once
#include "../types/Beverages.hpp"
#include "../types/Delivery.hpp"
#include "string"
#include "vector"

void appendLine(const std::vector<std::string> &elements, const std::string &filename);

std::vector<std::string> readAllLines(const std::string &filename);

void writeAllLines(const std::vector<std::string> &lines, const std::string &filename);

std::vector<Beverage> getAllBeverages(const std::string &filename);

std::vector<Delivery> getAllDeliveries(const std::string &filename);
