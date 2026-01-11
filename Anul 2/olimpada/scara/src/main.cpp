#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned short int n = 0;
	if (!(std::cin >> n)) return 0;

	unsigned short int treapta1 = 1;
	std::cin >> treapta1;

	unsigned short int prev2 = 0;		 // dp[0]
	unsigned short int prev1 = treapta1; // dp[1]

	if (n == 1) {
		std::cout << prev1;
		return 0;
	}

	unsigned short int costActual = prev1;
	for (int i = 2; i <= n; ++i) {
		unsigned short int cost = 1;
		std::cin >> cost;

		if (prev1 < prev2) costActual = prev1 + cost;
		else costActual = prev2 + cost;

		prev2 = prev1;
		prev1 = costActual;
	}

	std::cout << prev1;

	return 0;
}