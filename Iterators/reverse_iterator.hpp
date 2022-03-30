#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
    template <typename T>
    class reverse_iterator
    {
        public:
            typedef iterator_type<T> iterator_type;
            typedef iterator_traits::iterator_category iterator_category;
            typedef iterator_traits::value_type value_type;
            // difference type
            typedef iterator_traits::difference_type difference_type;
            typedef iterator_traits::pointer pointer;
            typedef iterator_traits::reference reference;

        private:
            iterator_type _it;
        public:
            // default constructor
            reverse_iterator() : _it() {}
            // copy constructor
            reverse_iterator(const reverse_iterator &copy) : _it(copy._it) {}
            // parameterized constructor
            reverse_iterator(iterator_type it) : _it(it) {}
            // dereferencing operator
            reference operator*() const
            {
                // ? 
                return *(_it - 1);
            }
            // prefix increment operator
            reverse_iterator &operator++()
            {
                --_it;
                return *this;
            }
            // postfix increment operator
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                --_it;
                return tmp;
            }
            // prefix decrement operator
            reverse_iterator &operator--()
            {
                ++_it;
                return *this;
            }
            // postfix decrement operator
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                ++_it;
                return tmp;
            }
            // comparison operators
            bool operator==(const reverse_iterator &obj) const
            {
                return _it == obj._it;
            }
            bool operator!=(const reverse_iterator &obj) const
            {
                return _it != obj._it;
            }
            // pointer operator
            pointer operator->() const
            {
                return &(*_it);
            }
            // dereference operator
            reference operator[](difference_type n) const
            {
                return *(_it - n);
            }
            // difference operator
            difference_type operator-(const reverse_iterator &obj) const
            {
                return _it - obj._it;
            }
            // addition operator
            reverse_iterator operator+(difference_type n) const
            {
                return reverse_iterator(_it - n);
            }
            // subtraction operator
            reverse_iterator operator-(difference_type n) const
            {
                return reverse_iterator(_it + n);
            }
            // addition assignment operator
            reverse_iterator &operator+=(difference_type n)
            {
                _it -= n;
                return *this;
            }
            // subtraction assignment operator
            reverse_iterator &operator-=(difference_type n)
            {
                _it += n;
                return *this;
            }
    };
}


#endif 