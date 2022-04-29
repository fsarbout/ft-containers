#pragma once

#include <map>
#include "../utils/pair.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "avl_tree.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../utils/equal.hpp"

namespace ft
{
    template <
        class Key,                                                  // map::key_type
        class Mapped_Type,                                          // map::mapped_type
        class Compare = std::less<Key>,                             // map::key_compare
        class Alloc = std::allocator<pair<const Key, Mapped_Type> > // map::allocator_type
        >
    class map
    {
    public:
        typedef Key key_type;
        typedef Mapped_Type mapped_type;
        typedef typename ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::size_type size_type;

        // typedef typename allocator_type::difference_type difference_type;

        typedef typename ft::avl_tree<Key, mapped_type, Compare, Alloc> tree;
        typedef ft::Node<value_type> node_type;
        typedef ft::bidirectional_iterator<node_type, value_type> iterator;
        typedef ft::const_bidirectional_iterator<node_type, value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef class value_compare : public std::binary_function<value_type, value_type, bool>
        {
        protected:
            key_compare _compare;

        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return _compare(x.first, y.first);
            }
            value_compare(key_compare c) : _compare(c) {}
        } value_compare;

    private:
        tree _tree;
        size_type _size;
        allocator_type _allocator;

    public:
        // ! empty constructor
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type())
        {
            (void)comp;
            (void)alloc;
            // Constructs an empty container, with no elements.
            (void)comp;
            (void)alloc;
            _size = 0;
            // _tree = tree(comp, alloc);
        }

        // ! range constructor
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
        {
            (void)first;
            (void)last;
            (void)comp;
            (void)alloc;
        }

        // ! copy constructor
        map(const map &x)
        {
            *this = x;
        }

        // ! destructor
        ~map() {}

        // ! assignation operator
        map &operator=(const map &x)
        {
            this->_tree = x._tree;
            this->_size = x._size;
            this->_allocator = x._allocator;
            return *this;
        }

        // ! it begin
        iterator begin()
        {
            std::cout << "begin called" << std::endl;
            node_type *tmp = _tree.min_node(_tree._root);
            return (iterator(tmp, const_cast<node_type **>(&_tree._root)));
        }

        const_iterator begin() const
        {
            node_type *tmp = _tree.min_node(_tree._root);
            return (const_iterator(tmp, const_cast<node_type **>(&_tree._root)));
        }

        // ! it end
        iterator end()
        {
            std::cout << "end called" << std::endl;
            return iterator(NULL, const_cast<node_type **>(&_tree._root));
        }
        const_iterator end() const
        {
            return const_iterator(NULL, const_cast<node_type **>(&_tree._root));
        }

        // ! rev it rbegin
        reverse_iterator rbegin()
        {
            std::cout << "rbegin called" << std::endl;
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            std::cout << "const rbegin called" << std::endl;
            return const_reverse_iterator(end());
        }

        // ! rev it rend
        reverse_iterator rend()
        {
            std::cout << "rend called" << std::endl;
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const
        {
            std::cout << "const rend called" << std::endl;
            return const_reverse_iterator(begin());
        }

        // ! empty
        bool empty() const
        {
            return this->_size == 0;
        }

        // ! size
        size_type size() const
        {
            return this->_size;
        }

        // ! max_size
        size_type max_size() const
        {
            return this->_allocator.max_size();
        }

        // ! operator []
        mapped_type &operator[](const key_type &k)
        {
            ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
			_tree.insert(p);
			node_type *tmp = _tree.search(_tree._root, k);
			return (tmp->_data->second);
        }

        // ! insert single element
        pair<iterator, bool> insert(const value_type &val);

        // ! insert with hint
        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            (void)val;
        }

        // ! insert range
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            (void)first;
            (void)last;
        }

        // ! erase
        void erase(iterator position)
        {
            (void)position;
        }

        size_type erase(const key_type &k)
        {
            return _tree.remove(k);
        }

        void erase(iterator first, iterator last)
        {
            // while (first != last)
            //     erase(first++);
            (void)first;
            (void)last;
        }

        // ! swap
        void swap(map &x);

        // ! clear
        void clear() {}

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
        allocator_type get_allocator() const
        {
            return this->_allocator;
        }
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
                   const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        (void)rhs;
        (void)lhs;
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
                   const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        (void)lhs;
        (void)rhs;
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
                    const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        (void)lhs;
        (void)rhs;
    }
}