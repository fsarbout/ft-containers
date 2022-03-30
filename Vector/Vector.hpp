#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

#define GREEN "\e[1;32m"
#define RED "\e[1;31m"
#define WHITE "\e[1;37m"
#define DEFAULT "\e[0;37m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define PURPLE "\e[1;35m"
#define COLOR "\e[1;36m"

namespace ft
{
    template <typename T>
    class vector
    {
    public:
        typedef T value_type;
        typedef std::allocator<T> allocator_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef ft::iterator<T> iterator;
        typedef const T *const_iterator;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        allocator_type alloc;
        pointer _arr;
        size_type _size;
        size_type _capacity;

    public:
        //  ! default constructor
        explicit vector(const allocator_type &alloc = allocator_type()) : alloc(alloc), _arr(nullptr), _size(0), _capacity(0)
        {
            //  constructs empty container with no elements
            std::cout << YELLOW << "VECTOR DEFAULT CONSTRUCTOR" << DEFAULT << std:: endl;
        }

        // ! needs is integral and enable if
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            // constructs container with n elements, each initialized with val
            // like : vector<int> v(10, 0); >> will create a vector of 10 ints with all elements initialized to 0
            (void)alloc;
            _arr = nullptr;
            _size = 0;
            _capacity = 0;
            reserve(n);
            for (size_type i = 0; i < n; ++i)
                _arr[i] = val;
            _size = n;
        }

        // ! IDK
        // template <class InputIterator>
        // vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
        // {
        //     (void)alloc;
        //     _arr = nullptr;
        //     _size = 0;
        //     _capacity = 0;
        //     reserve(last - first);
        //     for (; first != last; ++first)
        //         push_back(*first);
        // }

        // destructor
        ~vector()
        {
            std::cout << GREEN << "DESTRUCTOR" << DEFAULT << std::endl;
            if (_arr)
                alloc.deallocate(_arr, _capacity);
        }

