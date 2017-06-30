#include "KnapsackGreedy.h"

KnapsackGreedy::KnapsackGreedy(Knapsack *knapsack)
{
	this->knapsack = knapsack;
	this->numberOfItems = knapsack->numberOfItems;
	this->knapsackSize = knapsack->knapsackSize;
}

KnapsackGreedy::~KnapsackGreedy()
{
	delete[] knapsackContent;
	delete knapsack;
	counter = 0;
}

void KnapsackGreedy::GreedyAlgorithm() {
	knapsackContent = new Knapsack::item[0];
	for (int i = 0; i < numberOfItems; i++) {
		for (int j = 0; j < numberOfItems - 1; j++) {
			if (knapsack->items[j].ratio < knapsack->items[j + 1].ratio) {
				item tmp = knapsack->items[j + 1];
				knapsack->items[j + 1] = knapsack->items[j];
				knapsack->items[j] = tmp;
			}
		}
	}
	PutIntoKnapsack();
}

void KnapsackGreedy::PutIntoKnapsack() {
	int currentWeight = 0, currentValue = 0;
	for (int i = 0; i < numberOfItems; i++) {
		if ((knapsack->items[i].weight + currentWeight) <= knapsackSize) {
			ExtendKnapsackContent(knapsack->items[i]);
			currentValue += knapsack->items[i].value;
			currentWeight += knapsack->items[i].weight;
		}
	}
	showKnapsackContent(currentValue, currentWeight);
}

void KnapsackGreedy::ExtendKnapsackContent(item freshItem) {
	item *tmp = new item[counter];
	for (int i = 0; i < counter; i++) {
		tmp[i] = knapsackContent[i];
	}
	counter++;
	knapsackContent = new item[counter];
	for (int i = 0; i < counter; i++) {
		if (i == counter - 1) {
			knapsackContent[i] = freshItem;
		}
		else {
			knapsackContent[i] = tmp[i];
		}
	}
	delete[] tmp;
} 

void KnapsackGreedy::showKnapsackContent(int v, int w) {
	std::cout << "This is the list of packed items." << std::endl;
	for (int i = 0; i < counter; i++) {
		std::cout << i << ". item, value: " << knapsack->items[i].value << ", weight:" << knapsack->items[i].weight << std::endl;
	}
	std::cout << "Total weight: " << w << ", total value: " << v << std::endl;
}
