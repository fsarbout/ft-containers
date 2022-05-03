#pragma once

#include <iostream>
#include <vector>
#include <cstddef>
#include <iterator>
#include <typeinfo>
#include <memory>
#include "../utils/is_integral.hpp"
#include "../utils/enable_if.hpp"
#include "iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"



namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef ft::iterator<value_type> iterator;
        typedef ft::iterator<const value_type> const_iterator;
        typedef size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        allocator_type _alloc;
        pointer _arr;
        size_type _size;
        size_type _capacity;

    public:
        //  ! default constructor
        explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0) {}

        // ! fill constructor
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0)
        {
            reserve(n);
            for (size_type i = 0; i < n; ++i)
                _arr[i] = val;
            _size = n;
        }

        vector(const vector &x)
        {
            *this = x;
        }

        // ! range constructor
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0)
        {
            (void)f;
            reserve(last - first);
            for (; first != last; ++first)
                _arr[_size++] = *first;
        }

        // destructor
        ~vector()
        {
            for (size_type i = 0; i < _size; ++i)
                _alloc.destroy(&_arr[i]);
            _alloc.deallocate(_arr, _capacity);
        }

        // ? without const testclass& t3 = t2 = t1; after assigning t1 to t2 the copy value of t1 will be destroyed
        vector &operator=(const vector &x)
        {
            if (*this != x)
            {
                _size = x._size;
                _capacity = x._capacity;
                _arr = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; ++i)
                    _arr[i] = x._arr[i];
            }
            return *this;
        }

        // ! short functions
        iterator begin()
        {
            return _arr;
        }
        const_iterator begin() const { return _arr; }

        iterator end()
        {
            return _arr + _size;
        }
        const_iterator end() const { return _arr + _size; }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        // get_allocator returns a copy of the allocator object used by the vector
        allocator_type get_allocator() const { return this->_alloc; }

        size_type size() const { return _size; }
        size_type capacity() const { return _capacity; }
        bool empty() const { return _size == 0; }
        reference operator[](size_type n) { return _arr[n]; }
        const_reference operator[](size_type n) const { return _arr[n]; }
        reference front() { return _arr[0]; }
        const_reference front() const { return _arr[0]; }
        reference back() { return _arr[_size - 1]; }
        const_reference back() const { return _arr[_size - 1]; }

        size_type max_size() { return _alloc.max_size(); }

        void clear()
        {
            _size = 0;
        }
        reference at(size_type n)
        {
            if (n >= _size)
                throw std::out_of_range("out of range");
            return _arr[n];
        }
        const_reference at(size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("out of range");
            return _arr[n];
        }

        // reserve
        void reserve(size_type n)
        {
            if (n > max_size())
                throw std::length_error("length error");
            if (n > _capacity)
            {
                pointer tmp = _alloc.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    tmp[i] = _arr[i];
                _alloc.deallocate(_arr, _capacity);
                _arr = tmp;
                _capacity = n;
            }
        }
        void push_back(const value_type &val)
        {
            if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            _arr[_size++] = val;
        }

        void pop_back()
        {
            if (_size == 0)
                throw std::out_of_range("out of range");
            _size--;
        }

        iterator insert(iterator position, const value_type &val)
        {
            difference_type pos = position - _arr;
            if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            // ?
            for (difference_type i = _size; i > pos; --i)
                _arr[i] = _arr[i - 1];
            _arr[pos] = val;
            _size++;
            return iterator(&_arr[pos]);
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            difference_type diff = position - _arr;
            if (_capacity < _size + n && n <= _size)
                reserve(_capacity * 2);
            else if (_size + n > _capacity)
                reserve(_capacity + n);
            for (size_type i = diff; i < _size; ++i)
                _arr[i + n] = _arr[i];
            for (size_type i = 0; i < n; ++i)
                _arr[diff + i] = val;
            _size += n;
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL)
        {
            (void)f;
            difference_type pos = position - _arr;
            size_type n = last - first;
            if (_capacity < _size + n && n <= _size)
                reserve(_capacity * 2);
            else if (_size + n > _capacity)
                reserve(_capacity + n);
            for (size_type i = pos; i < _size; ++i)
                _arr[i + n] = _arr[i];
            for (size_type i = 0; i < n; ++i)
                _arr[pos + i] = *(first + i);
            _size += n;
        }

        iterator erase(iterator pos)
        {
            for (size_type i = pos - _arr; i < _size - 1; ++i)
                _arr[i] = _arr[i + 1];
            _size--;
            return pos;
        }

        iterator erase(iterator first, iterator last)
        {
           
            size_type n = last - first;
            for (size_type i = first - _arr; i < _size - n; ++i)
                _arr[i] = _arr[i + n];
            _size -= n;
            return first;
        }

        void swap(vector &x)
        {
            std::swap(_arr, x._arr);
            std::swap(_size, x._size);
            std::swap(_capacity, x._capacity);
        }

        void assign(size_type n, const T &x)
        {
            if (n > max_size())
                throw std::length_error("length error");
            if (n > _capacity)
            {
                pointer tmp = _alloc.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    tmp[i] = _arr[i];
                _alloc.deallocate(_arr, _capacity);
                _arr = tmp;
                _capacity = n;
            }
            for (size_type i = 0; i < n; ++i)
                _arr[i] = x;
            _size = n;
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL)
        {
            (void)f;
            size_type n = last - first;
            if (n > max_size())
                throw std::length_error("length error");
            if (n > _capacity)
            {
                pointer tmp = _alloc.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    tmp[i] = _arr[i];
                _alloc.deallocate(_arr, _capacity);
                _arr = tmp;
                _capacity = n;
            }
            for (size_type i = 0; i < n; ++i)
                _arr[i] = *first;
            _size = n;
        }

        void resize(size_type n, value_type val = value_type())
        {
            if (n < _size)
            {
                for (size_type i = n; i < _size; ++i)
                    _alloc.destroy(_arr + i);
                _size = n;
            }
            else if (n > _capacity)
            {
                if (n > (_capacity * 2))
                    reserve(n);
                else
                    reserve(_capacity * 2);
                for (size_type i = _size; i < n; ++i)
                    push_back(val);
            }
            else if (n > _size)
                for (size_type i = _size; i < n; ++i)
                    push_back(val);
        }
    };
    // ! end of class vector
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); ++i)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    }
    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() < rhs.size())
            return true;
        else if (lhs.size() > rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); ++i)
        {
            if (lhs[i] < rhs[i])
                return true;
            else if (lhs[i] > rhs[i])
                return false;
        }
        return false;
    }
    template <class T, typename Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return rhs < lhs;
    }
    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs > rhs);
    }
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
    {
        lhs.swap(rhs);
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const ft::vector<T> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
        os << v[i] << " ";
    return os;
}