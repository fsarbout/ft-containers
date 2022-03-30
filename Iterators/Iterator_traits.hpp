#ifndef ITERATOR__TRAITS_HPP
#define ITERATOR__TRAITS_HPP

namespace ft
{
    template <class T>
    struct iterator_traits
    {
        typedef typename T::value_type value_type;
        typedef typename T::difference_type difference_type;
        typedef typename T::pointer pointer;
        typedef typename T::reference reference;
        typedef typename T::iterator_category iterator_category;
    };
    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef random_access_iterator_tag iterator_category;
    };
    template <class T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef random_access_iterator_tag iterator_category;
    };

}

#endif

// what's good about stl ?
// the separation of data(containers) and operations(algorithms)
// the bridge between the two is the iterator

// ! links
// ! https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits