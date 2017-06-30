#pragma once
#include "Knapsack.h"

class KnapsackGreedy: protected Knapsack
{
private:
	Knapsack *knapsack;
	item *knapsackContent;
	int counter = 0;
public:
	KnapsackGreedy(Knapsack *knapsack);
	~KnapsackGreedy();
	void GreedyAlgorithm();
	void PutIntoKnapsack();
	void ExtendKnapsackContent(item freshItem);
	void showKnapsackContent(int v, int w);
};

