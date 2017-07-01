#include "TravellingSalesman.h"

TravellingSalesman::TravellingSalesman() {}

TravellingSalesman::TravellingSalesman(int numberOfCities)
{
	this->numberOfCities = numberOfCities;
	cities = new int*[numberOfCities];
	for (int i = 0; i < numberOfCities; i++) {
		cities[i] = new int[numberOfCities];
		for (int j = 0; j < numberOfCities; j++) {
			cities[i][j] = 0;
		}
	}
}

TravellingSalesman::~TravellingSalesman()
{
}

void TravellingSalesman::FillGraphManually() {
	int x, y, z;
	for (int i = 0; i < numberOfCities; i++) {
		std::cin >> x >> y >> z;
		cities[x][y] = cities[y][x] = z;
	}
}

void TravellingSalesman::FillGraphAuto() {
	srand(time(NULL));
	for (int i = 0; i < numberOfCities; i++) {
		for (int j = 0; j < numberOfCities; j++) {
			if (i == j)
				break;
			cities[i][j] = cities[j][i] = (rand() % TO_RAND) + FROM_RAND;
		}
	}
}

void TravellingSalesman::ShowCities() {
	std::cout << std::setw(5) << " ";
	for (int i = 0; i < numberOfCities; i++)
		std::cout << std::setw(5) << i;

	std::cout << std::endl;
	for (int i = 0; i < numberOfCities; i++) {
		std::cout << std::setw(5) << i;
		for (int j = 0; j < numberOfCities; j++) {
			std::cout << std::setw(5) << cities[i][j];
		}
		std::cout << std::endl;
	}
}