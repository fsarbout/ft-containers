#pragma once

#include <iostream>
#include <memory>
#include "../utils/pair.hpp"

// Internal node containing node references(left , right) and node data
namespace ft
{
    template <typename T>
    class Node
    {
    public:
        T *_data;
        Node<T> *_left;
        Node<T> *_right;
        Node<T> *_parent; // still don't know why
        int _height;
        int _balance_factor;

        Node() : _data(NULL), _left(NULL), _right(NULL), _height(0), _balance_factor(0) {}
        ~Node() {}
        Node(T *data, Node<T> *left, Node<T> *right) : _data(data), _left(left), _right(right) {}
        T operator*() { return *this->_data; }
    };

    template <class Key,                                            // map::key_type
              class T,                                              // map::mapped_type
              class Compare = std::less<Key>,                       // map::key_compare
              class Alloc = std::allocator<ft::pair<const Key, T> > // map::allocator_type
              >
    class avl_tree
    {
    public:
        typedef T mapped_type;
        typedef Alloc allocator_type;
        typedef Key key_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Node<value_type> node_type;
        typedef typename Alloc::template rebind<node_type>::other node_allocator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef Compare value_compare;
        node_type *_root; // has to be public

    private:
        size_type _size;
        value_compare _compare;
        allocator_type _pair_allocator;
        node_allocator _node_allocator;

        // ! private methods

        int height(node_type *node)
        {
            if (node == NULL)
                return 0;
            return 1 + std::max(height(node->_left), height(node->_right));
        }

        bool _equal(const key_type &key1, const key_type &key2) const
        {
            return (_compare(key1, key2) == false && _compare(key2, key1) == false);
        }

        bool __exists(node_type *node, T elem) const
        {
            // reached the end of the tree, value not found
            if (node == NULL)
                return false;

            // value found
            // else if (node->_data == elem)
            // compare using _compare
            else if (_equal(node->_data->first, elem))
                return true;

            // move to the left subtree because the value is smaller than the current node
            // else if (elem < node->_data)
            else if (_compare(elem, node->_data->first))
                return __exists(node->_left, elem);

            // move to the right subtree because the value is greater than the current node
            else
                return __exists(node->_right, elem);
        }

        // ? private height and exist are called by the public ones

        // ! end of private methods
        node_type *add(node_type *node, value_type value)
        {
            if (node == NULL)
            {
                node_type *tmp = _node_allocator.allocate(1);
                tmp->_data = _pair_allocator.allocate(1);
                _pair_allocator.construct(tmp->_data, value);
                tmp->_left = NULL;
                tmp->_parent = NULL;
                tmp->_right = NULL;
                tmp->_height = 0;
                tmp->_balance_factor = 0;
                return tmp;
            }
            else if (value.first < node->_data->first)
            {
                node->_left = add(node->_left, value);
                node->_left->_parent = node;
            }
            else if (value.first > node->_data->first)
            {
                node->_right = add(node->_right, value);
                node->_right->_parent = node;
            }
            else
            {
                node->_data->second = value.second;
            }
            // update height
            node->_height = 1 + std::max(height(node->_left), height(node->_right));
            return node;
        }

    public:
        // constructor
        avl_tree()
        {
            _root = NULL;
        }
        avl_tree(const avl_tree &other) : _root(NULL)
        {
            _root = copy(other._root);
        }
        avl_tree &operator=(const avl_tree &other)
        {
            if (this != &other)
            {
                clear();
                _root = copy(other._root);
            }
            return *this;
        }
        ~avl_tree()
        {
            clear();
        }
        void clear()
        {
            // clear(_root);
            _root = NULL;
        }
        bool exists(T elem) { return (__exists(_root, elem)); }
        // bool empty() { return _size == 0; }
        int height() const
        {
            if (_root == NULL)
                return 0;
            return _root->_height;
        }

        // add an lemenet to this binary tree.
        // return true if the element is added successfully.
        bool insert(value_type elem)
        {
            if (!exists(elem.first))
            {
                _root = add(_root, elem);
                _size++;
                return true;
            }
            return false;
        }
        // return max with recursive
        node_type *max_node(node_type *node)
        {
            if (node->_right == NULL)
                return node;
            else
                return max(node->_right);
        }

        // return min with recursive (smallest value in the tree(left most))
        node_type *min_node(node_type *node)
        {
            if (node->_left == NULL)
                return node;
            else
                return min(node->_left);
        }

        // ! print tree
        void printTree(node_type *node, std::string indent, bool last)
        {
            (void)last;
            if (node != nullptr)
            {
                // std::cout << indent;
                // if (last)
                // {
                //     std::cout << "R----";
                //     indent += "   ";
                // }
                // else
                // {
                //     std::cout << "L----";
                //     indent += "|  ";
                // }
                std::cout << node->_data->second << std::endl;
                // std::cout << "left" << std::endl;
                printTree(node->_left, indent, false);
                // std::cout << "right" << std::endl;
                printTree(node->_right, indent, true);
            }
        }
        void print_it(avl_tree<int, int> &tree)
        {
            tree.printTree(tree._root, "", true);
        }
    };

} // namespace ft