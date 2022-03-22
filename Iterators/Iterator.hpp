#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "../Helpers.hpp"
namespace ft
{
    template <class T>
    class Iterator
    {
    private:
        T *_ptr;

    public:
        void setPtr(T *ptr)
        {
            _ptr = ptr;
        }
        T* getPtr() const
        {
            return _ptr;
        }
        T *ptr;
        Iterator() {
            std::cout << GREEN << "CONSTRUCTOR" << DEFAULT << std::endl;
        }
        Iterator(T *ptr) : _ptr(ptr) {
            std::cout << GREEN << "PARAMETERIZED CONSTRUCTOR" << DEFAULT << std::endl;
        }
        ~Iterator()
        {
            std::cout << GREEN << "DESTRUCTOR" << DEFAULT << std::endl;
        }
        // * methods todo
        // TODO : copy constructor
        Iterator(const Iterator &copy)
        {
            std::cout << GREEN << "COPY CONSTRUCTOR" << DEFAULT << std::endl;
            // * return (*this) will return the current class object
            // * return (this ) will return the current class  address
            *this = copy;
        }
        // ? TF I need to return by reference ?!!!! both working fine
        Iterator &operator=(const Iterator &obj)
        {
            std::cout << GREEN << "ASSIGNEMENT OPERATOR" << DEFAULT << std::endl;
            this->_ptr = obj._ptr;
            return *this;
        }
        Iterator &operator++()
        {   
            std::cout << GREEN << "++ OPERATOR" << DEFAULT << std::endl;
            _ptr++;
            return *this;
        }
        Iterator operator++(int)
        {    
            std::cout << GREEN << "OPERATOR ++" << DEFAULT << std::endl;
            Iterator tmp = *this;
            ++*this;
            return tmp;
        }
        Iterator &operator--()
        {   
            std::cout << GREEN << "-- OPERATOR" << DEFAULT << std::endl;
            _ptr--;
            return *this;
        }
        Iterator operator--(int)
        {    
            std::cout << GREEN << "OPERATOR --" << DEFAULT << std::endl;
            Iterator tmp = *this;
            --*this;
            return tmp;
        }
        bool operator==(const Iterator &obj)
        {
            return (this->_ptr == obj._ptr);
        }
        bool operator!=(const Iterator &obj)
        {
            return (this->_ptr != obj._ptr);
        }
        bool operator<=(const Iterator &obj)
        {
            return (this->_ptr <= obj._ptr);
        }
        bool operator<(const Iterator &obj)
        {
            return (this->_ptr < obj._ptr);
        }
        bool operator>(const Iterator &obj)
        {
            return (this->_ptr > obj._ptr);
        }
        bool operator>=(const Iterator &obj)
        {
            return (this->_ptr >= obj._ptr);
        }
        Iterator operator+(const Iterator &obj)
        {
            // std::cout << "heoiwehgio" << std::endl;
            Iterator tmp;
            tmp._ptr = obj._ptr;
            return tmp;
        }
        Iterator operator-(const Iterator &obj)
        {
            // std::cout << "" << std::endl;
            Iterator tmp;
            tmp._ptr = obj._ptr;
            return tmp;
        }
        // returns the value of the current object
        T& operator*()
        {
            return _ptr;
        }
        // returns the address of the object
        //  should return a reference if I want to use for modification
        T* operator->()
        {
            return &_ptr;
        }
        
        // it + n function
        // add iterator to number
        Iterator operator+(int n)
        {
            std::cout << "you" << std::endl;
            Iterator tmp;
            tmp._ptr = _ptr + n;
            return tmp;
        }
        Iterator operator-(int n)
        {
            std::cout << "you" << std::endl;
            Iterator tmp;
            tmp._ptr = _ptr - n;
            return tmp;
        }
        // it - n function
        T* &operator[](int n)
        {
            return _ptr[n];
        }
        // operator +=
        Iterator &operator+=(int n)
        {
            _ptr += n;
            return *this;
        }
        // operator -=
        Iterator &operator-=(int n)
        {
            _ptr -= n;
            return *this;
        }
    };
}

template <typename T>
std::ostream &operator<<(std::ostream &out, ft::Iterator<T> it)
{
    std::cout << GREEN << "OPERATOR <<" << DEFAULT << std::endl;
    out << &it;
    return out;
}

template <typename T>
ft::Iterator<T> operator+(int n, ft::Iterator<T> it)
{
    std::cout << GREEN << "OPERATOR +" << DEFAULT << std::endl;
    ft::Iterator<T> tmp;
    tmp.setPtr(it.getPtr() + n);
    return tmp;
}   

template <typename T>
ft::Iterator<T> operator-(int n, ft::Iterator<T> it)
{
    std::cout << GREEN << "OPERATOR -" << DEFAULT << std::endl;
    ft::Iterator<T> tmp;
    tmp.setPtr(it.getPtr() - n);
    return tmp;
}

#endif

// ! links
// ! https://www.javatpoint.com/cpp-iterators
// ! https://www.cplusplus.com/reference/iterator/
// ! https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
// ! https://programmer.group/principle-and-simple-implementation-of-c-stl-iterator-just-read-this-one.html