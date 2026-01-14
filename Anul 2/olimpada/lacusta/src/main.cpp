#include <ios>
#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned short int n = 0;
	if (!(std::cin >> n)) return 0;

	std::vector<bool> T(n + 1, true);
	for (unsigned short int i = 1; i <= n; ++i) {
		bool input = false;
		if (!(std::cin >> input)) return 0;

		T[i] = input;
	}

	std::vector<unsigned long long int> dp(n + 1);
	dp[0] = 1;

	for (unsigned short int i = 1; i <= n; ++i) {
		if (!T[i]) {
			dp[i] = 0;
			continue;
		}

		unsigned long long int rute = 0;
		if (i - 1 >= 0) rute += dp[i - 1];
		if (i - 2 >= 0) rute += dp[i - 2];
		if (i - 3 >= 0) rute += dp[i - 3];
		dp[i] = rute;
	}

	std::cout << dp[n];
	return 0;
}