#pragma once
#include "Knapsack.h"

class KnapsackDynamicPro: public Knapsack
{
protected:
	int **PIJ, **QIJ;
	Knapsack *knapsack;
public:
	KnapsackDynamicPro(Knapsack *knapsack);
	~KnapsackDynamicPro();
	void DynamicProgrammingAlgorithm();
	void ShowArrays(int **arr);
	int whichIsGreater(int a, int b);
};

