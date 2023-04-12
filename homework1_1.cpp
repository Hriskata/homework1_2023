#include <iostream>
#include <string>
#include <vector>

class Car {
public:
    Car(int id, const std::string& number, double rentalAmount, int posX, int posY)
        : id_(id), number_(number), rentalAmount_(rentalAmount), posX_(posX), posY_(posY), isRented_(false) {}

    int getId() const {
        return id_;
    }

    std::string getNumber() const {
        return number_;
    }

    double getRentalAmount() const {
        return rentalAmount_;
    }

    int getPosX() const {
        return posX_;
    }

    int getPosY() const {
        return posY_;
    }

    bool getIsRented() const {
        return isRented_;
    }

    void setIsRented(bool isRented) {
        isRented_ = isRented;
    }

private:
    int id_;
    std::string number_;
    double rentalAmount_;
    int posX_;
    int posY_;
    bool isRented_;
};

class Customer {
public:
    Customer(const std::string& name, const std::string& driverLicense, double accountBalance, int posX, int posY)
        : name_(name), driverLicense_(driverLicense), accountBalance_(accountBalance), posX_(posX), posY_(posY) {}

    std::string getName() const {
        return name_;
    }

    std::string getDriverLicense() const {
        return driverLicense_;
    }

    double getAccountBalance() const {
        return accountBalance_;
    }

    int getPosX() const {
        return posX_;
    }

    int getPosY() const {
        return posY_;
    }

    void rentCar(Car& car, double rentalAmount) {
        if (!car.getIsRented() && accountBalance_ >= rentalAmount) {
            car.setIsRented(true);
            accountBalance_ -= rentalAmount;
            std::cout << "Car with ID " << car.getId() << " has been rented by " << name_ << " for "
                << rentalAmount << " BGN." << std::endl;
        }
        else {
            std::cout << "Unable to rent the car. Either the car is already rented or insufficient account balance."
                << std::endl;
        }
    }

    void askCarDistance(const Car& car) const {
        int distance = abs(posX_ - car.getPosX()) + abs(posY_ - car.getPosY());
        std::cout << "The distance between you and the car with ID " << car.getId() << " is " << distance << " km."
            << std::endl;
    }

private:
    std::string name_;
    std::string driverLicense_;
    double accountBalance_;
    int posX_;
    int posY_;
};

int main() {
    // Create some sample cars
    Car car1(1, "AB1234", 30.0, 2, 3);
    Car car2(2, "BC5678", 25.0, 5, 7);

    // Create a sample customer
    Customer customer("John Smith", "DL123456", 50.0, 1, 1);

    // Rent a car
    customer.rentCar(car1, 30.0);

    // Ask for car distance
    customer.askCarDistance(car1);

    return 0;
}
