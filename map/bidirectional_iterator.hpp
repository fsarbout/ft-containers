#pragma once

namespace ft
{
    template <typename Node, typename Pair>
    class bidirectional_iterator
    {
    public:
        typedef Node *node_pointer;
        typedef Pair *pair_pointer; // more readable
        typedef Pair *pointer;      // for iterator traits
        typedef Pair &reference;    // for iterator traits

        typedef Pair value_type;
        typedef Pair &pair_reference;
        node_pointer _node;
        typedef std::bidirectional_iterator_tag iterator_category;
        node_pointer *_root;
        typedef std::ptrdiff_t difference_type;

        bidirectional_iterator() : _node(NULL), _root(NULL) {}

        bidirectional_iterator(node_pointer node, node_pointer *root) : _node(node), _root(root) {}

        bidirectional_iterator(const bidirectional_iterator &other)
        {
            *this = other;
        }

        bidirectional_iterator &operator=(const bidirectional_iterator &other)
        {
            _node = other._node;
            _root = other._root;
            return *this;
        }

        ~bidirectional_iterator() {}

        pair_reference operator*() const
        {
            return *_node->_data;
        }

        pair_pointer operator->() const
        {
            return _node->_data;
        }

        bidirectional_iterator &operator++()
        {
            if (_node)
            {
                if (_node->_right)
                {
                    _node = _node->_right;
                    while (_node->_left)
                        _node = _node->_left;
                }
                else
                {
                    while (_node->_parent && _node->_parent->_right == _node)
                        _node = _node->_parent;
                    _node = _node->_parent;
                }
            }
            else
            {
                _node = _node->_right;
                while (_node->_left)
                    _node = _node->_left;
            }
            return *this;
        }

        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        bidirectional_iterator &operator--()
        {
            if (_node)
            {
                if (_node->_left)
                {
                    _node = _node->_left;
                    while (_node->_right)
                        _node = _node->_right;
                }
                else
                {
                    while (_node->_parent && _node->_parent->_left == _node)
                        _node = _node->_parent;
                    _node = _node->_parent;
                }
            }
            else
            {
                _node = _node->_left;
                while (_node->_right)
                    _node = _node->_right;
            }
            return *this;
        }

        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator tmp = *this;
            --*this;
            return tmp;
        }

        // operator ==
        bool operator==(const bidirectional_iterator &other) const
        {
            return (_node == other._node);
        }

        // operator !=
        bool operator!=(const bidirectional_iterator &other) const
        {
            return (_node != other._node);
        }
    };

    template <typename Node, typename Pair>
    class const_bidirectional_iterator
    {
    public:
        typedef Node *node_pointer;
        typedef Pair *pair_pointer;
        typedef Pair *pointer;   // for iterator traits
        typedef Pair &reference; // for iterator traits
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef Pair value_type;
        typedef Pair &pair_reference;
        typedef std::ptrdiff_t difference_type;
        typedef ft::bidirectional_iterator<Node, Pair> bidirectional_iterator;
        


    private:
        node_pointer _node;
        node_pointer *_root;

    public:
        const_bidirectional_iterator() : _node(NULL), _root(NULL) {}

        const_bidirectional_iterator(node_pointer node, node_pointer *root) : _node(node), _root(root) {}

        const_bidirectional_iterator(Node node, node_pointer root) : _node(node), _root(root) {}

        const_bidirectional_iterator(const bidirectional_iterator &other)
        {
            *this = other;
        }

        const_bidirectional_iterator(const const_bidirectional_iterator &other)
        {
            *this = other;
        }

        const_bidirectional_iterator &operator=(const const_bidirectional_iterator &other)
        {
            _node = other._node;
            _root = other._root;
            return *this;
        }

        ~const_bidirectional_iterator() {}

        pair_reference operator*() const
        {
            return *_node->_data;
        }

        pair_pointer operator->() const
        { 
            return _node->_data;
        }

        const_bidirectional_iterator &operator++()
        {
            if (_node)
            {
                if (_node->_right)
                {
                    _node = _node->_right;
                    while (_node->_left)
                        _node = _node->_left;
                }
                else
                {
                    while (_node->_parent && _node->_parent->_right == _node)
                        _node = _node->_parent;
                    _node = _node->_parent;
                }
            }
            else
            {
                _node = _node->_right;
                while (_node->_left)
                    _node = _node->_left;
            }
            return *this;
        }

        const_bidirectional_iterator operator++(int)
        {
            const_bidirectional_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        const_bidirectional_iterator &operator--()
        {
            if (_node)
            {
                if (_node->_left)
                {
                    _node = _node->_left;
                    while (_node->_right)
                        _node = _node->_right;
                }
                else
                {
                    while (_node->_parent && _node->_parent->_left == _node)
                        _node = _node->_parent;
                    _node = _node->_parent;
                }
            }
            else
            {
                _node = _node->_left;
                while (_node->_right)
                    _node = _node->_right;
            }
            return *this;
        }

        const_bidirectional_iterator operator--(int)
        {
            const_bidirectional_iterator tmp = *this;
            --*this;
            return tmp;
        }

        // operator ==
        bool operator==(const const_bidirectional_iterator &other) const
        {
            return (_node == other._node);
        }

        // operator !=
        bool operator!=(const const_bidirectional_iterator &other) const
        {
            return (_node != other._node);
        }
    };

 


}