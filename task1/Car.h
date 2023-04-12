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

    int get_id() const;
    const char* get_number() const;
    double get_rentalAmount() const;
    std::pair<int, int> get_pos() const;
    bool get_isRented() const;

    void set_pos(std::pair<int, int> _pos);
    void set_isRented(bool _isRented);
};

