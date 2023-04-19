#pragma once
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <utility>
#include "Car.h"

class Customer {
private:
    char* name;
    char* licenseNumber;
    double accountBalance;
    std::pair<int, int> posCus;

public:
    Customer();
    Customer(const char* _name, const char* _licenseNumber, double _accountBalance, std::pair<int, int> _pos);
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);
    ~Customer();

    // Function to calculate the distance between the customer and a car by car ID
    double get_distanceToCar(int car_id, const std::unordered_map<int, Car>& cars) const;

    // Function to rent a car by car ID
    void RentCar(int car_id, std::unordered_map<int, Car>& cars);
};