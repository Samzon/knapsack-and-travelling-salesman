#pragma once
#include <iostream>

class List
{
private:
	struct element {
		int city, value;
		element *next, *prev;
	};
	element *head, *tail;
	int size;
public:
	List();
	~List();
	void AddElement(int city, int value);
	bool removeLast();
	void DisplayList();
};

