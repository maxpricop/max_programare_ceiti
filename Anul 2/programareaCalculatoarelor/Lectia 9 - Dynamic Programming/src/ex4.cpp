#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <vector>

int triangleSum(std::vector<std::vector<int>> &triangle) {
	int triangleSize = triangle.size();
	std::vector<std::vector<int>> dp(triangleSize, std::vector<int>(triangleSize, 0));

	for (int i = 0; i < triangleSize; i++) {
		dp[triangleSize - 1][i] = triangle[triangleSize - 1][i];
	}

	// Bottom-up DP
	for (int i = triangleSize - 2; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int down = triangle[i][j] + dp[i + 1][j];
			int downRight = triangle[i][j] + dp[i + 1][j + 1];

			dp[i][j] = std::min(down, downRight);
		}
	}

	return dp[0][0];
}

void ex4() {
	std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

	int minSum = triangleSum(triangle);
	std::cout << "Suma minima de la varful la baza triunghiului este: " << minSum << "\n";
}