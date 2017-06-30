#include "Knapsack.h"

Knapsack::Knapsack() {}

Knapsack::Knapsack(int numberOfItems, int knapsackSize)
{
	this->numberOfItems = numberOfItems;
	this->knapsackSize = knapsackSize;
	items = new item[numberOfItems];
}

Knapsack::~Knapsack()
{
	delete[] items;
}

void Knapsack::FillItemsManually() {
	for (int i = 0; i < numberOfItems; i++) {
		std::cout << "Type data of " << i << ". element." << std::endl;
		std::cout << "Value: ";
		std::cin >> items[i].value;
		std::cout << std::endl;
		std::cout << "Weight: ";
		std::cin >> items[i].weight;
		std::cout << std::endl;
		items[i].ratio = items[i].value / items[i].weight;
	}
}

void Knapsack::FillItemsRand() {
	srand(time(NULL));
	for (int i = 0; i < numberOfItems; i++) {
		items[i].value = (std::rand() & 190) + 10;
		items[i].weight = (std::rand() & (knapsackSize - 1) ) + 1;
		items[i].ratio = items[i].value / items[i].weight;
	}
}

void Knapsack::ShowItems() {
	for (int i = 0; i < numberOfItems; i++) {
		std::cout << i << ". item, value: " << items[i].value << ", weight: " << items[i].weight << ", ratio: " << items[i].ratio << std::endl;
	}
}

