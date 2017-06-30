#pragma once
#include <iostream>
#include <ctime>

class Knapsack
{
private:
	friend class KnapsackGreedy;
	friend class KnapsackDynamicPro;
	friend class KnapsackBruteforce;
	struct item {
		int value, weight, ratio;
	};
	int numberOfItems, knapsackSize;
	item *items;
public:
	Knapsack();
	Knapsack(int numberOfItems, int knapsackSize);
	~Knapsack();
	void FillItemsManually();
	void FillItemsRand();
	void ShowItems();
};

