#include "KnapsackBruteforce.h"



KnapsackBruteforce::KnapsackBruteforce(Knapsack *knapsack)
{
	this->knapsack = knapsack;
	combos = new combinationStructure[knapsack->numberOfItems];
}


KnapsackBruteforce::~KnapsackBruteforce()
{
}

void KnapsackBruteforce::BruteforceAlgorithm() {
	for (int i = 0; i < knapsack->numberOfItems; i++) {
		if (i == knapsack->numberOfItems) {
			combos[i].combinationSize = 1;
		}
		else {
			combos[i].combinationSize = power(knapsack->numberOfItems) / (power(i + 1)*power(knapsack->numberOfItems - (i + 1)));
		}
		combos[i].subsets = new item*[combos[i].combinationSize];
	}

	for (int i = 0; i < knapsack->numberOfItems; i++) {
		for (int j = 0; j < combos[i].combinationSize; j++) {
			combos[i].subsets[j] = new item[i + 1];
		}
	}
}

int KnapsackBruteforce::power(int number) {
	unsigned long long result;
	for (int i = 1; i <= number; i++) {
		result *= i;
	}
	return result;
}