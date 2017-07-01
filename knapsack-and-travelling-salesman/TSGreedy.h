#pragma once
#include "TravellingSalesman.h"
#include "List.h"

class TSGreedy: protected TravellingSalesman
{
private:
	List *route;
	int **matrix;
public:
	TSGreedy(int firstCity, TravellingSalesman *graph);
	~TSGreedy();
	void GreedyAlgorithm();
};

