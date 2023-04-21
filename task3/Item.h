#pragma once
#include <iostream>

class Item{
private:
	char* name;
	size_t availability;
public:
	Item();
	Item(const char* name, size_t availability);
	Item(const Item& other);
	Item& operator=(const Item& other);
	~Item();

	const char* get_name() const;
	size_t get_availability() const;
	void set_availability();
};
