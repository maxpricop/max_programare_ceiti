#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// 0 - nord, 1 - est, 2 - sud, 3 - vest
	long long int pasi[4] = {0, 0, 0, 0};

	long long int totalSteps = 0;
	long long int lungimePadure = 0;

	if (!(std::cin >> pasi[0] >> pasi[1] >> pasi[2] >> pasi[3] >> lungimePadure)) return 0;

	// Progres spre iesire in urmatoarele directii
	// 0 - nord/sud, 1 - vest/est
	long long int progress[2] = {lungimePadure, lungimePadure};
	lungimePadure *= 2;

	unsigned short int currentStep = 0;
	while ((progress[0] > 0 && progress[1] > 0) && (progress[0] < lungimePadure && progress[1] < lungimePadure) &&
		   (progress[0] < lungimePadure && progress[1] > 0) && (progress[0] > 0 && progress[1] < lungimePadure)) {
		totalSteps += pasi[currentStep];

		switch (currentStep) {
			case 0: {
				// Mers spre nord (sus)
				progress[0] += pasi[0];

				++currentStep;
				break;
			}
			case 1: {
				// Mers spre est (dreapta)
				progress[1] += pasi[1];

				++currentStep;
				break;
			}
			case 2: {
				// Mers spre sud (jos)
				progress[0] -= pasi[2];

				++currentStep;
				break;
			}
			case 3: {
				// Mers spre vest (stanga)
				progress[1] -= pasi[3];

				currentStep = 0;
				break;
			}
			default: {
				return 1;
			}
		}
	}

	if (progress[0] < 0) totalSteps += progress[0];
	if (progress[1] < 0) totalSteps += progress[1];

	if (progress[0] > lungimePadure) totalSteps -= (progress[0] - lungimePadure);
	if (progress[1] > lungimePadure) totalSteps -= (progress[1] - lungimePadure);

	std::cout << totalSteps;

	return 0;
}