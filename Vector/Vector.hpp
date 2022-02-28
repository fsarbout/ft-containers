// #pragma once

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../Helpers.hpp"
#include <memory>

template <typename T>
class Vector
{
private:
	T *_data;
	size_t _size;	  // ! number of elements
	size_t _capacity; // ! how much it can store without reallocating
	// 
	void reAlloc(size_t newCapacity)
	{
		T *newBlock = new T[newCapacity];

		if (newCapacity < _size)
			_size = newCapacity;

		for (size_t i = 0; i < _size; i++)
			newBlock[i] = _data[i];

		delete[] _data;
		_data = newBlock;
		_capacity = newCapacity;
	}

public:
	// TODO : constructor * 4
	// TODO : destructor
	// TODO : operator =
	// ! ITERATORS
	// TODO : ITERATOR: 1.begin() => return iterator to beginning
	// TODO : ITERATOR: 2.end() => ret iterator to end
	// TODO : ITERATOR: 3.rbegin() => ret reverse iterator to reverse beginning
	// TODO : ITERATOR: 4.rend() => ret reverse iterator to reverse end
	// TODO : ITERATOR: 5.cbegin() => ret const iterator to beginning
	// TODO : ITERATOR: 6.cend() => ret const iterator to end
	// TODO : ITERATOR: 7.crbegin() => ret const reverse iterator to reverse beginning
	// TODO : ITERATOR: 8.crend() => ret const reverse iterator to reverse end

	// TODO : void push_back(int data) - add element to the end of the vector
	// TODO : void push(int data, int index) - add element to index position
	// TODO : int get(int index) - return element at index position
	// TODO : void pop() - remove element from the end of the vector
	// TODO : int size() - return number of elements (just filled elements)
	// TODO : int capacity() - return total storage
	// TODO : 
	// TODO :
	// TODO :
	// TODO :
	// TODO :

	// ! default constructor
	Vector()
	{
		std::cout << GREEN << "default constructor" << DEFAULT << std::endl;
		_data = new T[2];
		_capacity = 2;
		_size = 0;
	}
	// ! fill constructor : constructs a container with n elements, each element is a copy of val
	~Vector()
	{
		std::cout << GREEN << "destructor" << DEFAULT << std::endl;
		delete[] _data;
	}

	Vector &operator=(const Vector &other)
	{
		std::cout << GREEN << "assignment operator" << DEFAULT << std::endl;
		if (this != &other)
		{
			// ? necessity of delete[] ??
			// delete[] _data;
			_data = new T[other._capacity];
			_size = other._size;
			_capacity = other._capacity;
			for (size_t i = 0; i < _size; i++)
				_data[i] = other._data[i];
		}
		return *this;
	}

	Vector(const Vector &other)
	{
		std::cout << GREEN << "copy constructor" << DEFAULT << std::endl;
		*this = other;
	}

	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}

	void pushBack(const T &value)
	{
		if (_size >= _capacity)
			reAlloc(_capacity + _capacity / 2);
		_data[_size] = value;
		_size++;
	}

	const T &operator[](size_t index) const
	{
		std::cout << GREEN << "operator[]" << DEFAULT << std::endl;
		return _data[index];
	}
};

#endif