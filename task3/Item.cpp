#include "Item.h"

Item::Item()
{
	name = new char[1];
	name = '\0';
	availability = 0;
}

Item::Item(const char* _name, size_t _availability)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	availability = _availability;
}

Item::Item(const Item& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	availability = other.availability;
}

Item& Item::operator=(const Item& other)
{
	if (this != &other)
	{
		this->~Item();
		Item(other);
	}
	return *this;
}

Item::~Item()
{
	delete[] this->name;
}

const char* Item::get_name() const
{
	return name;
}

size_t Item::get_availability() const
{
	return availability;
}

void Item::set_availability()
{
	availability -= 1;
}
