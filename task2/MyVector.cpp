#include "MyVector.h"

template<class T>
MyVector<T>::MyVector()
{
	this->myVector = new T[1];
	myVector[0] = nullptr;
	this->capacity = 1;
	iterator = 0;
}

template<class T>
MyVector<T>::MyVector(const T& _vector, std::size_t _iterator, std::size_t _capacity) : iterator(_iterator), capacity(_capacity)
{
	this->myVector = new T * [capacity];
	for (size_t i = 0; i < capacity; i++) 
	{
		myVector[i] = _vector[i];
	}
}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	this->capacity = other.capacity;
	this->iterator = 0;
	this->myVector = new T * [capacity];

	while (iterator < capacity)
	{
		this->myVector[iterator] = other.myVector[iterator];
	}
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		this->~MyVector();
		MyVector(other);
	}
	return *this;
}

template<class T>
MyVector<T>::~MyVector()
{
	delete[] this->myVector;
}

template<class T>
void MyVector<T>::push(const T& element)
{
	if (this->iterator == capacity) 
	{
		T* temp = new T[2 * capacity];

		for (size_t i = 0; i < capacity; i++) 
		{
			temp[i] = myVector[i];
		}

		delete[] this->myVector;
		capacity *= 2;
		this->myVector = temp;
	}

	this->myVector[iterator] = element;
	iterator++;
}

template<class T>
void MyVector<T>::remove()
{
	if (iterator == 0)
	{
		std::cout << "There is nothing to delete from vector" << std::endl;
		return;
	}
	this->iterator--;
	this->capacity--;
	this->myVector[iterator] = nullptr;
}

template<class T>
void MyVector<T>::removeSubarray(std::size_t a, std::size_t b)
{
	if (a < 0 && b >= iterator && a > b)
	{
		throw std::invalid_argument("invalid arguments");
	}

	size_t temp_capacity = this->capacity - (b - a);
	T* temp = new T[temp_capacity];
	size_t temp_iterator = 0;

	for (size_t i = 0; i < a; i++)
	{
		temp[temp_iterator] = myVector[i];
		temp_iterator++;
	}
	for (size_t i = b; i < iterator; i++)
	{
		temp[temp_iterator] = myVector[i];
		temp_iterator++;
	}

	delete[] this->myVector;
	MyVector(temp, temp_iterator, temp_capacity);
}

template<class T>
T& MyVector<T>::operator[](std::size_t index) const
{
	return this->myVector[index];
}

template<class T>
MyVector<T>& MyVector<T>::operator+(const MyVector<T>& other)
{
	size_t temp_capacity = this->capacity + other.capacity;
	size_t temp_iterator = 0;
	T* temp = new T[temp_capacity];
	for (size_t i = 0; i < this->iterator; i++)
	{
		temp[temp_iterator] = this->myVector[i];
		temp_iterator++;
	}
	for (size_t i = 0; i < other.iterator; i++)
	{
		temp[temp_iterator] = this->myVector[i];
		temp_iterator++;
	}

	MyVector<T> newVector(temp, temp_iterator, temp_capacity);
	delete[] temp;
	return *newVector;
}

template<class T>
MyVector<T>& MyVector<T>::get_Subarray(std::size_t a, std::size_t b)
{
	if (a < 0 && b >= iterator && a>b)
	{
		throw std::invalid_argument("invalid arguments");
	}
	size_t temp_capacity = b - a + 1;
	size_t temp_iterator = 0;
	T* temp = new T[temp_capacity];

	for (size_t i = a; i < b; i++)
	{
		temp[temp_iterator] = myVector[i];
		temp_iterator++;
	}
	MyVector<T> newVector(temp, temp_iterator, temp_capacity);
	delete[] temp;
	return *newVector;
}