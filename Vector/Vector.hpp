#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
    template <typename T>
    class Vector
    {
    public:
        typedef T value_type;
        typedef std::allocator<T> allocator_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T *iterator;
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
        explicit vector(size_type n, const allocator_type &alloc = allocator_type())
            : alloc(alloc), _arr(nullptr), _size(0), _capacity(0)
        {
            reserve(n);
            for (size_type i = 0; i < n; ++i)
                _arr[i] = T();
            _size = n;
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
        {

        }
        vector (const vector& x)
        {
            _size = x._size;
            _capacity = x._capacity;
            _arr = alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; ++i)
                _arr[i] = x._arr[i];
        }
    };

}

#endif