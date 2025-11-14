#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <string>
#include <vector>

unsigned maxRepeating(std::string sequence, std::string searchWord) {
	int sequenceSize = sequence.size();
	int searchWordSize = searchWord.size();

	std::vector<unsigned> dp(sequenceSize, 0);
	unsigned result = 0;

	for (int posSequence = 0; posSequence < sequenceSize; posSequence++) {
		if (posSequence + 1 < searchWordSize) continue;

		bool matches = true;
		for (int posWord = 0; posWord < searchWordSize; posWord++) {
			if (sequence[posSequence - searchWordSize + 1 + posWord] == searchWord[posWord]) continue;

			matches = false;
			break;
		}

		if (!matches) continue;
		dp[posSequence] = 1;

		if (posSequence - searchWordSize >= 0) dp[posSequence] += dp[posSequence - searchWordSize];
		result = std::max(result, dp[posSequence]);
	}

	return result;
}

void ex3() {
	std::string sequence;
	std::cout << "Introdu secventa: ";
	std::cin >> sequence;

	std::string searchWord;
	std::cout << "Introdu cuvantul cautat: ";
	std::cin >> searchWord;

	unsigned maxCount = maxRepeating(sequence, searchWord);
	std::cout << "Cuvantul '" << searchWord << "' apare de maximum " << maxCount << " ori consecutiv in secventa '" << sequence << "'.\n";
}