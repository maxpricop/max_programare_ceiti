#include "../include/exercises/Exercises.hpp"
#include <iostream>

int main() {
	while (true) {
		std::cout << "----- Tema: Exercitii cu liste -----\n";
		std::cout << "Alege exercitiul de rulat:\n";
		std::cout << "1. Exercitiul 14\n";
		std::cout << "2. Exercitiul 15\n";
		std::cout << "3. Exercitiul 16\n";
		std::cout << "4. Iesire\n";
		std::cout << "Optiunea: ";

		int choice;
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Input invalid.\n\n";
			continue;
		}

		switch (choice) {
			case 1: {
				runEx14();
				break;
			}
			case 2: {
				runEx15();
				break;
			}
			case 3: {
				runEx16();
				break;
			}
			case 4: {
				std::cout << "Program inchis\n";
				return 0;
			}
			default: {
				std::cout << "Optiune invalida\n";
				break;
			}
		}
	}

	return 0;
}
