#pragma once

#include <iterator>

namespace ft
{
    template <class Iter>
    class iterator_traits
    {
    public:
        typedef typename Iter::value_type value_type;
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };
    template <class T>
    class iterator_traits<T *>
    {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template <class T>
    class iterator_traits<const T *>
    {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
}
// provides infos about iterator type

// what's good about stl ?
// the separation of data(containers) and operations(algorithms)
// the bridge between the two is the iterator

// ! links
// ! https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits