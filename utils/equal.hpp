# ifndef EQUAL_HPP
# define EQUAL_HPP

# include "enable_if.hpp"
# include "is_integral.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
# include "lexicographical_compare.hpp"
# include "../iterators/iterator_traits.hpp"

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        for (; first1 != last1; ++first1, ++first2)
            if (!(*first1 == *first2))
                return false;
        return true;
    }

    // ? how does it work?
    // * it returns true if the ranges are the same size and the elements are the same

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        for (; first1 != last1; ++first1, ++first2)
            if (!pred(*first1, *first2))
                return false;
        return true;
    }
}

// * pred is a binary function that accepts two arguments of the same type and returns a bool (true if x == y, false otherwise)
// * example :
// ! {
// bool mypredicate(int i, int j)
// {
//     return (i == j);
// }
// ! }

#endif