#pragma once
#include "Knapsack.h"

class KnapsackBruteforce: public Knapsack
{
protected:
	Knapsack *knapsack;
	struct combinationStructure {
		item **subsets;
		unsigned long long combinationSize;
	};
	combinationStructure *combos;
	int maxI, maxJ;
public:
	KnapsackBruteforce(Knapsack *knapsack);
	~KnapsackBruteforce();
	int power(int number);
	void BruteforceAlgorithm();
};

