#ifndef ITERATOR__TRAITS_HPP
#define ITERATOR__TRAITS_HPP

namespace ft
{
    template <typename T>
    struct iterator_traits
    {
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };
    class iterator_traits
    {
        
    };
}


#endif