        vector &operator=(const vector &x)
        {
            if (this != &x)
            {
                _size = x._size;
                _capacity = x._capacity;
                _arr = alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; ++i)
                    _arr[i] = x._arr[i];
            }
            // std::cout << "so9 mok (1) ?" << this << std::endl;
            // std::cout << "so9 mok (2) ?" << *this << std::endl;
            return *this;
            // the return statement is "return *this", rather than "return this".
            // That's because this is a pointer to Vector.
            // You have to dereference it to get a reference to Vector.
        }
        // ! short functions
        // * begin() related infos
        // ? begin()
        // begin returns an iterator to the first element in the vector
        // :this iterator is a pointer to the first element in the vector
        // _arr and _arr[0] are the same
        // ? why is it returning _arr and its return type is iterator ?
        // (we want to use the iterator to access the elements in the vector.)
        iterator begin() { return _arr; }
        const_iterator begin() const { return _arr; }
        // ***** //

        // * end()... related infos
        // ?  _arr + _size vs _arr[_size] vs *(_arr + _size) ?
        // (_arr + _size) this one returns and iterator , so basically it is a pointer to the last element in the vector
        // _arr[_size] and *(arr + _size) will return the last element in the vector
        iterator end() { return _arr + _size; }
        const_iterator end() const { return _arr + _size; }
        // ***** //

        // * rend() rbegin()... related infos
        // ? rbegin()
        // rbegin returns an iterator to the last element in the vector
        // ? why don't we just use end() ? : it returns reverse_iterator
        reverse_iterator rbegin() { return reverse_iterator(end()); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
        // ***** //

        vector(const vector &x) { this = x; }

        // get_allocator returns a copy of the allocator object used by the vector
        allocator_type get_allocator() const { return alloc; }

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
        size_type max_size() { return alloc.max_size(); }

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
                pointer tmp = alloc.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    tmp[i] = _arr[i];
                alloc.deallocate(_arr, _capacity);
                _arr = tmp;
                _capacity = n;
            }
            // this function has no effect on size , and cannot alter its elements
            // we use allocator so in case of failure it will throw an exception : std::bad_alloc
        }
        void push_back(const T &x)
        {
            // if the vector is full, allocate new memory and copy elements
            // here we used reserve instead of resize because we don't want to change the size of the vector
            if (_size == _capacity)
                reserve(_capacity + 1);
            _arr[_size++] = x;
        }
        void pop_back()
        {
            // we reduce the size of the vector by 1 , so basically we remove the last element
            if (_size == 0)
                throw std::out_of_range("out of range");
            _size--;
        }
        // insert reserves memory for n elements and inserts x at position n
        // if n is greater than the size of the vector, the new elements are default constructed
        // if n is less than the size of the vector, the new elements are copy constructed from the existing elements
        // if n is equal to the size of the vector, the new elements are copy constructed from x

        iterator insert(iterator pos, const T &x)
        {
            if (_size == _capacity)
                reserve(_capacity + 1);
            for (size_type i = _size; i > pos - _arr; --i)
                _arr[i] = _arr[i - 1];
            _arr[pos - _arr] = x;
            _size++;
            return pos;
        }

        // void insert checks if size is bigger than capacity and if so, it calls reserve
        // then it inserts x at position n and moves all the elements after n to the right
        // if n is greater than the size of the vector, the new elements are default constructed
        void insert(iterator pos, size_type n, const T &x)
        {
            if (_size + n > _capacity)
                reserve(_capacity + n);
            for (size_type i = _size; i > pos - _arr; --i)
                _arr[i] = _arr[i - 1];
            for (size_type i = 0; i < n; ++i)
                _arr[pos - _arr + i] = x;
            _size += n;
        }

        // ! insert with input iterator needs is integral and enable if because of the iterator type, which is not integral
        // ! if we don't check for is integral we get a compile error
        // ! we check for is integral to avoid the error of the iterator type not being integral as this example shows :
        // ! vector<int> v;
        // ! v.insert(v.begin(), v.begin(), v.end());
        // ! this is not allowed because the iterator type is not integral and we can't use it in the insert function

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last)
        {
            size_type n = last - first;
            if (_size + n > _capacity)
                reserve(_capacity + n);
            for (size_type i = _size; i > position - _arr; --i)
                _arr[i] = _arr[i - 1];
            for (size_type i = 0; i < n; ++i)
                _arr[position - _arr + i] = *(first + i);
            _size += n;
        }
        // erase removes the element at position n and moves all the elements after n to the left 
        // example : vector<int> v;
        // v.erase(v.begin());
        // v.erase(v.begin() + 1);
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
                pointer tmp = alloc.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    tmp[i] = _arr[i];
                alloc.deallocate(_arr, _capacity);
                _arr = tmp;
                _capacity = n;
            }
            for (size_type i = 0; i < n; ++i)
                _arr[i] = x;
            _size = n;
        }
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last)
        {
            size_type n = last - first;
            if (n > max_size())
                throw std::length_error("length error");
            if (n > _capacity)
            {
                pointer tmp = alloc.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    tmp[i] = _arr[i];
                alloc.deallocate(_arr, _capacity);
                _arr = tmp;
                _capacity = n;
            }
            for (size_type i = 0; i < n; ++i)
                _arr[i] = first[i];
            _size = n;
        }

        // resize
        void resize(size_type n)
        {
            // ! if n is greater than the current size, we fill the new elements with the default value
            // ! example : vector<int> v; v.resize(10) will call v.reserve(10) and fill the new elements with the default value which is 0
            // ! the size of vector is basically the filled capacity of the vector, so resize needs to fill the new elements with the default value
            if (n > _capacity)
                reserve(n);
            if (n > _size)
                for (size_type i = _size; i < n; ++i)
                    _arr[i] = T();
            std::cout << YELLOW << "resize called ( _arr[i] = T()) :  ^ " << DEFAULT << std::endl;
            _size = n;
        }
    };
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const ft::vector<T> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
        os << v[i] << " ";
    return os;
}

// TODO : implement the following functions
// constuctors:
// begin : // * done
// end : // * done
// rbegin : // * done
// rend : // * done
// size : // * done
// max_size : // * done
// capacity : // * done
// reserve : // * done
// operator[] : // * done
// resize : // * done
// swap : // ? quesition : what about swaping allocators ? 
// operator= : // * done
// assign :
// insert :
// erase :
// clear : // * done
// push_back : // * done
// pop_back : // * done
// front : // * done
// back : // * done
// get_allocator : // * done
// TODO: non member functions
// * 1 :
// template <class T, class Alloc>
// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// * 2 :
// template <class T, class Alloc>
//   bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// * 3 :
// template <class T, class Alloc>
//   bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// * 4 :
// template <class T, class Alloc>
//   bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// * 5 :
// template <class T, class Alloc>
//   bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// * 6 :
// template <class T, class Alloc>
//   bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

// * 7 : swap
// template <class T, class Alloc>
//   void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

// ? when should operators return by reference ?
// answer : * if the built-in operator returns an rvalue then your overload should return a reference.
// : * if the built-in returns an lvalue then your overload should return a value.
// lvalue: is an object that is not a temporary object.

// Returning a value also forces unnecessary trips through the object's copy constructor, costing you in performance.?
//

#endif