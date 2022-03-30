#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// #define RED "\e[1;31m"
// #define WHITE "\e[1;37m"
#define DEFAULT "\e[0;37m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
// #define PURPLE "\033[1;35m"


#include <iostream>
namespace ft
{
    template <class T>
    class iterator
    {
    public:
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ft::iterator<T> iterator_category;

    private:
        T *_ptr;

    public:
        iterator()
        {
            std::cout << BLUE << "iterator default constructor" << DEFAULT << std::endl;
        }
        iterator(T *ptr) : _ptr(ptr)
        {
            std::cout << YELLOW << "iterator param constructor" << DEFAULT << std::endl;
        }
        ~iterator()
        {
            std::cout << YELLOW << "destructor" << DEFAULT << std::endl;
        }
        // * methods todo
        // TODO : copy constructor
        iterator(const iterator &copy)
        {
            std::cout << YELLOW << "iterator copy constructor" << DEFAULT << std::endl;
            // * return (*this) will return the current class object
            // * return (this ) will return the current class  address
            *this = copy;
        }
        // ? TF I need to return by reference ?!!!! both working fine
        iterator &operator=(const iterator &obj)
        {
            std::cout << YELLOW << "iterator assignation operator  (it)" << DEFAULT << std::endl;
            this->_ptr = obj._ptr;
            return *this;
        }
        iterator &operator++()
        {
            std::cout << YELLOW << "++ operator (it)" << DEFAULT << std::endl;
            _ptr++;
            return *this;
        }
        iterator operator++(int)
        {
            std::cout << YELLOW << "operator ++ (it)" << DEFAULT << std::endl;
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
        iterator &operator--()
        {
            std::cout << YELLOW << "-- operator (it)" << DEFAULT << std::endl;
            _ptr--;
            return *this;
        }
        iterator operator--(int)
        {
            std::cout << YELLOW << "operator -- (it)" << DEFAULT << std::endl;
            iterator tmp = *this;
            --*this;
            return tmp;
        }
        bool operator==(const iterator &obj)
        {
            return (this->_ptr == obj._ptr);
        }
        bool operator!=(const iterator &obj)
        {
            return (this->_ptr != obj._ptr);
        }
        bool operator<=(const iterator &obj)
        {
            return (this->_ptr <= obj._ptr);
        }
        bool operator<(const iterator &obj)
        {
            return (this->_ptr < obj._ptr);
        }
        bool operator>(const iterator &obj)
        {
            return (this->_ptr > obj._ptr);
        }
        bool operator>=(const iterator &obj)
        {
            return (this->_ptr >= obj._ptr);
        }
        iterator operator+(const iterator &obj)
        {
            // std::cout << "TEST" << std::endl;
            iterator tmp;
            tmp._ptr = obj._ptr;
            return tmp;
        }
        iterator operator-(const iterator &obj)
        {
            // std::cout << "" << std::endl;
            iterator tmp;
            tmp._ptr = obj._ptr;
            return tmp;
        }
        // returns the value of the current object
        T &operator*()
        {
            return *_ptr;
        }
        //  returns the address of the object
        //  should return a reference if I want to use for modification
        T *operator->()
        {
            return &_ptr;
        }

        // it + n function
        // add iterator to number
        iterator operator+(int n)
        {
            std::cout << "you" << std::endl;
            iterator tmp;
            tmp._ptr = _ptr + n;
            return tmp;
        }
        iterator operator-(int n)
        {
            std::cout << "you" << std::endl;
            iterator tmp;
            tmp._ptr = _ptr - n;
            return tmp;
        }
        T *&operator[](int n)
        {
            return _ptr[n];
        }
        iterator &operator+=(int n)
        {
            _ptr += n;
            return *this;
        }
        // operator -=
        iterator &operator-=(int n)
        {
            _ptr -= n;
            return *this;
        }
    };

    // input iterator

}

template <typename T>
std::ostream &operator<<(std::ostream &out, ft::iterator<T> it)
{
    std::cout << YELLOW << "OPERATOR <<" << DEFAULT << std::endl;
    out << &it;
    return out;
}

template <typename T>
ft::iterator<T> operator+(int n, ft::iterator<T> it)
{
    std::cout << YELLOW << "OPERATOR +" << DEFAULT << std::endl;
    ft::iterator<T> tmp;
    tmp.setPtr(it.getPtr() + n);
    return tmp;
}

template <typename T>
ft::iterator<T> operator-(int n, ft::iterator<T> it)
{
    std::cout << YELLOW << "OPERATOR -" << DEFAULT << std::endl;
    ft::iterator<T> tmp;
    tmp.setPtr(it.getPtr() - n);
    return tmp;
}

#endif

// ! links
// ! https://www.javatpoint.com/cpp-iterators
// ! https://www.cplusplus.com/reference/iterator/
// ! https://www.cplusplus.com/reference/iterator/RandomAccessiterator/
// ! https://programmer.group/principle-and-simple-implementation-of-c-stl-iterator-just-read-this-one.html