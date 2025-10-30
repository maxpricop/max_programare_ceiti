#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <limits>

int main() {
	while (true) {
		int option;

		std::cout << "Alege exercitiul:\n";
		std::cout << "1. Tower of Hanoi\n";
		std::cout << "2. Factori Primi\n";
		std::cout << "3. Verificare Palindrome\n";
		std::cout << "4. Oprire Program\n";
		std::cout << "Optiunea aleasa: ";

		if (!(std::cin >> option)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input Invalid.\n\n";
			continue;
		}

		switch (option) {
			case 1: {
				towerOfHanoi();
				break;
			}
			case 2: {
				primeFactors();
				break;
			}
			case 3: {
				palindromeCheck();
				break;
			}
			case 4: {
				std::cout << "Program Inchis\n";
				return 0;
			}
			default: {
				std::cout << "Optiune invalida\n";
				break;
			}
		}

		std::cout << '\n';
	}

	return 0;
}