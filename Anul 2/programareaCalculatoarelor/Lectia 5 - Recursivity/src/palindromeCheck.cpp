#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <string>

bool isPalindrome(const std::string &s, int leftIndex, int rightIndex) {
	if (leftIndex >= rightIndex) return true;
	if (s[leftIndex] != s[rightIndex]) return false;

	return isPalindrome(s, leftIndex + 1, rightIndex - 1);
}

void palindromeCheck() {
	std::string str;
	std::cout << "Introdu un cuvant: ";
	std::cin >> str;

	bool check = isPalindrome(str, 0, str.length() - 1);

	if (check) std::cout << '"' << str << "\" este un palindrom.\n";
	else std::cout << '"' << str << "\" nu este un palindrom.\n";
}
