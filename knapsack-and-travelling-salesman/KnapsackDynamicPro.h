#pragma once
#include "Knapsack.h"

class KnapsackDynamicPro: protected Knapsack
{
private:
	int **valuesArray, **weightsArray;
	Knapsack *knapsack;
public:
	KnapsackDynamicPro(Knapsack *knapsack);
	~KnapsackDynamicPro();
	void DynamicProgrammingAlgorithm();
	void ShowArrays(int **arr);
	int whichIsGreater(int a, int b);
};

