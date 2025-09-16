#include "../include/exercises/Exercises.hpp"
#include "../include/linkedLists/LinkedList.hpp"
#include <iostream>

void runEx14() {
	LinkedList list;

	std::cout << "Exercitiul 14\n";
	std::cout << "Citeste numere intregi pana se intalneste o valoare negativa (aceasta nu se adauga)\n";

	while (true) {
		int newElement;
		std::cout << "Introduceti un numar (negativ -> stop): ";

		if (!(std::cin >> newElement)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Input invalid, incercati din nou.\n";
			continue;
		}

		if (newElement < 0) break;
		list.insertEnd(newElement);
	}

	std::cout << "Lista creata: ";
	list.display();

	std::cout << "Elementele impare din lista: ";
	list.displayIf([](int nodeValue) { return nodeValue % 2 == 1; });

	// Contorizeaza in lista divizorii lui 25
	std::size_t divisorsCount = list.countIf([](int nodeValue) {
		if (nodeValue == 0) return false;
		return 25 % nodeValue == 0;
	});

	std::cout << "Numarul de elemente din lista care sunt divizori ai lui 25: " << divisorsCount << '\n';

	// Sterge elementele care contin informatie 17
	std::size_t removed = list.removeAll(17);
	std::cout << "S-au sters " << removed << " noduri cu valoarea 17.\n";

	std::cout << "Lista dupa stergere: ";
	list.display();

	std::cout << "Sfarsit exercitiu 14.\n";
}
