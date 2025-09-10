#include "../include/linkedLists/LinkedList.hpp"
#include <iostream>

int main() {
	LinkedList list;

	while (true) {
		short int userChoice;

		std::cout << "Alege o optiune:\n";
		std::cout << "1. Adauga un element in linked list la inceput.\n";
		std::cout << "2. Adauga un element in linked list la sfarsit.\n";
		std::cout << "3. Sterge un element din linked list in baza valorii.\n";
		std::cout << "4. Sterge un element din linked list in baza pozitiei din lista.\n";
		std::cout << "5. Afiseaza linked list.\n";
		std::cout << "6. Iesi din program.\n";
		std::cout << "Optiunea aleasa: ";

		if (!(std::cin >> userChoice)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			std::cout << "Input invalid\n\n\n\n";
			continue;
		}

		switch (userChoice) {
			case 1: {
				int newData;
				std::cout << "Introdu ce informatie (int) vrei sa fie salvata in lista la inceput: ";
				std::cin >> newData;
				list.insertAtStart(newData);
				break;
			}
			case 2: {
				int newData;
				std::cout << "Introdu ce informatie (int) vrei sa fie salvata in lista la sfarsit: ";
				std::cin >> newData;

				list.insertAtEnd(newData);
				break;
			}
			case 3: {
				int deleteData;
				std::cout << "Introdu valoarea ce sa fie stearsa: ";
				std::cin >> deleteData;

				if (list.removeValue(deleteData)) std::cout << "Elementul cu valoarea " << deleteData << " a fost sters.\n";
				else std::cout << "Acest element nu exista in lista.\n";

				break;
			}
			case 4: {
				unsigned deletePosition;
				std::cout << "Introdu pozitia ce sa fie stearsa: ";
				std::cin >> deletePosition;

				if (list.removePosition(deletePosition)) std::cout << "Elementul cu pozitia " << deletePosition << " a fost sters.\n";
				else std::cout << "Acesta pozitie nu exista in lista.\n";

				break;
			}
			case 5: {
				list.display();
				break;
			}
			case 6: {
				std::cout << "Program inchis cu succes.\n";
				return 0;
			}
			default: {
				std::cout << "Optiune invalida.\n\n";
			}
		}

		std::cout << "\n\n\n";
	}
}
