#include "Customer.h"

Customer::Customer()
{
	name = new char[1];
	name[0] = '\0';
	licenseNumber = new char[1];
	licenseNumber = '\0';
	accountBalance = 0;
	posCus.first = -1;
	posCus.second = -1;

}

Customer::Customer(const char* _name, const char* _licenseNumber, double _accountBalance, std::pair<int, int> _pos)
					: accountBalance(_accountBalance), posCus(_pos) {
		name = new char[strlen(name) + 1];
		strcpy(name, _name);
		licenseNumber = new char[strlen(_licenseNumber) + 1];
		strcpy(licenseNumber, _licenseNumber);
	}

Customer::Customer(const Customer& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	licenseNumber = new char[strlen(other.licenseNumber) + 1];
	strcpy(licenseNumber, other.licenseNumber);
	accountBalance = other.accountBalance;
	posCus = other.posCus;

}

Customer& Customer::operator=(const Customer& other)
{
	if (this != &other)
	{
		this->~Customer();
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		licenseNumber = new char[strlen(other.licenseNumber) + 1];
		strcpy(licenseNumber, other.licenseNumber);
		accountBalance = other.accountBalance;
		posCus = other.posCus;
	}
	return *this;
}

Customer::~Customer()
{
	delete[] name;
	delete[] licenseNumber;
}

double Customer::get_distanceToCar(int carId, const std::unordered_map<int, Car>& cars) const
{
	if (cars.find(carId) != cars.end()) {
		const Car& car = cars.at(carId);
		double distance = std::sqrt(std::pow(posCus.first - car.get_pos().first, 2) + std::pow(posCus.second - car.get_pos().second, 2));
		return distance;
	}
	else {
		std::cout << "Car with ID " << carId << " not found." << std::endl;
		return -1;
	}
}

void Customer::RentCar(int carId, std::unordered_map<int, Car>& cars)
{
	if (cars.find(carId) != cars.end()) {
		Car& car = cars.at(carId);
		if (car.get_isRented() && accountBalance >= car.get_rentalAmount()) {
			car.set_isRented(false);
			accountBalance -= car.get_rentalAmount();
			std::cout << "Car with ID " << carId << " has been rented." << std::endl;
		}
		else if (!car.get_isRented()) {
			std::cout << "Car with ID " << carId << " is already rented." << std::endl;
		}
		else {
			std::cout << "Insufficient account balance to rent car with ID " << carId << "." << std::endl;
		}
	}
	else {
		std::cout << "Car with ID " << carId << " not found." << std::endl;
	}
}


