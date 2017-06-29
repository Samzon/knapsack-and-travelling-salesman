#include "KnapsackDynamicPro.h"



KnapsackDynamicPro::KnapsackDynamicPro(Knapsack *knapsack)
{
	this->knapsack = knapsack;
	PIJ = new int*[knapsack->numberOfItems + 1];
	QIJ = new int*[knapsack->numberOfItems + 1];
	for (int i = 0; i <= knapsack->numberOfItems; i++) {
		PIJ[i] = new int[knapsack->knapsackSize + 1];
		QIJ[i] = new int[knapsack->knapsackSize + 1];
	}

}


KnapsackDynamicPro::~KnapsackDynamicPro()
{
}

void KnapsackDynamicPro::DynamicProgrammingAlgorithm() {
	for (int i = 0; i <= knapsack->numberOfItems; i++) {
		for (int j = 0; j <= knapsack->knapsackSize; j++) {
			if (i == 0 || j == 0) {
				PIJ[i][j] = 0;
				QIJ[i][j] = 0;
			}
			else if (knapsack->items[i - 1].weight <= j) {
				PIJ[i][j] = whichIsGreater((knapsack->items[i - 1].value + PIJ[i - 1][j - (knapsack->items[i - 1].weight)]), PIJ[i - 1][j]);
				QIJ[i][j] = whichIsGreater((knapsack->items[i - 1].weight + QIJ[i - 1][j - (knapsack->items[i - 1].weight)]), QIJ[i - 1][j]);
			}
			else {
				PIJ[i][j] = PIJ[i - 1][j];
				QIJ[i][j] = PIJ[i - 1][j];
			}
		}
	}
	std::cout << "VALUES ARRAY: ";
	ShowArrays(PIJ);
	std::cout << "WEIGHTS ARRAY: ";
	ShowArrays(QIJ);
	std::cout << "\n";
	std::cout << "Value packed in knapsack: " << PIJ[knapsack->numberOfItems][knapsack->knapsackSize] << std::endl;
	std::cout << "Total weight of packed knapsack: " << QIJ[knapsack->numberOfItems][knapsack->knapsackSize] << "/" << size << std::endl;
	std::cout << "\n";
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
