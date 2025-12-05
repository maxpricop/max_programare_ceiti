#include <iostream>
#include <limits>
#include <queue>
#include <vector>

const long long INF = std::numeric_limits<long long>::max() / 4;

int main() {
	int numNodes, numEdges, startNode;

	std::cout << "Introdu numarul de noduri: ";
	std::cin >> numNodes;

	std::cout << "Introdu numarul de muchii: ";
	std::cin >> numEdges;

	std::cout << "Introdu nodul de start: ";
	std::cin >> startNode;

	std::vector<std::vector<std::pair<int, long long>>> adjacencyList(numNodes + 1);
	for (int edgeIndex = 0; edgeIndex < numEdges; ++edgeIndex) {
		int from, to;
		long long weight;

		std::cout << "Introdu muchia " << edgeIndex + 1 << " (format: nodulOrigine, nodulFinal, greutatea/costul): ";
		std::cin >> from >> to >> weight;

		if (from >= 1 && from <= numNodes) adjacencyList[from].emplace_back(to, weight);
	}

	std::vector<long long> distance(numNodes + 1, INF);
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>>
		priorityQueue;
	distance[startNode] = 0;
	priorityQueue.emplace(0, startNode);

	while (!priorityQueue.empty()) {
		std::pair<long long, int> topPair = priorityQueue.top();
		long long currentDistance = topPair.first;
		int currentNode = topPair.second;

		priorityQueue.pop();
		if (currentDistance != distance[currentNode]) continue;

		for (auto &edge : adjacencyList[currentNode]) {
			int to = edge.first;
			long long weight = edge.second;

			if (to < 1 || to > numNodes) continue;

			if (distance[to] > currentDistance + weight) {
				distance[to] = currentDistance + weight;
				priorityQueue.emplace(distance[to], to);
			}
		}
	}

	for (int nodeIndex = 1; nodeIndex <= numNodes; nodeIndex++) {
		std::cout << "Distanta de la nodul " << startNode << " la nodul " << nodeIndex << " este: ";
		if (distance[nodeIndex] == INF) std::cout << -1;
		else std::cout << distance[nodeIndex];

		std::cout << '\n';
	}

	std::cout << '\n';

	return 0;
}
