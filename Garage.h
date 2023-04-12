#pragma once

#include "Car.h"

class Garage {
private:
    int capacity;
    int size;
    Car** cars;

    void resize() 
    {
        int newCapacity = capacity * 2;
        Car** newCars = new Car * [newCapacity];
        for (int i = 0; i < size; ++i) 
        {
            newCars[i] = cars[i];
        }
        delete[] cars;
        cars = newCars;
        capacity = newCapacity;
    }

    int findCarIndex(int carId) const 
    {
        for (int i = 0; i < size; ++i) 
        {
            if (cars[i] != nullptr && cars[i]->get_id() == carId) 
            {
                return i;
            }
        }
        return -1;
    }
public:
    Garage();
    Garage(const Garage& other);
    Garage& operator=(const Garage& other);
    ~Garage();

    void addCar(const Car& car);
    void removeCar(int carId);
    void printCars() const;
};
