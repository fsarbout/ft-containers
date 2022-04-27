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

// note : install "better comments" to highlight comments"
// ? question
// * answer
// ** example

// Note : we can't access end() of vector, it doesn't point to any valid data
// end() doesn't point to last element, it points to the element behind the last
// so it gives an undefined behavior
// v::iterator = v.end() => derreferencing an invalid pointer
// in case of empty vector, end() == begin()

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
        explicit vector(const allocator_type &alloc= allocator_type()) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0) {}

        // ! fill constructor
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc= allocator_type()) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0)
        {
            // constructs container with n elements, each initialized with val
            // like : vector<int> v(10, 0); >> will create a vector of 10 ints with all elements initialized to 0
            // std::cout << "VECTOR CONSTRUCTOR" << std::endl;

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
        vector(InputIterator first, InputIterator last, const allocator_type &alloc= allocator_type(),
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
            // std::cout << "VECTOR ASSIGNMENT" << std::endl;
            if (this != &x)
            {
                _size = x._size;
                _capacity = x._capacity;
                _arr = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; ++i)
                    _arr[i] = x._arr[i];
            }
            return *this;
            // the return statement is "return *this", rather than "return this".
            // That's because this is a pointer to Vector.
            // You have to dereference it to get a reference to Vector.
        }
        // ! short functions
        iterator begin()
        {
            // begin returns an iterator(pointer) to the first element in the vector
            // _arr and _arr[0] are the same (_arr is the address of the first element)
            return _arr;
        }
        const_iterator begin() const { return _arr; }

        iterator end()
        {
            // ?  _arr + _size vs _arr[_size] vs *(_arr + _size) ?
            // (_arr + _size) this one returns and iterator , so basically it is a pointer to the last element in the vector
            // _arr[_size] and *(arr + _size) will return the last element in the vector
            return _arr + _size;
        }
        const_iterator end() const { return _arr + _size; }

        reverse_iterator rbegin()
        {
            // rbegin returns an iterator to the last element in the vector
            // ? why don't we just use end() ?
            // * in STL it returns a reverse_iterator
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        // get_allocator returns a copy of the allocator object used by the vector
        allocator_type get_allocator() const { return this->_alloc; }

        void clear() { _size = 0; }
        size_type size() const { return _size; }
        size_type capacity() const { return _capacity; }
        bool empty() const { return _size == 0; }
        reference operator[](size_type n) { return _arr[n]; }
        const_reference operator[](size_type n) const { return _arr[n]; }
        reference front() { return _arr[0]; }
        const_reference front() const { return _arr[0]; }
        reference back() { return _arr[_size - 1]; }
        const_reference back() const { return _arr[_size - 1]; }

        // max_size returns the maximum possible number of elements that can be stored in the vector
        // ? does it change each time we insert an element ? (: no)
        size_type max_size() { return _alloc.max_size(); }

        // ! end of short functions
        // ? at vs [] ? : at checks if the index is in the range of the vector and thwors an exception if it is not
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
            // reserve space for n elements
            // we use reserve in case we need to increase the capacity of the vector
            // if n is greater than current capacity, allocate new memory and copy elements
            // if n is small or equal to current capacity, no change
            // if n is greater than max_size(), throw std::length_error
            // ? reserve vs resize : reserve is used to pre-allocate memory, resize is used to change the size of the container
            if (n > max_size())
                throw std::length_error("length error");
            if (n > _capacity)
            {
                // we use tmp to store the old array and allocate new memory for the new
                //      array with the new capacity and copy the old array to the new array
                //      then we delete the old array and assign the new array to the old array
                //      and the new capacity to the old capacity
                //  we use tmp to avoid the problem of the old array being deleted before the new array is copied
                // ? and case of arr is empty should I use nullptr instead of tmp ?
                pointer tmp = _alloc.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    tmp[i] = _arr[i];
                _alloc.deallocate(_arr, _capacity);
                _arr = tmp;
                _capacity = n;
            }
            // this function has no effect on size , and cannot alter its elements
            // we use allocator so in case of failure it will throw an exception : std::bad_alloc
            // deallocate tmp after use
        }
        void push_back(const value_type &val)
        {
            if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            _arr[_size++] = val;
        }

        void pop_back()
        {
            // we reduce the size of the vector by 1 , so basically we remove the last element
            if (_size == 0)
                throw std::out_of_range("out of range");
            _size--;
        }
        // insert start //

        // insert end //
        // ! test

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
            // we're calling iterator constructor: cuz we need to create a new iterator to the element that was inserted.because
            // the previous one is invalidated
            // iterator invalidation:  the vector is resized and the iterator is pointing to the new location of the element
            // we return an iterator to the element that was inserted.
            return iterator(&_arr[pos]);
        }

        // void insert checks if size is bigger than capacity and if so, it calls reserve
        // then it inserts x at position n and moves all the elements after n to the right
        // if n is greater than the size of the vector, the new elements are default constructed

        // ! fill

        void insert(iterator position, size_type n, const value_type &val)
        {
            // in case of n is greater than the size of the vector, the new elements are default constructed
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

        // ! insert with input iterator needs is integral and enable if because of the iterator type, which is not integral
        // ! if we don't check for is integral we get a compile error
        // ! we check for is integral to avoid the error of the iterator type not being integral as this example shows:
        // ! vector<int> v;
        // ! v.insert(v.begin(), v.begin(), v.end());
        // ! this is not allowed because the iterator type is not integral and we can't use it in the insert function

        // TODO: need to fix is_integral, enable if
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

        // erase removes the element at position n and moves all the elements after n to the left
        // example : vector<int> v;
        // v.erase(v.begin());
        // v.erase(v.begin() + 1);

        iterator erase(iterator pos)
        {
            // ? what does this function do ?
            // * it removes the element at position n and moves all the elements after n to the left
            // ** example : vector<int> v; (v contains {1, 2, 3, 4, 5}), v.erase(v.begin() + 1) will result in {1, 3, 4, 5},
            // ** it will remove the element at position 1 and move all the elements after position 1 to the left
            // ? how does this function work ?
            // * arr is a pointer to the first element in the array
            // * pos is a pointer to the element we want to remove
            // * the distance between pos and arr is the index of the element we want to remove
            // * the distance is calculated in iterator operator - , which is the distance between two iterators, basically two pointers
            // * we decrease the size of the vector by 1 because we removed one element
            // ? return value ?
            // * in stl this function returns an iterator to the element after the removed element, so the pos of the removed element
            for (size_type i = pos - _arr; i < _size - 1; ++i)
                _arr[i] = _arr[i + 1];
            _size--;
            return pos;
        }

        // 1 2 3 4 5 6 7 8 9 10
        // erase(begin() + 5); >> will remove the element at position 6 and move all the elements after position 5 to the left
        // 1 2 3 4 5 7 8 9 10

        iterator erase(iterator first, iterator last)
        {
            // ? what does this function do ?
            // * it removes the elements between first and last and moves all the elements after last to the left
            // * the last element is not included in the range
            // ** example : vector<int> v; (v contains {1, 2, 3, 4, 5}), v.erase(v.begin() + 1, v.begin() + 3) will result in {1, 5},
            // difference_type first = std::distance(first, last);
            // std::cout << t << std::endl;
            size_type n = last - first;
            for (size_type i = first - _arr; i < _size - n; ++i)
                _arr[i] = _arr[i + n];
            _size -= n;
            return first;
            // 1 2 3 4 5 6
            // it = begin(); == 1
            // it2 = begin() + 2; == 3
            // erase (it, it2); ==
        }
        void swap(vector &x)
        {
            std::swap(_arr, x._arr);
            std::swap(_size, x._size);
            std::swap(_capacity, x._capacity);
        }
        // assign vs insert :
        // assign is used to assign a new value to all the elements in the vector
        // insert is used to insert a new element at the end of the vector(specified position)
        // ! insert vs assign :
        // ! insert : inserts the elements in the specific position after moving the positions elements to the right
        // ! assign : assigns the new value to all the elements in the vector, overwriting the old values
        void assign(size_type n, const T &x)
        {
            // ? what does this function do ?
            // * it assigns n copies of x to the vector
            // ** example : vector<int> v; (v contains {1, 2, 3, 4, 5}), v.assign(3, 'a') will result in {'a', 'a', 'a'}
            // ? how does this function work ?
            // std::cout << "assign 1" << std::endl;
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

        // TODO: need to fix integral, enable if
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL)
        {
            (void)f;
            // std::cout << "assign 2" << std::endl;
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

        // resize start //
        // ! if n is greater than the current size, we fill the new elements with the default value
        // ! example : vector<int> v; v.resize(10) will call v.reserve(10) and fill the new elements with the default value which is 0
        // ! the size of vector is basically the filled capacity of the vector, so resize needs to fill the new elements with the default value

        // resize end //

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