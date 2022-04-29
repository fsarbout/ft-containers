#pragma once

#include <iterator>
#include "../vector/iterator.hpp"

namespace ft
{
    template <class Iterator>
    class iterator_traits
    {
    public:
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };
    template <class Iterator>
    class iterator_traits<Iterator *>
    {
    public:
        typedef Iterator value_type;
        typedef std::ptrdiff_t difference_type;
        typedef Iterator *pointer;
        typedef Iterator &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template <class Iterator>
    class iterator_traits<const Iterator *>
    {
    public:
        typedef Iterator value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const Iterator *pointer;
        typedef const Iterator &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
}
// provides infos about iterator type


// ! links
// ! https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits