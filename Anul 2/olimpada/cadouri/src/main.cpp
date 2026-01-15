#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned long long int bomboaneInCadou = 0;
	unsigned long long int pachete1 = 0;
	unsigned long long int pachete3 = 0;

	if (!(std::cin >> bomboaneInCadou >> pachete1 >> pachete3)) return 0;

	unsigned long long high = (pachete1 + 3ull * pachete3) / bomboaneInCadou;
	unsigned long long low = 0;
	unsigned long long cadouriTotale = 0;

	while (low <= high) {
		unsigned long long mid = low + (high - low) / 2;

		unsigned long long triplePachete = bomboaneInCadou / 3;

		unsigned long long maxTriplePachete;
		if (triplePachete == 0) maxTriplePachete = 0;
		else maxTriplePachete = mid * triplePachete;

		unsigned long long tripleFolosibile = std::min(pachete3, maxTriplePachete);

		unsigned long long total = pachete1 + 3ull * tripleFolosibile;

		if (total / bomboaneInCadou >= mid) {
			cadouriTotale = mid;
			low = mid + 1;
		} else {
			if (mid == 0) break;
			high = mid - 1;
		}
	}

	std::cout << cadouriTotale;

	return 0;
}