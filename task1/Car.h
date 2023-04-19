#pragma once

#include <iostream>

class Car {
private:
    int id;
    char* number;
    double rentalAmount;
    std::pair<int, int> pos;
    bool isRented;

public:
    Car();
    Car(int _id, char* _number, double _rentalAmount, std::pair<int, int>& _pos, bool isRented);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();

    // Function to get ID
    int get_id() const;

    // Function to get number
    const char* get_number() const;

    // Function to get rental amount
    double get_rentalAmount() const;

    // Function to get position on the car
    std::pair<int, int> get_pos() const;

    // Function to get the status of the car - rented/not rented
    bool get_isRented() const;

    // Function to set the position on the car
    void set_pos(std::pair<int, int> _pos);

    // Function to set the status of the car - rent/free
    void set_isRented(bool _isRented);
};

