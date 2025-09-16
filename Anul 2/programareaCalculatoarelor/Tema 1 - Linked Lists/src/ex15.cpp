#include "../include/exercises/Exercises.hpp"
#include "../include/linkedLists/LinkedList.hpp"
#include <iostream>

void runEx15() {
	LinkedList list;

	std::cout << "Exercitiul 15\n";
	std::cout << "Citeste numere intregi pana se intalneste valoarea 10 (10 -> stop; nu se adauga)\n";

	while (true) {
		int newElement;
		std::cout << "Introduceti un numar (10 -> stop): ";

		if (!(std::cin >> newElement)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Input invalid, incercati din nou.\n";
			continue;
		}

		if (newElement == 10) break;
		list.insertEnd(newElement);
	}

	std::cout << "Lista creata: ";
	list.display();

	// Contorizeaza elementele divizibile cu 5
	std::size_t div5 = list.countIf([](int nodeValue) { return nodeValue % 5 == 0; });
	std::cout << "Numarul elementelor divizibile cu 5: " << div5 << '\n';

	// Afiseaza elementele nenegative (>= 0)
	std::cout << "Elementele nenegative (>=0): ";
	list.displayIf([](int v) { return v >= 0; });

	// Sterge nodurile cu informatia 13
	std::size_t removed = list.removeAll(13);
	std::cout << "S-au sters " << removed << " noduri cu valoarea 13.\n";

	std::cout << "Lista dupa stergere: ";
	list.display();

	std::cout << "Sfarsit exercitiu 15.\n";
}
