#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// #define RED "\e[1;31m"
// #define WHITE "\e[1;37m"
#define DEFAULT "\e[0;37m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
// #define PURPLE "\033[1;35m"

#include <iostream>
// #include <cstddef>
// #include <typeinfo>
// #include <iterator>

namespace ft
{
    template <class T>
    class iterator
    {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
        // std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
    private:
        pointer _ptr;

    public:
        iterator()
        {
        }
        iterator(pointer ptr) : _ptr(ptr)
        {
        }
        ~iterator()
        {
        }
        iterator(const iterator &copy)
        {
            // * return (*this) will return the current class object
            // * return (this ) will return the current class  address
            *this = copy;
        }
        // ? TF I need to return by reference ?!!!! both working fine
        iterator &operator=(const iterator &obj)
        {
            this->_ptr = obj._ptr;
            return *this;
        }
        iterator &operator++()
        {
            _ptr++;
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++*this;
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
            // std::cout << YELLOW << "operator + (it)" << DEFAULT << std::endl;
            iterator tmp = *this;
            tmp._ptr += obj._ptr;
            return tmp;
        }
        // operator - returns distance between two iterators
        // we get the value at position 
        difference_type operator-(const iterator &obj)
        {
            // * Subtraction gives you the distance - the number of steps from one point to the other
            return (this->_ptr - obj._ptr);
        }
    
        T &operator*()
        {
            // returns the value of the current object
            return *_ptr;
        }
        T *operator->()
        {
            //  returns the address of the object
            //  should return a reference if I want to use for modification
            return &_ptr;
        }

        iterator operator+(int n)
        {
            iterator tmp;
            tmp._ptr = _ptr + n;
            return tmp;
        }
        iterator operator-(int n)
        {
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
        iterator &operator-=(int n)
        {
            _ptr -= n;
            return *this;
        }
        operator iterator<const value_type>() const
        { 
            return iterator<const value_type>(_ptr);
        }
    };

    // input iterator

}

template <typename T>
std::ostream &operator<<(std::ostream &out, ft::iterator<T> it)
{
    out << &it;
    return out;
}

template <typename T>
ft::iterator<T> operator+(int n, ft::iterator<T> it)
{
    ft::iterator<T> tmp;
    tmp.setPtr(it.getPtr() + n);
    return tmp;
}

template <typename T>
ft::iterator<T> operator-(int n, ft::iterator<T> it)
{
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