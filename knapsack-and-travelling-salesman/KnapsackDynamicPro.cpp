#include "KnapsackDynamicPro.h"

KnapsackDynamicPro::KnapsackDynamicPro(Knapsack *knapsack)
{
	this->knapsack = knapsack;
	valuesArray = new int*[knapsack->numberOfItems + 1];
	weightsArray = new int*[knapsack->numberOfItems + 1];
	for (int i = 0; i <= knapsack->numberOfItems; i++) {
		valuesArray[i] = new int[knapsack->knapsackSize + 1];
		weightsArray[i] = new int[knapsack->knapsackSize + 1];
	}
}

KnapsackDynamicPro::~KnapsackDynamicPro()
{
	delete[] valuesArray;
	delete[] weightsArray;
}

void KnapsackDynamicPro::DynamicProgrammingAlgorithm() {
	for (int i = 0; i <= knapsack->numberOfItems; i++) {
		for (int j = 0; j <= knapsack->knapsackSize; j++) {
			if (i == 0 || j == 0) {
				valuesArray[i][j] = 0;
				weightsArray[i][j] = 0;
			}
			else if (knapsack->items[i - 1].weight <= j) {
				valuesArray[i][j] = whichIsGreater((knapsack->items[i - 1].value + valuesArray[i - 1][j - (knapsack->items[i - 1].weight)]), valuesArray[i - 1][j]);
				weightsArray[i][j] = whichIsGreater((knapsack->items[i - 1].weight + weightsArray[i - 1][j - (knapsack->items[i - 1].weight)]), weightsArray[i - 1][j]);
			}
			else {
				valuesArray[i][j] = valuesArray[i - 1][j];
				weightsArray[i][j] = weightsArray[i - 1][j];
			}
		}
	}
	std::cout << "\nVALUES ARRAY: \n";
	ShowArrays(valuesArray);
	std::cout << "\n\nWEIGHTS ARRAY: \n";
	ShowArrays(weightsArray);
	std::cout << "\n";
	std::cout << "\nTotal weight: " << weightsArray[knapsack->numberOfItems][knapsack->knapsackSize] << ", total value: " << valuesArray[knapsack->numberOfItems][knapsack->knapsackSize] << std::endl;
}

void KnapsackDynamicPro::ShowArrays(int **arr) {
	for (int i = 0; i < knapsack->numberOfItems; i++) {
		std::cout << std::endl;
		for (int j = 0; j < knapsack->knapsackSize; j++) {
			std::cout << arr[i][j] << " ";
		}
	}
}

int KnapsackDynamicPro::whichIsGreater(int a, int b) {
	return (a > b) ? a : b;
}
