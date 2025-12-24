#include "../include/exercises/Exercises.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

const char letters[5] = {'a', 'b', 'c', 'd', 'e'};
const size_t MAX_WORD_LENGTH = 4;

bool isVowel(char letter) { return letter == 'a' || letter == 'e'; }

void backtrack(std::string &currentWord, std::vector<std::string> &generatedWords) {
	if (currentWord.length() == MAX_WORD_LENGTH) {
		generatedWords.push_back(currentWord);
		return;
	}

	for (char letter : letters) {
		if (!currentWord.empty()) {
			char lastLetter = currentWord.back();

			if (isVowel(lastLetter) && isVowel(letter)) continue;
		}

		currentWord.push_back(letter);
		backtrack(currentWord, generatedWords);
		currentWord.pop_back();
	}
}

/**
 * Exercitiul 1
 * Folosind metoda backtracking, sa se genereze in ordine lexicografica
 * cuvintele de cate patru litere din multimea A={a, b, c, d, e},
 * cuvinte care nu contin doua vocale alaturate.
 * Primele 8 cuvinte generate sunt: abab, abac, abad, abba, abbb, abbc, abbd, abbe
 */
void ex1() {
	std::vector<std::string> generatedWords;

	std::string currentWord;
	backtrack(currentWord, generatedWords);

	for (std::string &word : generatedWords) {
		std::cout << word << '\n';
	}
}