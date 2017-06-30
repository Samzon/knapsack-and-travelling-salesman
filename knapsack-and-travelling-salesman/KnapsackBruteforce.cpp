#include "KnapsackBruteforce.h"

KnapsackBruteforce::KnapsackBruteforce(Knapsack *knapsack)
{
	this->knapsack = knapsack;
	this->nOfItems = this->knapsack->numberOfItems;
	this->kSize = this->knapsack->knapsackSize;
	combos = new combinationStructure[nOfItems];
}

KnapsackBruteforce::~KnapsackBruteforce()
{
	delete[] combos;
}

void KnapsackBruteforce::BruteforceAlgorithm() {
	unsigned long long tmpSize = 0;
	for (int i = 0; i < nOfItems; i++) {
		if (i + 1 == nOfItems) {
			tmpSize = 1;
		}
		else {
			tmpSize = power(nOfItems) / (power(i + 1)*power(nOfItems - (i + 1)));
		}
		combos[i].combinationSize = tmpSize;
		combos[i].subsets = new item*[tmpSize];
	}

	for (int i = 0; i < nOfItems; i++) {
		for (int j = 0; j < combos[i].combinationSize; j++) {
			combos[i].subsets[j] = new item[i + 1];
		}
	}

	int *arr = new int[kSize];
	for (int i = 0; i < nOfItems; i++) {
		iterator = 0;
		GenerateCombination(kSize, i + 1, arr, i + 1, i);
	}
	delete[] arr;
	SelectBestCombination();
}

void KnapsackBruteforce::GenerateCombination(int size, int step, int *arr, int combinationLength, int index) {
	for (int k = size; k >= step; k--) {
		arr[step - 1] = k;
		if (step > 1) {
			GenerateCombination(k - 1, step - 1, arr, combinationLength, index);
		}
		else {
			for (int i = 0; i < combinationLength; i++) {
				item tmp = knapsack->items[(arr[i] - 1)];
				combos[index].subsets[iterator][i] = tmp;
			}
			iterator++;
		}
	}
}

void KnapsackBruteforce::SelectBestCombination() {
	int sumWeight, sumValue, currentWeight = 0, currentValue = 0;
	for (int i = 0; i < nOfItems; i++) {
		for (int j = 0; j < combos[i].combinationSize; j++) {
			sumWeight = 0;
			sumValue = 0;
			for (int k = 0; k < i + 1; k++) {
				sumWeight += combos[i].subsets[j][k].weight;
				sumValue += combos[i].subsets[j][k].value;
			}
			if (sumValue > currentValue && sumWeight <= kSize) {
				currentValue = sumValue;
				currentWeight = sumWeight;
				maxI = i;
				maxJ = j;
			}
		}
	}
	ShowResults(currentValue, currentWeight);
}

unsigned long long KnapsackBruteforce::power(int number) {
	unsigned long long result = 1;
	for (int i = 1; i <= number; i++) {
		result *= i;
	}
	return result;
}

void KnapsackBruteforce::ShowResults(int v, int w) {
	std::cout << "\nThis is the list of packed items - BRUTEFORCE." << std::endl;
	for (int i = 0; i < (maxI + 1); i++) {
		std::cout << i << ". item, value: " << combos[maxI].subsets[maxJ][i].value << ", weight: " << combos[maxI].subsets[maxJ][i].weight << std::endl;
	}
	std::cout << "Total weight: " << w << "/" << kSize << ", total value: " << v << std::endl;
}