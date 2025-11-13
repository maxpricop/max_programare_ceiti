#include "../include/exercises/Exercises.hpp"
#include <iostream>

int main() {
	while (true) {
		short int userChoice;

		std::cout << "Alege o optiune:\n";
		std::cout << "1. Numere prime in interval.\n";
		std::cout << "2. Iesi din program.\n";
		std::cout << "Optiunea aleasa: ";

		if (!(std::cin >> userChoice)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			std::cout << "Input invalid\n\n\n\n";
			continue;
		}

		switch (userChoice) {
			case 1: {
				ex1();
				break;
			}
			case 2: {
				std::cout << "Program inchis cu succes.\n";
				return 0;
			}
			default: {
				std::cout << "Optiune invalida.";
			}
		}

		std::cout << "\n\n\n";
	}
	return 0;
}