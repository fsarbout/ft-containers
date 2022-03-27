#ifndef INPUT_ITERATOR_HPP
#define INPUT_ITERATOR_HPP

namespace ft
{
    template <typename T>
    class input_iterator
    {
    public:
    private:
        iterator_type _it;

    public:
        // default constructor
        input_iterator() : _it() {}
        // copy constructor
        input_iterator(const input_iterator &copy) : _it(copy._it) {}
        // parameterized constructor
        input_iterator(iterator_type it) : _it(it) {}
        // dereferencing operator
        reference operator*() const
        {
            return *_it;
        }
        // prefix increment operator
        input_iterator &operator++()
        {
            ++_it;
            return *this;
        }
        // postfix increment operator
        input_iterator operator++(int)
        {
            input_iterator tmp = *this;
            ++_it;
            return tmp;
        }
        bool operator==(const input_iterator &obj) const
        {
            return _it == obj._it;
        }
        bool operator!=(const input_iterator &obj) const
        {
            return _it != obj._it;
        }
        pointer operator->() const
        {
            return &(*_it);
        }
        reference operator*()
        {
            return *_it;
        }
    };
}

#endif