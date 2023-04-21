#pragma once
#include "Item.h"


class Store {
private:
	Item** store;
	size_t size;
	size_t capacity;
public:
	Store();
	Store(size_t capacity);
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	bool checkAvailability(const char* _name);
	void sell(const char* _name);
	void add(Item* item);
	friend std::ostream& operator<<(std::ostream os, const Store& store);
	Store operator+(const Store& other) const;
};