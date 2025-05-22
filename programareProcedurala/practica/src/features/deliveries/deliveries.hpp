#pragma once
#include "string"

void displayDeliveries(const std::string &filename);

void addNewDelivery(const std::string &filename);

void deleteDelivery(const std::string &filename);

void editDelivery(const std::string &filename);

void summarizeDeliveries(const std::string &beverageFile, const std::string &deliveryFile, const std::string &outFile);
