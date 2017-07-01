#pragma once
#include "List.h"
#include "TSBruteforce.h"
#include "TravellingSalesman.h"
#include <algorithm>

class TSBruteforce: protected TravellingSalesman
{
private:
	List *route;
	int **matrix;
public:
	TSBruteforce(int firstCity, TravellingSalesman *graph);
	~TSBruteforce();
	void BruteforceAlgorithm();
};

