#include "../include/exercises/Exercises.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

struct Time {
	public:
		unsigned short int hour;
		unsigned short int minute;
};

struct Show {
	public:
		Time start;
		Time end;
		size_t id;
};

unsigned short int toMinutes(const Time t) { return t.hour * 60 + t.minute; }

/**
 * Exercitiul 4
 * Managerul artistic al unui festival trebuie sa selecteze o multime cat mai ampla
 * de spectacole ce pot fi jucate intr-o singura sala pe care o are la dispozitie.
 * Stiind ca i s-au propus n (n <= 100) spectacole si pentru fiecare spectacol
 * i-a fost anuntat intervalul in care se poate desfasura [Si, Fi]
 * (Si reprezinta ora si minutul de inceput, iar Fi reprezinta ora si minutul de final al spectacolului i),
 * scrieti un program care sa permita spectatorilor vizionarea unui numar cat mai mare de spectacole.
 */
void ex4() {
	size_t showCount = 0;
	while (true) {
		std::cout << "Introdu numarul de spectacole (n <= 100): ";

		if (!(std::cin >> showCount)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Input invalid\n\n";
			continue;
		}

		if (showCount <= 0 || showCount > 100) {
			std::cout << "n trebuie sa fie intre 1 si 100.\n\n";
			continue;
		}

		break;
	}

	std::vector<Show> shows;
	shows.reserve(showCount);

	for (size_t i = 0; i < showCount; ++i) {
		while (true) {
			Time ShowStart = {0, 0};
			Time ShowEnd = {0, 0};
			;
			std::cout << "Introdu ora de start (0-23) pentru spectacolul " << i + 1 << ": ";
			if (!(std::cin >> ShowStart.hour)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "Input invalid\n";
				continue;
			}

			std::cout << "Introdu minutul de start (0-59) pentru spectacolul " << i + 1 << ": ";
			if (!(std::cin >> ShowStart.minute)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "Input invalid\n";
				continue;
			}

			std::cout << "Introdu ora de final (0-23) pentru spectacol " << i + 1 << ": ";
			if (!(std::cin >> ShowEnd.hour)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "Input invalid\n";
				continue;
			}

			std::cout << "Introdu minutul de final (0-59) pentru spectacol " << i + 1 << ": ";
			if (!(std::cin >> ShowEnd.minute)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "Input invalid\n";
				continue;
			}

			if (ShowStart.hour > 23 || ShowStart.minute > 59 || ShowEnd.hour > 23 || ShowEnd.minute > 59) {
				std::cout << "Ora trebuie sa fie intre 0 si 23, minutul intre 0 si 59.\n";
				continue;
			}

			if (toMinutes(ShowStart) >= toMinutes(ShowEnd)) {
				std::cout << "Timpul de inceput trebuie sa fie inaintea timpului de final.\n";
				continue;
			}

			shows.push_back({ShowStart, ShowEnd, i + 1});
			break;
		}
	}

	// Manual selection sort
	// We sort the shows by their finish time (earliest finish first).
	// This ordering is required for the greedy activity-selection algorithm:
	// picking the show that finishes earliest always leaves the maximum remaining
	// time to schedule subsequent (non-overlapping) shows, which yields an
	// optimal maximal set.
	for (size_t i = 0; i < shows.size(); ++i) {
		size_t minId = i;

		for (size_t j = i + 1; j < shows.size(); ++j) {
			unsigned short int jEnd = toMinutes(shows[j].end);
			unsigned short int minEnd = toMinutes(shows[minId].end);

			// If candidate finishes later than current minimum, skip
			if (jEnd > minEnd) continue;

			// If finishes at same time, require earlier start to replace
			if (jEnd == minEnd) {
				if (toMinutes(shows[j].start) >= toMinutes(shows[minId].start)) continue;
			}

			// Passed checks — this one is a better candidate
			minId = j;
		}

		if (minId != i) std::swap(shows[i], shows[minId]);
	}

	std::vector<Show> selectedShows;
	unsigned short int currentEnd = 0;
	for (const auto &possibileShow : shows) {
		// Skip shows that start before the current end time
		if (toMinutes(possibileShow.start) < currentEnd) continue;

		// Passed checks: select this show
		selectedShows.push_back(possibileShow);
		currentEnd = toMinutes(possibileShow.end);
	}

	std::cout << "Numarul maxim de spectacole care pot fi vizionate: " << selectedShows.size() << '\n';
	if (!selectedShows.empty()) {
		std::cout << "Spectacolele selectate:\n";
		for (const Show selectedShow : selectedShows) {
			std::cout << "ID - " << selectedShow.id << ", "
					  << "Start - " << selectedShow.start.hour << ":" << selectedShow.start.minute << ", "
					  << "Final - " << selectedShow.end.hour << ":" << selectedShow.end.minute << '\n';
		}
	}
}