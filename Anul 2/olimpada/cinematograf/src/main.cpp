#include <ios>
#include <iostream>

/**
 * Rand impar - N locuri
 * Rand par - N+1 locuri
 * Primul rand este 1, impar
 * Locurile sunt numerotate de la 1 la N sau N+1
 */
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned long long int N = 1;
	unsigned long long int K = 1;
	if (!(std::cin >> N >> K)) return 0;

	// Locurile intr-o pereche de randuri (rand impar + rand par)
	unsigned long long int locuriInPereche = 2 * N + 1;

	// Cate perechi complete de randuri (rand par + impar) sunt inaintea locului K
	unsigned long long int perechiInainte = (K - 1) / locuriInPereche;

	// Al catelea loc in perechea curenta este locul K. De la 1 la locuriInPereche
	unsigned long long int pozitieInPereche = (K - 1) % locuriInPereche + 1;

	unsigned long long randFinal, locFinal;
	if (pozitieInPereche <= N) {
		// rand impar
		randFinal = perechiInainte * 2 + 1;
		locFinal = pozitieInPereche;
	} else {
		// rand par
		randFinal = perechiInainte * 2 + 2;
		locFinal = pozitieInPereche - N;
	}

	// Incercarea originala - formula gresita
	// unsigned long long int randuriPare = (K / N) / 2;
	// unsigned long long int randFinal = K % N == 0 ? (K / N) : (K / N) + 1;
	// unsigned long long int locFinal = K % N == 0 ? N : (K % N) - randuriPare;

	// if (locFinal == 0) {
	// 	locFinal = N + 1;
	// 	randFinal -= 1;
	// }

	// Metoda iterativa - prea lenta pentru K mare
	// for (unsigned int i = 1; i < K; ++i) {
	// 	if (randFinal & 1) {
	// 		if (locFinal == N) {
	// 			++randFinal;
	// 			locFinal = 1;
	// 		} else {
	// 			++locFinal;
	// 		}
	// 	} else {
	// 		if (locFinal == N + 1) {
	// 			++randFinal;
	// 			locFinal = 1;
	// 		} else {
	// 			++locFinal;
	// 		}
	// 	}
	// }

	std::cout << randFinal << " " << locFinal;

	return 0;
}