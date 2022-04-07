#pragma once

namespace ft
{
    template <class T1, class T2>
    class pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

    private:
        first_type first;
        second_type second;

    public:
        pair() : first(), second() {}

        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        // first
        first_type& first() { return first; }
        const first_type& first() const { return first; }
        // second
        second_type& second() { return second; }
        const second_type& second() const { return second; }

        // operator =
        template <class U, class V>
        pair &operator=(const pair<U, V> &pr)
        {
            first = pr.first;
            second = pr.second;
            return *this;
        }
    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }
}