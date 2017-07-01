#include <iostream>
#include "Knapsack.h"
#include "KnapsackGreedy.h"
#include "KnapsackDynamicPro.h"
#include "KnapsackBruteforce.h"

#include "TravellingSalesman.h"
#include "TSGreedy.h"
#include "TSBruteforce.h"

int choice;

void KnapsackProblem() {
	int numberOfItems, knapsackSize;
	std::cout << "\nHow many items do you have? ";
	std::cin >> numberOfItems;
	std::cout << "\nWhat's the size of your knapsack? ";
	std::cin >> knapsackSize;
	Knapsack *ks = new Knapsack(numberOfItems, knapsackSize);
	KnapsackGreedy *ksg;
	KnapsackDynamicPro *ksdp;
	KnapsackBruteforce *ksb;
	do {
		std::cout
			<< "\n__________________________________\n\n"
			<< "FILL AN ITEMS ARRAY: \n"
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
			<< "0 - Show me elements to pack\n"
			<< "ALGORITHMS:\n"
			<< "1 - Bruteforce\n"
			<< "2 - Greedy\n"
			<< "3 - Dynamic Programming\n"
			<< "DEFAULT - Exit to main menu\n\n"
			<< "What do you want to do?\n"
			<< "\n__________________________________\n";
		std::cin >> choice;
		switch (choice) {
		case 0:
			ks->ShowItems();
			break;
		case 1:
			ksb = new KnapsackBruteforce(ks);
			ksb->BruteforceAlgorithm();
			break;
		case 2:
			ksg = new KnapsackGreedy(ks);
			ksg->GreedyAlgorithm();
			break;
		case 3:
			ksdp = new KnapsackDynamicPro(ks);
			ksdp->DynamicProgrammingAlgorithm();
			break;
		default:
			return;
			break;
		}
	}
}

void TravellingSalesmanProblem() {
	int numberOfCities, firstCity;
	std::cout << "Type number of cities: ";
	std::cin >> numberOfCities;
	std::cout << "From which city do you want to start? ";
	std::cin >> firstCity;
	TravellingSalesman *ts = new TravellingSalesman(numberOfCities);
	TSGreedy *tsg;
	TSBruteforce *tsb;
	do {
		std::cout
			<< "\n__________________________________\n\n"
			<< "CREATE A HAMILTONIAN GRAPH: \n"
			<< "1 - Randomly\n"
			<< "2 - Manually\n"
			<< "\n__________________________________\n";
		std::cin >> choice;
		switch (choice) {
		case 1:
			ts->FillGraphAuto();
			break;
		case 2:
			ts->FillGraphManually();
			break;
		}
	} while (choice != 1 && choice != 2);

	while (true) {
		std::cout
			<< "\n__________________________________\n\n"
			<< "0 - Show me graph\n"
			<< "ALGORITHMS:\n"
			<< "1 - Bruteforce\n"
			<< "2 - Greedy\n"
			<< "DEFAULT - Exit to main menu\n\n"
			<< "What do you want to do?\n"
			<< "\n__________________________________\n";
		std::cin >> choice;
		switch (choice) {
		case 0:
			ts->ShowCities();
			break;
		case 1:
			tsb = new TSBruteforce(firstCity, ts);
			tsb->BruteforceAlgorithm();
			break;
		case 2:
			tsg = new TSGreedy(firstCity, ts);
			tsg->GreedyAlgorithm();
			break;
		default:
			return;
			break;
		}
	}
}


int main() {
	while (true) {
		std::cout 
			<< "_________________________________\n\n"
			<< "1 - Knapsack Problem\n"
			<< "2 - Travelling Salesman Problem\n"
			<< "DEFAULT - Exit\n\n"
			<< "Select problem to solve!"
			<< "\n__________________________________\n"
			<< std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
			KnapsackProblem();
			break;
		case 2:
			TravellingSalesmanProblem();
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}