#include "../include/linkedLists/CircularLinkedList.hpp"
#include <cstddef>
#include <iostream>

int main() {
	CircularDoublyLinkedList list;

	while (true) {
		std::cout << "Meniu:\n";
		std::cout << "1. Adauga element\n";
		std::cout << "2. Sterge element\n";
		std::cout << "3. Afiseaza lista\n";
		std::cout << "4. Numarul de elemente cu vecini egali\n";
		std::cout << "5. Sterge lista\n";
		std::cout << "6. Iesire\n";

		short int userChoice;
		std::cout << "Optiunea aleasa: ";
		if (!(std::cin >> userChoice)) {
			std::cout << "Input invalid!\n\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (userChoice) {
			case 1: {
				int value;
				std::size_t position;

				std::cout << "Valoarea de adaugat: ";
				std::cin >> value;

				std::cout << "Pozitia la care se adauga (0 - inceput, " << list.size() << " - sfarsit): ";
				std::cin >> position;

				if (list.push(value, position)) std::cout << "Element adaugat cu succes!\n";
				else std::cout << "Elementul nu a fost putut fi adaugat!\n";

				break;
			}
			case 2: {
				std::size_t position;

				if (list.size() == 0) {
					std::cout << "Lista este goala!\n";
					break;
				}

				std::cout << "Pozitia de sters (0 - inceput, " << list.size() - 1 << " - sfarsit): ";
				std::cin >> position;

				if (list.pop(position)) std::cout << "Element sters cu succes!\n";
				else std::cout << "Elementul nu a fost putut fi sters!\n";

				break;
			}
			case 3: {
				if (list.size() == 0) {
					std::cout << "Lista este goala!\n";
					break;
				}

				auto curentElement = list.getHead();

				std::cout << "Lista: ";
				for (size_t i = 0; i < list.size(); i++) {
					std::cout << curentElement->data;

					if (curentElement->next == list.getHead()) std::cout << '.';
					else std::cout << ", ";

					curentElement = curentElement->next;
				}
				std::cout << '\n';

				break;
			}
			case 4: {
				std::cout << "Numarul de elemente cu vecini egali: " << list.countElementsWithEqualNeighbors() << '\n';
				break;
			}
			case 5: {
				list.clear();
				std::cout << "Lista a fost stearsa!\n";
				break;
			}
			case 6: {
				list.clear();
				std::cout << "Program inchis!\n";
				return 0;
			}
			default: {
				std::cout << "Optiune invalida!\n";
				break;
			}
		}

		std::cout << "\n\n\n";
	}

	return 0;
}