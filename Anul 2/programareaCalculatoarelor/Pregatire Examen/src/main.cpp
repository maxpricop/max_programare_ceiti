#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <limits>

int main() {
	while (true) {
		short int userChoice;

		std::cout << "Alege o optiune:\n";
		std::cout << "1. Backtracking cuvinte de 4 litere fara 2 vocale alaturate.\n";
		std::cout << "2. De aflat produsul maxim unui sir de numere intregi.\n";
		std::cout << "3. Numar de masini de pot fi reparate intr-un timp.\n";
		std::cout << "4. Spectacole maxime de privit\n";
		std::cout << "5. Toate drapelele posisible\n";
		std::cout << "6. Iesi din program.\n";
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
				ex3();
				break;
			}
			case 4: {
				ex4();
				break;
			}
			case 5: {
				ex5();
				break;
			}
			case 6: {
				std::cout << "Program inchis cu succes.";
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