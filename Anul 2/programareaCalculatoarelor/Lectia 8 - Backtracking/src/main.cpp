#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <limits>

int main() {
	while (true) {
		short int userChoice;

		std::cout << "Alege o optiune:\n";
		std::cout << "1. Permutarile posibile.\n";
		std::cout << "2. Alfabet.\n";
		std::cout << "3. Iesi din program.\n";
		std::cout << "Optiunea aleasa: ";

		if (!(std::cin >> userChoice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Input invalid\n\n\n\n";
			continue;
		}

		switch (userChoice) {
			case 1: {
				ex1();
				break;
			}
			case 2: {
				ex2();
				break;
			}
			case 3: {
				std::cout << "Program inchis cu succes.\n";
				return 0;
			}
			default: {
				std::cout << "Optiune invalida.\n\n";
			}
		}

		std::cout << "\n\n\n";
	}

	return 0;
}