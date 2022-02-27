// #pragma once

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Helpers.hpp"


template <typename T>
class Vector
{
private:
	T* _data;
	size_t _size; // * number of elements
	size_t _capacity; // * how much it can store without reallocating
	void  reAlloc(size_t newCapacity)
	{
		T* newBlock = new T[newCapacity];

		if (newCapacity < _size)
			_size = newCapacity;

		for (size_t i = 0; i < _size; i++)
			newBlock[i] = _data[i];

		delete[] _data;
		_data = newBlock;
		_capacity = newCapacity;
	}

public:
	Vector()
	{
		reAlloc(2);
	}

	~Vector()
	{

	}

	// Vector & operator=(const Vector & other)
	// {
	// 	if (this != &other)
	// 	{
	// 		// ? necessity of delete[] ??
	// 		delete[] _data;
	// 		_data = new T[other._capacity];
	// 		_size = other._size;
	// 		_capacity = other._capacity;
	// 		for (size_t i = 0; i < _size; i++)
	// 			_data[i] = other._data[i];
	// 	}
	// 	return *this;
	// }

	// Vector(const Vector& other)
	// {
	// 	*this = other;
	// }

	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}

	void pushBack(const T& value)
	{
		if (_size >= _capacity)
			reAlloc(_capacity + _capacity / 2);
		_data[_size] = value;
		_size++;
	}

	const T& operator[](size_t index) const
	{
		return _data[index];
	}
};

#endif