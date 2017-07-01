#include "TSBruteforce.h"



TSBruteforce::TSBruteforce(int firstCity, TravellingSalesman *graph)
{
	this->firstCity = firstCity;
	route = new List();
	this->matrix = graph->cities;
	this->numberOfCities = graph->numberOfCities;
}


TSBruteforce::~TSBruteforce()
{
}

void TSBruteforce::BruteforceAlgorithm() {
	int *visitedArray = new int[numberOfCities - 1];
	int *citiesToCheck = new int[numberOfCities - 1];
	int min, currentValue;

	for (int i = 0, n = 0; i < numberOfCities; i++) {
		if (i != firstCity) {
			visitedArray[n] = i;
			citiesToCheck[n] = i;
			n++;
		}
	}

	min = INT_MAX;
		 
	if(numberOfCities > 1)
		do {
			currentValue = 0;
			currentValue += matrix[firstCity][visitedArray[0]];
			for (int i = 1; i < numberOfCities - 1; i++) {
				currentValue += matrix[visitedArray[i - 1]][visitedArray[i]];
			}
			currentValue += matrix[visitedArray[numberOfCities - 2]][firstCity];
			if (currentValue < min) {
				for (int i = 0; i < numberOfCities - 1; i++) {
					citiesToCheck[i] = visitedArray[i];
				}
				min = currentValue;
			}
		} while (std::next_permutation(visitedArray, visitedArray + (numberOfCities - 1)));
		
		route->AddElement(firstCity, 0);
		route->AddElement(citiesToCheck[0], matrix[firstCity][citiesToCheck[0]]);
		for (int i = 1; i < numberOfCities - 1; i++) {
			route->AddElement(citiesToCheck[i], matrix[citiesToCheck[i - 1]][citiesToCheck[i]]);
		}
		route->AddElement(firstCity, matrix[citiesToCheck[numberOfCities - 2]][firstCity]);

		delete[] citiesToCheck;

		route->DisplayList();
}
