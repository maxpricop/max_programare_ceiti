#include "../include/exercises/Exercises.hpp"
#include "../include/linkedLists/LinkedList.hpp"
#include <iostream>

void runEx16() {
	LinkedList list;

	std::cout << "Exercitiul 16\n";
	std::cout << "Citeste numere intregi pana la 0 (0 -> stop; nu se adauga)\n";

	while (true) {
		int newElement;
		std::cout << "Introduceti un numar (0 -> stop): ";

		if (!(std::cin >> newElement)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Input invalid, incercati din nou.\n";
			continue;
		}

		if (newElement == 0) break;
		list.insertEnd(newElement);
	}

	std::cout << "Lista creata: ";
	list.display();

	// Afiseaza multiplii lui 7
	std::cout << "Multiplii lui 7 din lista: ";
	list.displayIf([](int nodeValue) { return nodeValue % 7 == 0; });

	// Gaseste elementul minim
	if (!list.empty()) {
		int min = list.findMin();
		std::cout << "Elementul minim al listei: " << min << '\n';

	} else {
		std::cout << "Lista este goala — nu exista element minim.\n";
	}

	// Contorizeaza elementele negative
	std::size_t negativeCount = list.countIf([](int nodeValue) { return nodeValue < 0; });
	std::cout << "Numarul elementelor negative: " << negativeCount << '\n';

	// Sterge nodurile cu informatia 5
	std::size_t removed = list.removeAll(5);
	std::cout << "S-au sters " << removed << " noduri cu valoarea 5.\n";

	std::cout << "Lista dupa stergere: ";
	list.display();

	std::cout << "Sfarsit exercitiu 16.\n";
}
