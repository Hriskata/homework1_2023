#include "Store.h"

Store::Store() : size(0), capacity(1)
{
	store = new Item * [capacity];
}

Store::Store(size_t _capacity) : size(0), capacity(_capacity)
{
	store = new Item * [capacity];
}

Store::Store(const Store& other) : size(other.size), capacity(other.capacity)
{
	store = new Item * [other.capacity];
	for (size_t i = 0; i < size; i++)
	{
		store[i] = new Item(*other.store[i]);
	}
}

Store& Store::operator=(const Store& other)
{
	if (this != &other)
	{
		this->~Store();
		Store(other);
	}
	return *this;
}

Store::~Store()
{
	for (size_t i = 0; i < size; i++)
	{
		delete store[i];
	}
	delete[] store;
}

bool Store::checkAvailability(const char* _name)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (store[i]->get_name() == _name && store[i]->get_availability() != 0)
			return true;
	}
	return false;
}

void Store::sell(const char* _name)
{
	for (size_t i = 0; i < size; i++)
	{
		if (store[i]->get_name() == _name && store[i]->get_availability() != 0)
		{
			store[i]->set_availability();
			if (store[i]->get_availability() == 0)
			{
				std::swap(store[i], store[size - 1]);
				store[size--]->~Item();
			}
		}
	}
}

void Store::add(Item* item)
{
	if (this->size == this->capacity)
	{
		capacity *= 2;
		Item** newStore = new Item * [capacity];
		newStore = store;
		this->~Store();
		store = newStore;
	}
	store[size++] = item;
}
