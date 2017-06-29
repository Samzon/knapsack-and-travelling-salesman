#include <iostream>
#include "Knapsack.h"
#include "KnapsackGreedy.h"
#include "KnapsackDynamicPro.h"

int choice;

void KnapsackProblem() {
	int numberOfItems, knapsackSize;
	std::cout << "\nHow many items do you have?";
	std::cin >> numberOfItems;
	std::cout << "\nWhat's the size of your knapsack?";
	std::cin >> knapsackSize;
	Knapsack *ks = new Knapsack(numberOfItems, knapsackSize);
	KnapsackGreedy *ksg;
	KnapsackDynamicPro *ksdp;
	do {
		std::cout
			<< "\n__________________________________\n\n"
			<< "FILL ITEMS ARRAY: \n"
			<< "1 - Randomly\n"
			<< "2 - Manually\n"
			<< "\n__________________________________\n";
		std::cin >> choice;
		switch (choice) {
		case 1:
			ks->FillItemsRand();
			break;
		case 2:
			ks->FillItemsManually();
			break;
		}
	} while (choice != 1 && choice != 2);

	while (true) {
		std::cout
			<< "\n__________________________________\n\n"
			<< "0 - Show me elements to pack"
			<< "ALGORITHMS:\n"
			<< "1 - Bruteforce\n"
			<< "2 - Greedy\n"
			<< "3 - Dynamic Programming\n"
			<< "\n__________________________________\n"
			<< "What do you want to do?\n";
		std::cin >> choice;
		switch (choice) {
		case 0:
			ks->ShowItems();
			break;
		case 1:
			
			break;
		case 2:
			ksg = new KnapsackGreedy(ks);
			ksg->GreedyAlgorithm();
			break;
		case 3:
			ksdp = new KnapsackDynamicPro(ks);
			ksdp->DynamicProgrammingAlgorithm();
			break;
		}
	}

}

void TravellingSalesman() {

}


int main() {
	while (true) {
		std::cout 
			<< "\n__________________________________\n\n"
			<< "1 - Knapsack Problem\n"
			<< "2 - Travelling Salesman Problem\n"
			<< "DEFAULT - Exit\n"
			<< "\n__________________________________\n"
			<< std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			KnapsackProblem();
			break;
		case 2:
			TravellingSalesman();
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}