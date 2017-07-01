#include "TSGreedy.h"



TSGreedy::TSGreedy(int firstCity, TravellingSalesman *graph)
{
	this->firstCity = firstCity;
	route = new List();
	route->AddElement(firstCity, 0);
	this->matrix = graph->cities;
	this->numberOfCities = graph->numberOfCities;
}


TSGreedy::~TSGreedy()
{
	delete route;
}

void TSGreedy::GreedyAlgorithm() {
	bool *wasVisited = new bool[numberOfCities];
	int min, current, destination;
	for (int i = 0; i < numberOfCities; i++) {
		wasVisited[i] = false;
	}

	current = firstCity;

	for (int i = 0; i < numberOfCities - 1; i++) {
		wasVisited[current] = true;
		min = INT_MAX;
		for (int j = 0; j < numberOfCities; j++) {
			if (!wasVisited[j] && (matrix[current][j] < min)) {
				min = matrix[current][j];
				destination = j;
			}
		}
		route->AddElement(destination, matrix[current][destination]);
		current = destination;
	}
	route->AddElement(firstCity, matrix[current][firstCity]);
	delete[] wasVisited;

	route->DisplayList();
}

