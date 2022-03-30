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
        explicit vector(const allocator_type &alloc = allocator_type())
            : alloc(alloc), _arr(nullptr), _size(0), _capacity(0)
        {
        }
        // ! needs isintegral and enable if

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

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
        {
            (void)alloc;
            _arr = nullptr;
            _size = 0;
            _capacity = 0;
            reserve(n);
            for (size_type i = 0; i < n; ++i)
                _arr[i] = val;
            _size = n;
        }
        vector(const vector &x)
        {
            this = x;
        }
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
            return *this;
        }
        size_type size() const
        {
            return _size;
        }
        size_type capacity() const
        {
            return _capacity;
        }
        bool empty() const
        {
            return _size == 0;
        }
        reference operator[](size_type n)
        {
            return _arr[n];
        }
        const_reference operator[](size_type n) const
        {
            return _arr[n];
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
        reference front()
        {
            return _arr[0];
        }
        const_reference front() const
        {
            return _arr[0];
        }
        reference back()
        {
            return _arr[_size - 1];
        }
        const_reference back() const
        {
            return _arr[_size - 1];
        }
        // max size
        size_type max_size()
        {
            return alloc.max_size();
        }
        // reserve
        void reserve(size_type n)
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
        }
        void push_back(const T &x)
        {
            if (_size == _capacity)
                reserve(_capacity + 1);
            _arr[_size++] = x;
        }
        void pop_back()
        {
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

        //  ! insert with input iterator needs isintegral and enable if because of the iterator type, which is not integral
        // ! if we don't check for is integral we get a compile error
        // ! we check for isintegral to avoid the error of the iterator type not being integral as this example shows :
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

        iterator erase(iterator position)
        {
            for (size_type i = position - _arr; i < _size - 1; ++i)
                _arr[i] = _arr[i + 1];
            _size--;
            return position;
        }
        void clear()
        {
            _size = 0;
        }
        void swap(vector &x)
        {
            std::swap(_arr, x._arr);
            std::swap(_size, x._size);
            std::swap(_capacity, x._capacity);
        }
        iterator begin()
        {
            return _arr;
        }
        const_iterator begin() const
        {
            return _arr;
        }
        iterator end()
        {
            return _arr + _size;
        }
        const_iterator end() const
        {
            return _arr + _size;
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
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
        allocator_type get_allocator() const
        {
            return alloc;
        }
        // resize
        void resize(size_type n)
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

#endif