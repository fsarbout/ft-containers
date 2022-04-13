# pragma once

#include <iostream>
#include <iterator>
#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class iterator
    {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;

    private:
        pointer _ptr;

    public:
        iterator() : _ptr(NULL) {}
        iterator(pointer ptr) : _ptr(ptr) {}
        ~iterator() {}
        iterator(const iterator &copy)
        {
            // * return (*this) will return the current class object
            // * return (this ) will return the current class address
            // * return (&this ) will return the current class address
            // std::cout << "this: " << this << "copy " << &copy << std::endl;
            *this = copy;
        }

        iterator &operator=(const iterator &obj)
        {
            this->_ptr = obj._ptr;
            std::cout << "this: " << this << "obj: " << &obj << std::endl;
            return *this;
        }

        iterator &operator++()
        {
            this->_ptr++;
            return *this;
        }
        
        iterator operator++(int)
        {
            iterator tmp(*this);
            this->_ptr++;
            return tmp;
        }
        iterator &operator--()
        {
            _ptr--;
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            _ptr--;
            return tmp;
        }
        bool operator==(const iterator &obj) const
        {
            return (this->_ptr == obj._ptr);
        }
        bool operator!=(const iterator &obj) const
        {
            return (this->_ptr != obj._ptr);
        }
        bool operator<=(const iterator &obj) const
        {
            return (this->_ptr <= obj._ptr);
        }
        bool operator<(const iterator &obj) const
        {
            return (this->_ptr < obj._ptr);
        }
        bool operator>(const iterator &obj) const
        {
            return (this->_ptr > obj._ptr);
        }
        bool operator>=(const iterator &obj) const
        {
            return (this->_ptr >= obj._ptr);
        }
        // operator - returns distance between two iterators
        difference_type operator-(const iterator &obj) const
        {
            // * Subtraction gives you the distance >> the number of steps from one point to the other
            return (this->_ptr - obj._ptr);
        }

        reference operator*() const
        {
            // returns the value of the current object
            return *this->_ptr;
        }
        pointer operator->()
        {
            //  returns the address of the object
            //  should return a reference if I want to use for modification
            return this->_ptr;
        }

        iterator operator+(difference_type n) const
        {
            return this->_ptr + n;
        }
        iterator operator-(difference_type n) const
        {
            return this->_ptr - n;
        }
        reference operator[](int n) const
        {
            return this->_ptr[n];
        }
        iterator &operator+=(int n)
        {
            this->_ptr += n;
            return *this;
        }
        iterator &operator-=(int n)
        {
            this->_ptr -= n;
            return *this;
        }
        operator iterator<const value_type>()
        {
            return iterator<const value_type>(_ptr);
        }
    };

    template <typename T>
    iterator<T> operator+(std::ptrdiff_t n, ft::iterator<T> it)
    {
        return it + n;
    }
}