// #pragma once

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Helpers.hpp"


template <typename T>
class Vector
{
private:
	T* _data = nullptr;
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
	Vector(int i)
	{

	}
	~Vector()
	{

	}
	void pushBack(const T& value)
	{
		if (_size >= _capacity)
			reAlloc(_capacity + _capacity / 2);
		_data[_size] = value;
		_size++;
	}
	const T& operator[](size_t index)
	{
		return _data[index];
	}
};

#endif