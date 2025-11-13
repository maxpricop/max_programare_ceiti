#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <utility>
#include <vector>

void ex1() {
	unsigned int amount;
	std::vector<std::pair<unsigned int, unsigned int>> banknotes = {{100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2, 0}};

	std::cout << "Introdu o suma de bani: ";
	if (!(std::cin >> amount)) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		std::cout << "Input invalid\n\n\n\n";
		return;
	}

	for (auto &banknote : banknotes) {
		banknote.second = amount / banknote.first;
		amount %= banknote.first;
	}

	if (amount != 0) {
		std::cout << "Nu se poate returna suma exacta cu bancnotele disponibile.\n";
		return;
	}

	std::cout << "Bancnotele returnate sunt:\n";
	for (const auto &banknote : banknotes) {
		std::cout << "Bancnote de " << banknote.first << ": " << banknote.second << '\n';
	}
}