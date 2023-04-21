#pragma once
#include <iostream>
#include <exception>

template <class T>
class MyVector
{
private:
	T* myVector;
	std::size_t capacity;
	std::size_t iterator;

public:
	MyVector();
	MyVector(const T& _vector, std::size_t _iterator, std::size_t _capacity);
	MyVector(const MyVector<T>& other);
	MyVector<T>& operator=(const MyVector<T>& other);
	~MyVector();
	void push(const T& element);
	void remove();
	void removeSubarray(std::size_t a, std::size_t b);
	T& operator[](std::size_t index) const;
	bool isTrueForAll(/*predikat ?*/);
	MyVector<T>& operator+(const MyVector<T>& other);
	void map(/*ne shvanah*/);
	MyVector<T>& get_Subarray(std::size_t a, std::size_t b);

};









