#pragma once

#include <map>
#include "../utils/pair.hpp"
#include "../utils/less.hpp"

namespace ft
{
    template <
        class Key,                                        // map::key_type
        class T,                                          // map::mapped_type
        class Compare = std::less<Key>,                        // map::key_compare
        class Alloc = std::allocator<pair<const Key, T> > // map::allocator_type
        >
    class map
    {
    public:
        typedef ft::pair<const key_type, mapped_type> typedef Key key_type typedef T mapped_type typedef Compare key_compare typedef... value_compare typedef... allocator_type;
        typedef... reference;
        typedef... const_reference;
        typedef... pointer;
        typedef... const_pointer;
        typedef... iterator;
        typedef... const_iterator;
        typedef... reverse_iterator;
        typedef... const_reverse_iterator;
        typedef... difference_type;
        typedef... size_type;

    private:
        // data
    public:
        // ! empty constructor
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type());

        // ! range constructor
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type());

        // ! copy constructor
        map(const map &x);

        // ! destructor
        ~map();

        // ! assignation operator
        map &operator=(const map &x);

        // ! it begin
        iterator begin();
        const_iterator begin() const;

        // ! it end
        iterator end();
        const_iterator end() const;

        // ! rev it rbegin
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;

        // ! rev it rend
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // ! empty
        bool empty() const;

        // ! size
        size_type size() const;

        // ! max_size
        size_type max_size() const;

        // ! operator []
        mapped_type &operator[](const key_type &k);

        // ! insert single element
        pair<iterator, bool> insert(const value_type &val);

        // ! insert with hint
        iterator insert(iterator position, const value_type &val);

        // ! insert range
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);

        // ! erase
        void erase(iterator position);
        size_type erase(const key_type &k);
        void erase(iterator first, iterator last);

        // ! swap
        void swap(map &x);

        // ! clear
        void clear();

        // ! key compare
        key_compare key_comp() const;

        // ! value compare
        value_compare value_comp() const;

        // ! find
        iterator find(const key_type &k);
        const_iterator find(const key_type &k) const;

        // ! count
        size_type count(const key_type &k) const;

        // ! lower bound
        iterator lower_bound(const key_type &k);
        const_iterator lower_bound(const key_type &k) const;

        // ! upper bound
        iterator upper_bound(const key_type &k);
        const_iterator upper_bound(const key_type &k) const;
    
        // ! equal range
        pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
        pair<iterator, iterator> equal_range(const key_type &k);

        // ! get allocator
        allocator_type get_allocator() const;

    };
}