#include "../include/exercises/Exercises.hpp"
#include <iostream>

int main() {

	while (true) {
		short int userChoice;
		std::cout << "Alege rularea unui exercitiu:\n";
		std::cout << "1. Exercitiul 1\n";
		std::cout << "2. Exercitiul 1, dar cu stiva statica\n";
		std::cout << "3. Exercitiul 2\n";
		std::cout << "4. Exercitiul 3\n";
		std::cout << "5. Exercitiul 4\n";
		std::cout << "6. Exercitiul 5\n";
		std::cout << "7. Exercitiul 6\n";
		std::cout << "8. Exercitiul 7\n";
		std::cout << "9. Exercitiul 8\n";
		std::cout << "10. Inchide programul\n";
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
				ex1Static();
				break;
			}
			case 3: {
				ex2();
				break;
			}
			case 4: {
				ex3();
				break;
			}
			case 5: {
				ex4();
				break;
			}
			case 6: {
				ex5();
				break;
			}
			case 7: {
				ex6();
				break;
			}
			case 8: {
				ex7();
				break;
			}
			case 9: {
				ex8();
				break;
			}
			case 10: {
				std::cout << "Program inchis";
				return 0;
			}
			default: {
				std::cout << "Optiune invalida.";
				break;
			}
		}

		std::cout << "\n\n";
	}

	return 0;
}