#include "../include/exercises/Exercises.hpp"
#include <cstddef>
#include <iostream>
#include <stack>
#include <string>

enum Color { WHITE = 1, YELLOW = 2, RED = 3, GREEN = 4, BLUE = 5, BLACK = 6 };
const Color allowedMidColors[2] = {YELLOW, GREEN};

std::string getColorName(Color selectedColor) {
	switch (selectedColor) {
		case WHITE: {
			return "Alb";
		}
		case YELLOW: {
			return "Galben";
		}
		case RED: {
			return "Rosu";
		}
		case GREEN: {
			return "Verde";
		}
		case BLUE: {
			return "Albastru";
		}
		case BLACK: {
			return "Negru";
		}
		default: {
			return "CULOARE INVALIDA";
		}
	}
}

/**
 * Exercitiul 5
 * Avem la dispozitie 6 culori: alb, galben, rosu, verde, albastru si negru.
 * Elaborati un program ce va preciza toate drapelele tricolore care se pot proiecta,
 * stiind ca trebuie respectate urmatoarele reguli:
 * - orice drapel are culoarea din mijloc galben sau verde;
 * - cele trei culori pe drapel sunt distincte.
 *
 * Exemple: "Alb-Galben-Rosu", "Rosu-Verde-Galben"
 * Indicatii: Folosim o stiva cu 3 nivele, reprezentand cele trei culori de pe drapel
 * si codificam culorile prin numere: 1 - alb, 2 - galben, 3 - rosu, 4 - verde, 5 - albastru, 6 - negru.
 */
void ex5() {
	size_t total = 0;
	std::cout << "Drapeale posibile:\n";

	for (Color midColor : allowedMidColors) {
		for (int left = WHITE; left <= BLACK; ++left) {
			for (int right = WHITE; right <= BLACK; ++right) {
				if (left == midColor) continue;
				if (right == midColor) continue;
				if (left == right) continue;

				std::stack<Color> st;

				// push in reverse so we can pop/print in left->mid->right order
				st.push(static_cast<Color>(right));
				st.push(midColor);
				st.push(static_cast<Color>(left));

				// print while popping (display before popping)
				bool first = true;
				while (!st.empty()) {
					Color color = st.top();

					if (first) first = false;
					else std::cout << "-";

					std::cout << getColorName(color);
					st.pop();
				}

				std::cout << '\n';
				++total;
			}
		}
	}

	std::cout << "Total drapele: " << total << '\n';
}