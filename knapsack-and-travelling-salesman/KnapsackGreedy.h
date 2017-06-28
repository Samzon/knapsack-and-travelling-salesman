#pragma once
#include "Knapsack.h"

class KnapsackGreedy: public Knapsack
{
protected:
	Knapsack *knapsack;
	item *knapsackContent;
	int counter = 0;
	int *ratio;
public:
	KnapsackGreedy(Knapsack *knapsack);
	~KnapsackGreedy();
	void GreedyAlgorithm();
	void PutIntoKnapsack();
	void ExtendKnapsackContent(item freshItem);
	void showKnapsackContent(int v, int w);
};

