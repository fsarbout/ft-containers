#pragma once

// biderctional_iterator for map with avl treee
namespace ft
{
    template <typename Node, typename Pair>
    class bidirectional_iterator
    {
    public:
        typedef Node *node_pointer;
        typedef Pair *pair_pointer;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef Pair value_type;
        typedef Pair &pair_reference;
        node_pointer _node;
        pair_pointer _pair;

        bidirectional_iterator() : _node(NULL), _pair(NULL) {}

        bidirectional_iterator(node_pointer node, pair_pointer pair)
            : _node(node), _pair(pair) {}

        bidirectional_iterator(const bidirectional_iterator &other)
            : _node(other._node), _pair(other._pair) {}

        bidirectional_iterator &operator=(const bidirectional_iterator &other)
        {
            _node = other._node;
            _pair = other._pair;
            return *this;
        }

        pair_reference &operator*() const
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
        }

        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        // decrementing an node in avl_tree
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
        }

        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator tmp = *this;
            --*this;
            return tmp;
        }
    };
}