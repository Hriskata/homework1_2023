#include "Garage.h"

Garage::Garage():capacity(1), size(0), cars(new Car* [capacity])
{}

Garage::Garage(const Garage& other): capacity(other.capacity), size(other.size)
{
	cars = new Car * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		cars[i] = new Car(*other.cars[i]);
	}
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other) 
    {
        for (int i = 0; i < size; ++i) 
        {
            delete cars[i];
        }
        delete[] cars;

        capacity = other.capacity;
        size = other.size;
        cars = new Car * [capacity];
        for (int i = 0; i < size; ++i) 
        {
            cars[i] = new Car(*other.cars[i]);
        }
	}
	return *this;
}

Garage::~Garage()
{
    for (int i = 0; i < size; ++i) 
    {
        delete cars[i];
    }
    delete[] cars;
}

void Garage::addCar(const Car& car)
{
    if (size == capacity) 
    {
        resize();
    }
    cars[size] = new Car(car);
    ++size;
}

void Garage::removeCar(int carId)
{
    int index = findCarIndex(carId);
    if (index != -1) {
        delete cars[index];
        cars[index] = nullptr;
        // Move the last car to the removed car's position
        cars[index] = cars[size - 1];
        cars[size - 1] = nullptr;
        --size;
    }
}

void Garage::printCars() const
{
    std::cout << "Cars in the garage:" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (cars[i] != nullptr) {
            std::cout << "Car ID: " << cars[i]->get_id() << ", Car Number: " << cars[i]->get_number()
                << ", Rental Amount: " << cars[i]->get_rentalAmount()
                << ", Position: (" << cars[i]->get_pos().first << ", " << cars[i]->get_pos().second
                << ")" << std::endl;
        }
    }
}
