#include <ios>
#include <iostream>

unsigned long int reverseNumber(unsigned long int originalNumber) {
	unsigned long int reversedNumber = 0;

	while (originalNumber != 0) {
		char nextDigit = originalNumber % 10;
		reversedNumber = reversedNumber * 10 + nextDigit;

		originalNumber /= 10;
	}

	return reversedNumber;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned long int n = 0;
	if (!(std::cin >> n)) return 0;

	unsigned short int nivelPalindromic = 0;
	unsigned long int reversedNumber = reverseNumber(n);

	while (n != reversedNumber) {
		n += reversedNumber;
		reversedNumber = reverseNumber(n);

		++nivelPalindromic;
	}

	std::cout << nivelPalindromic;

	return 0;
}