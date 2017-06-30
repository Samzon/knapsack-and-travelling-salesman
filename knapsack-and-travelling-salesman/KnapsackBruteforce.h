#pragma once
#include "Knapsack.h"

class KnapsackBruteforce: protected Knapsack
{
private:
	Knapsack *knapsack;
	struct combinationStructure {
		item **subsets;
		unsigned long long combinationSize;
	};
	combinationStructure *combos;
	int maxI, maxJ, iterator, nOfItems, kSize;
public:
	KnapsackBruteforce(Knapsack *knapsack);
	~KnapsackBruteforce();
	unsigned long long power(int number);
	void BruteforceAlgorithm();
	void GenerateCombination(int size, int step, int *arr, int combinationLength, int index);
	void SelectBestCombination();
	void ShowResults(int v, int w);
};

