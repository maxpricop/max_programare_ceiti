#include <iostream>
#include <limits>
#include <random>

int main() {
	unsigned long long maxNumber = 1;
	unsigned long long randomNumber = 1;

	while (true) {
		std::cout << "Introdu limita n (superioara) pentru numarul ascuns (n >= 1): ";

		if (!(std::cin >> maxNumber)) {
			std::cout << "Numar invalid!\n\n\n";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}

		break;
	}

	std::cout << "Numarul ascuns poate fi intre 1 si " << maxNumber << ".\n";

	std::random_device rd;
	std::mt19937_64 generator(rd());
	std::uniform_int_distribution<unsigned long long> dist(1, maxNumber);
	randomNumber = dist(generator);

	while (true) {
		std::cout << "Alege o optiune:\n";
		std::cout << "1. Numarul este egal cu ... ?\n";
		std::cout << "2. Numarul este mai mare decat ... ?\n";
		std::cout << "3. Numarul este mai mic decat ... ?\n";
		std::cout << "4. Preda-te (afiseaza numarul ascuns si iesi din program).\n";
		std::cout << "Optiunea aleasa: ";

		short int userChoice;
		if (!(std::cin >> userChoice)) {
			std::cout << "Optiune Invalida!\n\n\n";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}

		if (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4) {
			std::cout << "Optiune Invalida!\n\n\n";
			continue;
		}

		if (userChoice == 4) {
			std::cout << "Numarul ascuns era: " << randomNumber << '\n';
			return 0;
		}

		unsigned long long guessedNumber;
		std::cout << "Introdu numarul: ";
		if (!(std::cin >> guessedNumber)) {
			std::cout << "Numar invalid!\n\n\n";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}

		switch (userChoice) {
			case 1: {
				if (randomNumber == guessedNumber) {
					std::cout << "Felicitari! Ai ghicit numarul ascuns (" << randomNumber << ").\n";
					return 0;
				} else std::cout << "Numarul ascuns nu este " << guessedNumber << ".\n\n\n";

				break;
			}
			case 2: {
				if (randomNumber > guessedNumber) std::cout << "Da, numarul ascuns este mai mare decat " << guessedNumber << ".\n\n\n";
				else std::cout << "Nu, numarul ascuns nu este mai mare decat " << guessedNumber << ".\n\n\n";

				break;
			}
			case 3: {
				if (randomNumber < guessedNumber) std::cout << "Da, numarul ascuns este mai mic decat " << guessedNumber << ".\n\n\n";
				else std::cout << "Nu, numarul ascuns nu este mai mic decat " << guessedNumber << ".\n\n\n";

				break;
			}
		}
	}

	return 0;
}
