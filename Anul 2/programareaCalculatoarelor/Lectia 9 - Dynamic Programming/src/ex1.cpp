#include "../include/exercises/Exercises.hpp"
#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>

std::vector<std::vector<int>> pascalTriangle(std::size_t rows) {
	std::vector<std::vector<int>> result;
	std::vector<int> previousRow;

	for (std::size_t row = 0; row < rows; row++) {
		std::vector<int> currentRow(row + 1, 1);

		for (std::size_t i = 1; i < row; i++) {
			currentRow[i] = previousRow[i - 1] + previousRow[i];
		}

		result.push_back(currentRow);
		previousRow = currentRow;
	}

	return result;
}

void ex1() {
	std::size_t rowNumber = 1;
	std::cout << "Introdu numarul de randuri pentru triunghiul lui Pascal: ";

	if (!(std::cin >> rowNumber) || rowNumber <= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Valoare invalida. Trebuie un integer > 0.\n";
		return;
	}

	std::vector<std::vector<int>> finalTriangle = pascalTriangle(rowNumber);

	for (auto row : finalTriangle) {
		for (auto value : row) {
			std::cout << value << " ";
		}

		std::cout << '\n';
	}
}