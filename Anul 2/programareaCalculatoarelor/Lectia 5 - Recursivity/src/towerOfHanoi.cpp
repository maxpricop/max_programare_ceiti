#include "../include/exercises/Exercises.hpp"
#include <cmath>
#include <iostream>

void moveDiskRecursively(int diskCount, char fromTower, char toTower, char auxTower) {
	if (diskCount == 1) {
		std::cout << "Mutare discul " << diskCount << " de la " << fromTower << " la " << toTower << '\n';
		return;
	}

	moveDiskRecursively(diskCount - 1, fromTower, auxTower, toTower);
	std::cout << "Mutare discul " << diskCount << " de la " << fromTower << " la " << toTower << '\n';
	moveDiskRecursively(diskCount - 1, auxTower, toTower, fromTower);
}

void solveItteratively(int diskCount, char fromTower, char toTower, char auxTower) {
	int totalMoves = pow(2, diskCount) - 1; // 2^n - 1

	for (int move = 1; move <= totalMoves; move++) {
		int disk = 1;
		int temp = move;

		while (temp % 2 == 0) {
			disk++;
			temp /= 2;
		}

		if (diskCount % 2 == 0) {
			if (move % 3 == 0) std::cout << "Mutare discul " << disk << " de la " << auxTower << " la " << toTower << '\n';
			else if (move % 3 == 1) std::cout << "Mutare discul " << disk << " de la " << fromTower << " la " << auxTower << '\n';
			else std::cout << "Mutare discul " << disk << " de la " << fromTower << " la " << toTower << '\n';
		} else {
			if (move % 3 == 0) std::cout << "Mutare discul " << disk << " de la " << toTower << " la " << auxTower << '\n';
			else if (move % 3 == 1) std::cout << "Mutare discul " << disk << " de la " << fromTower << " la " << toTower << '\n';
			else std::cout << "Mutare discul " << disk << " de la " << fromTower << " la " << auxTower << '\n';
		}
	}
}

void towerOfHanoi() {
	short int solveMethod;
	std::cout << "Alege metoda de rezolvare:\n";
	std::cout << "1. Recursivitate\n";
	std::cout << "2. Iterativ\n";
	std::cout << "Optiunea aleasa: ";
	std::cin >> solveMethod;

	int diskNumber;
	std::cout << "Introdu nr. de discuri: ";
	std::cin >> diskNumber;

	std::cout << "Miscarile sunt:\n";
	if (solveMethod == 1) moveDiskRecursively(diskNumber, 'A', 'B', 'C');
	else solveItteratively(diskNumber, 'A', 'B', 'C');
}