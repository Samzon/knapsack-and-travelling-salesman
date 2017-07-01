#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>

#define FROM_RAND 50
#define TO_RAND 250

class TravellingSalesman
{
private:
	friend class TSGreedy;
	friend class TSBruteforce;
	int **cities;
	int numberOfCities, firstCity;
public:
	TravellingSalesman();
	TravellingSalesman(int numberOfCities);
	~TravellingSalesman();
	void FillGraphAuto();
	void FillGraphManually();
	void ShowCities();
};

