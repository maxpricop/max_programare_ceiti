#pragma once
#include "string"
#include "vector"

void appendLine(const std::vector<std::string> &elements, const std::string &filename);

std::vector<std::string> readAllLines(const std::string &filename);

void writeAllLines(const std::vector<std::string> &lines, const std::string &filename);