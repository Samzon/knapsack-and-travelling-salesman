#include "List.h"



List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}


List::~List()
{
}

void List::AddElement(int city, int value) {
	element *e = new element();
	e->value = value;
	e->city = city;
	e->next = nullptr;
	e->prev = nullptr;
	element *pointer = new element();
	if (size == 0) {
		size++;
		head = e;
		tail = e;
	}
	else {
		size++;
		tail->next = e;
		e->prev = tail;
		tail = e;
	}
}

bool List::removeLast() {
	if (size != 0) {
		if (size == 1) {
			size--;
			delete tail;
			tail = nullptr;
			head = nullptr;
			return true;
		}
		else {
			element *tmp = new element();
			tail->next->prev = nullptr;
			tmp = tail->prev;
			delete tail;
			tail = tmp;
			return true;
		}
		return false;
	}
}

void List::DisplayList() {
	int sumValue = 0;
	std::cout << "\nOur rote: ";
	if (size != 0) {
		element *pointer;
		pointer = head;
		while (true) {
			std::cout << pointer->city;
			sumValue = pointer->value;
			if (pointer->next == nullptr)
				break;
			std::cout << " -> ";
			pointer = pointer->next;
		}
	}
	std::cout << "\nLength of this route is: " << sumValue << std::endl;
}
