#pragma once
#include "string"

void displayBeverages(const std::string &filename);

void addNewBeverage(const std::string &filename);

void deleteBeverage(const std::string &filename);

void editBeverage(const std::string &filename);

void displaySpecificBeverage(const std::string &filename);

void displayBeverageValueExtremes(const std::string &beverageFile, const std::string &deliveryFile);

void displayAveragePriceForQuantity(const std::string &beverageFile, const std::string &deliveryFile);
