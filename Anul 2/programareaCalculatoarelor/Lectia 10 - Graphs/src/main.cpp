#include <cstddef>
#include <iostream>

int main() {
	std::size_t graphNodes;

	std::cout << "Introduceti numarul de noduri ale grafului: ";
	std::cin >> graphNodes;

	int adjacencyMatrix[graphNodes][graphNodes];

	std::cout << '\t';
	for (std::size_t i = 0; i < graphNodes; ++i) {
		std::cout << i + 1 << '\t';
	}
	std::cout << '\n';

	for (std::size_t i = 0; i < graphNodes; ++i) {
		std::cout << i + 1 << '\t';
		for (std::size_t j = 0; j < graphNodes; ++j) {
			std::cin >> adjacencyMatrix[i][j];
		}
	}
	std::cout << '\n';

	std::cout << "Nodurile izolate sunt:\n";
	for (std::size_t i = 0; i < graphNodes; ++i) {
		bool isolated = true;

		for (std::size_t j = 0; j < graphNodes; ++j) {
			if (adjacencyMatrix[i][j] != 0) {
				isolated = false;
				break;
			}
		}

		if (isolated) std::cout << i + 1 << ' ';
	}
	std::cout << '\n';

	// std::cout << "Matricea de adiacenta este:\n";
	// std::cout << '\t';
	// for (std::size_t i = 0; i < graphNodes; ++i) {
	// 	std::cout << i + 1 << '\t';
	// }
	// std::cout << '\n';

	// for (std::size_t i = 0; i < graphNodes; ++i) {
	// 	std::cout << i + 1 << '\t';
	// 	for (std::size_t j = 0; j < graphNodes; ++j) {
	// 		std::cout << adjacencyMatrix[i][j] << '\t';
	// 	}
	// 	std::cout << '\n';
	// }

	return 0;
}