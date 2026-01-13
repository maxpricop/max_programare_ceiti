#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned long long int n = 2;
	if (!(std::cin >> n)) return 0;

	unsigned long long int best = 2;

	for (unsigned long long int putere2 = 1; putere2 <= n; putere2 *= 2) {
		for (unsigned long long int value23 = putere2; value23 <= n; value23 *= 3) {
			for (unsigned long long int candidateNumber = value23; candidateNumber <= n; candidateNumber *= 5) {
				if (candidateNumber > best) best = candidateNumber;

				if (candidateNumber > n / 5) break;
			}

			if (value23 > n / 3) break;
		}

		if (putere2 > n / 2) break;
	}

	std::cout << best;

	return 0;
}