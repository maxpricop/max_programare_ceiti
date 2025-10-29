#include "../include/binaryTree/BinaryTree.hpp"
#include <iostream>
#include <limits>

int main() {
	BinaryTree tree;
	int choice = 0;

	while (true) {
		std::cout << "Arbore Binar - Alege o optiune:\n";
		std::cout << "1. Inserare\n";
		std::cout << "2. Cautare\n";
		std::cout << "3. Stergere\n";
		std::cout << "4. Parcurgere preordine\n";
		std::cout << "5. Parcurgere inordine\n";
		std::cout << "6. Parcurgere postordine\n";
		std::cout << "7. Golire arbore\n";
		std::cout << "8. Iesire\n";
		std::cout << "Alege o optiune: ";

		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input Invalid.\n";
			continue;
		}

		switch (choice) {
			case 1: {
				int value;
				std::cout << "Introdu valoarea de inserat: ";

				if (std::cin >> value) {
					tree.insert(value);
					std::cout << "Inserat " << value << '\n';
				} else {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Valoare invalida.\n";
				}

				break;
			}
			case 2: {
				int value;
				std::cout << "Introdu valoarea de cautat: ";

				if (std::cin >> value) {
					bool found = tree.search(value);
					std::cout << (found ? "Gasit\n" : "Nu a fost gasit\n");
				} else {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Valoare invalida.\n";
				}

				break;
			}
			case 3: {
				int value;
				std::cout << "Introdu valoarea de sters: ";

				if (std::cin >> value) {
					bool removed = tree.remove(value);
					std::cout << (removed ? "Sters\n" : "Valoarea nu a fost gasita\n");
				} else {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Valoare invalida.\n";
				}

				break;
			}
			case 4: {
				std::cout << "Preordine: ";
				tree.preorderTraversal();
				break;
			}
			case 5: {
				std::cout << "Inordine: ";
				tree.inorderTraversal();
				break;
			}
			case 6: {
				std::cout << "Postordine: ";
				tree.postorderTraversal();
				break;
			}
			case 7: {
				tree.clear();
				std::cout << "Arbore golit\n";
				break;
			}
			case 8: {
				std::cout << "Program Inchis\n";
				return 0;
			}
			default: {
				std::cout << "Optiune Invalida.\n";
				break;
			}
		}

		std::cout << '\n';
	}

	return 0;
}