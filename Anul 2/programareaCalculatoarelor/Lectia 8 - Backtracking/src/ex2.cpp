#include "../include/exercises/Exercises.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

bool isVowel(char character) { return character == 'a' || character == 'e'; }

void backtrack(std::string &finalString, std::size_t currentPosition, const std::vector<char> &alphabet, unsigned int &counter) {
	const std::size_t endPosition = finalString.size();

	if (currentPosition == endPosition) {
		std::cout << finalString << '\n';
		counter++;

		return;
	}

	for (char ch : alphabet) {
		if (currentPosition > 0 && isVowel(finalString[currentPosition - 1]) && isVowel(ch)) continue;

		finalString[currentPosition] = ch;
		backtrack(finalString, currentPosition + 1, alphabet, counter);
	}
}

void ex2() {
	const std::size_t length = 4;
	std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e'};
	std::string theString(length, ' ');

	unsigned int counter = 0;

	backtrack(theString, 0, alphabet, counter);
	std::cout << "Total cuvinte generate: " << counter << '\n';
}
