#include "Car.h"

Car::Car()
{
	id = -1;
	number = new char[1];
	number[0] = '\0';
	rentalAmount = -1;
	pos.first = -1;
	pos.second = -1;
	isRented = true;
}

Car::Car(int _id, char* _number, double _rentalAmount, std::pair<int, int>& _pos, bool _isRented)
	: id(_id), rentalAmount(_rentalAmount), pos(_pos), isRented(_isRented)
{
	number = new char[strlen(_number) + 1];
	strcpy(number, _number);
}

Car::Car(const Car& other)
{
	id = other.id;
	rentalAmount = other.rentalAmount;
	pos = other.pos;
	isRented = other.isRented;
	number = new char[strlen(other.number) + 1];
	strcpy(number, other.number);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other) 
	{
		this->~Car();
		id = other.id;
		rentalAmount = other.rentalAmount;
		pos = other.pos;
		isRented = other.isRented;
		number = new char[strlen(other.number) + 1];
		strcpy(number, other.number);
	}
	return *this;
}

Car::~Car()
{
	delete[] number;
}

int Car::get_id() const
{
	return id;
}

const char* Car::get_number() const
{
	return number;
}

double Car::get_rentalAmount() const
{
	return rentalAmount;
}

std::pair<int, int> Car::get_pos() const
{
	return pos;
}

bool Car::get_isRented() const
{
	return isRented;
}

void Car::set_pos(std::pair<int, int> _pos)
{
	pos = _pos;
}

void Car::set_isRented(bool _isRented)
{
	isRented = _isRented;
}
