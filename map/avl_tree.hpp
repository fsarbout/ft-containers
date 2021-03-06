#pragma once
#include <iostream>
#include <memory>
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"
#include "bidirectional_iterator.hpp"
#include <cstddef> // linux

#define DEFAULT "\e[0;37m"
#define GREEN "\e[1;32m"
#define RED "\e[1;31m"

namespace ft
{
    // node will be used as internal data for map and tree,
    // each node contains its data and a pointer to left node and a pointer to right node
    template <typename Pair>
    class Node
    {
    public:
        Pair *_data;
        Node<Pair> *_left;
        Node<Pair> *_right;
        Node<Pair> *_parent;
        int _height;
        int _balance_factor;
        Node() {}
        ~Node() {}
    };

    template <class T>
    Node<T> *min_node(Node<T> *node)
    {
        if (!node)
            return (node);
        while (node->_left)
            node = node->_left;
        return (node);
    }

    template <class T>
    Node<T> *max_node(Node<T> *node)
    {
        if (!node)
            return (node);
        while (node->_right)
            node = node->_right;
        return (node);
    }

    template <class T>
    Node<T> *increment(Node<T> *node, Node<T> *root)
    {
        if (!node)
            node = min_node(root);
        else
        {
            if (node->_right)
            {
                node = node->_right;
                while (node->_left)
                    node = node->_left;
            }
            else
            {
                Node<T> *tmp = node->_parent;

                while (tmp && node == tmp->_right)
                {
                    node = tmp;
                    tmp = tmp->_parent;
                }
                node = tmp;
            }
        }
        return (node);
    }

    template <class T>
    Node<T> *decrement(Node<T> *node, Node<T> *root)
    {
        if (!node)
            node = max_node(root);
        else if (node->_left)
        {
            node = node->_left;
            while (node->_right)
                node = node->_right;
        }
        else
        {
            Node<T> *tmp = node->_parent;
            while (tmp && node == tmp->_left)
            {
                node = tmp;
                tmp = tmp->_parent;
            }
            node = tmp;
        }
        return (node);
    }

    // * avl_tree class

    template <class Key,                                                      // map::key_type
              class Mapped_Type,                                              // map::mapped_type
              class Compare = std::less<Key>,                                 // map::key_compare
              class Alloc = std::allocator<ft::pair<const Key, Mapped_Type> > // map::allocator_type
              >
    class avl_tree
    {
    public:
        typedef Mapped_Type mapped_type;
        typedef Alloc allocator_type;
        typedef Key key_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Node<value_type> node_type;
        typedef typename Alloc::template rebind<node_type>::other node_allocator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        node_type *_root;

        typedef bidirectional_iterator<node_type, value_type> iterator;

    private:
        size_type _size;
        Compare _compare;
        allocator_type _pair_allocator;
        node_allocator _node_allocator;

        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                           private methods                                 ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************

        int height(node_type *node)
        {
            if (node == NULL)
                return 0;
            return 1 + std::max(height(node->_left), height(node->_right));
        }

        bool ___equal(const key_type &key1, const key_type &key2) const
        {
            return (_compare(key1, key2) == false && _compare(key2, key1) == false);
        }

        bool __exists(node_type *node, key_type elem) const
        {
            // reached the end of the tree, value not found
            if (node == NULL)
                return false;

            // value found
            else if (___equal(node->_data->first, elem))
                return true;

            // move to the left subtree because the value is smaller than the current node
            else if (_compare(elem, node->_data->first))
                return __exists(node->_left, elem);

            // move to the right subtree because the value is greater than the current node
            else
                return __exists(node->_right, elem);
        }

        node_type *add(node_type *node, value_type value)
        {
            if (node == NULL)
                return (newNode(value));

            else if (_compare(value.first, node->_data->first))
            {
                node->_left = add(node->_left, value);
                node->_left->_parent = node;
            }
            else if (_compare(node->_data->first, value.first))
            {
                node->_right = add(node->_right, value);
                node->_right->_parent = node;
            }
            update(node);
            return balance(node);
        }

        // allocate a new node
        node_type *newNode(value_type value)
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

        node_type *remove(node_type *node, key_type elem)
        {
            if (_compare(elem, node->_data->first))
                node->_left = remove(node->_left, elem);
            else if (_compare(node->_data->first, elem))
                node->_right = remove(node->_right, elem);
            else
            {
                if (!node->_left && node->_right)
                {
                    node->_right->_parent = node->_parent;
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data, *(node->_right->_data));
                    _pair_allocator.destroy(node->_right->_data);
                    _pair_allocator.deallocate(node->_right->_data, 1);
                    _node_allocator.deallocate(node->_right, 1);
                    node->_right = NULL;
                }
                else if (!node->_right && node->_left)
                {
                    node->_left->_parent = node->_parent;
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data, *(node->_left->_data));
                    _pair_allocator.destroy(node->_left->_data);
                    _node_allocator.deallocate(node->_left, 1);
                    node->_left = NULL;
                }
                else if (!node->_left && !node->_right)
                {
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.deallocate(node->_data, 1);
                    _node_allocator.deallocate(node, 1);
                    node = NULL;
                    return NULL;
                }
                else
                {
                    node_type *tmp = min_node(node->_right);
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data, *(tmp->_data));
                    node->_right = remove(node->_right, tmp->_data->first);
                }
            }
            update(node);
            return (balance(node));
        }

        void update(node_type *node)
        {
            if (node != NULL)
            {
                int leftnode = (node->_left == NULL) ? -1 : node->_left->_height;
                int rightnode = (node->_right == NULL) ? -1 : node->_right->_height;
                node->_height = std::max(leftnode, rightnode) + 1;
                node->_balance_factor = rightnode - leftnode;
            }
        }

        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                           public methods                                  ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************

    public:
        avl_tree() : _root(NULL), _size(0), _compare(), _pair_allocator(), _node_allocator() {}

        avl_tree(const avl_tree &other) : _root(NULL), _size(other._size)
        {
            *this = other;
        }

        avl_tree(const Compare &comp, const allocator_type &alloc) : _root(NULL), _compare(comp), _pair_allocator(alloc), _node_allocator(alloc) {}

        avl_tree &operator=(const avl_tree &other)
        {
            clear();
            node_type *tmp = other._root;
            copy(tmp);
            return *this;
        }

        void copy(node_type *node)
        {
            if (node != NULL)
            {
                insert(*(node->_data));
                copy(node->_left);
                copy(node->_right);
            }
        }

        ~avl_tree()
        {
            clear();
        }

        void clear()
        {
            freee(_root);
            _root = NULL;
            _size = 0;
        }

        void freee(node_type *node)
        {
            if (node)
            {
                freee(node->_left);
                freee(node->_right);
                _pair_allocator.destroy(node->_data);
                _pair_allocator.deallocate(node->_data, 1);
                _node_allocator.deallocate(node, 1);
            }
            node = NULL;
        }

        bool exists(key_type elem) const { return (__exists(_root, elem)); }

        int height() const
        {
            if (_root == NULL)
                return 0;
            return _root->_height;
        }

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

        node_type *_max(node_type *node) const
        {
            while (node && node->_right)
                node = node->_right;
            return node;
        }

        node_type *_min(node_type *node) const
        {
            while (node->_left)
                node = node->_left;
            return node;
        }

        // ! print tree
        void printTree(node_type *node, std::string indent, bool last)
        {
            (void)last;
            if (node != NULL)
            {
                std::cout << RED << indent << DEFAULT;
                if (last)
                {
                    std::cout << GREEN << "R---- " << DEFAULT;
                    indent += "   ";
                }
                else
                {
                    std::cout << RED << "L---- " << DEFAULT;
                    indent += "|  ";
                }
                std::cout << node->_data->first << std::endl;
                printTree(node->_left, indent, false);
                printTree(node->_right, indent, true);
            }
        }

        void print_it(avl_tree<int, int> &tree)
        {
            tree.printTree(tree._root, "", true);
        }

        bool remove(key_type key)
        {
            if (!exists(key))
                return false;
            _root = remove(_root, key);
            _size--;
            return true;
        }

           void swap(avl_tree &other)
        {
            std::swap(_size, other._size);
            std::swap(_root, other._root);
            std::swap(_compare, other._compare);
        }

        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                           balance methods                                 ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************

        node_type *balance(node_type *node)
        {
            if (node->_balance_factor < -1)
            {
                if (node->_left->_balance_factor <= 0)
                    return (right_rotate(node));
                else
                    return (lr_rotate(node));
            }
            else if (node->_balance_factor > 1)
            {
                if (node->_right->_balance_factor >= 0)
                    return (left_rotate(node));
                else
                    return (rl_rotate(node));
            }
            return node;
        }

        node_type *left_rotate(node_type *node)
        {
            node_type *tmp = node->_right;
            node->_right = tmp->_left;
            if (tmp->_left)
                tmp->_left->_parent = node;
            tmp->_parent = node->_parent;
            if (!node->_parent)
                _root = tmp;
            else if (node == node->_parent->_left)
                node->_parent->_left = tmp;
            else
                node->_parent->_right = tmp;
            tmp->_left = node;
            node->_parent = tmp;
            update(node);
            update(tmp);
            return tmp;
        }

        node_type *right_rotate(node_type *node)
        {
            node_type *tmp = node->_left;

            node->_left = tmp->_right;

            if (tmp->_right)
                tmp->_right->_parent = node;
            tmp->_parent = node->_parent;
            if (!node->_parent)
                _root = tmp;
            else if (node == node->_parent->_left)
                node->_parent->_left = tmp;
            else
                node->_parent->_right = tmp;
            tmp->_right = node;
            node->_parent = tmp;
            update(node);
            update(tmp);
            return tmp;
        }

        node_type *lr_rotate(node_type *node)
        {
            node->_left = left_rotate(node->_left);
            return (right_rotate(node));
        }

        node_type *rl_rotate(node_type *node)
        {
            node->_right = right_rotate(node->_right);
            return (left_rotate(node));
        }
        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                           search  methods                                 ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************

        // search in tree
        node_type *search(node_type *node, key_type key) const
        {
            if (!node)
                return NULL;
            if (key == node->_data->first)
                return node;
            else
            {
                if (_compare(key, node->_data->first))
                    return search(node->_left, key);
                else
                    return search(node->_right, key);
            }
        }

        // ! ********************* temp test *********************
        // node_type *looking(key_type key)
        // {
        //     node_type *tmp = search(_root, key);
        //     if (tmp)
        //     {
        //         std::cout << "found" << std::endl;
        //         std::cout << tmp->_data->second << std::endl;
        //     }
        //     else
        //         std::cout << "not found" << std::endl;
        //     return tmp;
        // }

        bool empty() const
        {
            return (_size == 0);
        }

        // size of tree
        size_type size() const
        {
            return _size;
        }

        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                            operation methods                              ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************

        // susscessor is the next node in the tree to the given node a < b < c < d < e < f < g , b succesor is c
        node_type *successor(node_type *node) const
        {
            if (node->_right)
                return _min(node->_right);
            node_type *tmp = node->_parent;
            while (tmp && node == tmp->_right)
            {
                node = tmp;
                tmp = tmp->_parent;
            }
            return tmp;
        }

        // create a function that returns the node with the smallest key >= key, using min_node() method
        node_type *lower_bound(node_type *node, key_type key)
        {
            node_type *tmp = min_node(node);
            while (tmp)
            {
                if (tmp->_data->first >= key)
                    return tmp;
                tmp = successor(tmp);
            }
            return NULL;
        }

        // const lower bound
        node_type *lower_bound(node_type *node, key_type key) const
        {
            node_type *tmp = min_node(node);
            while (tmp)
            {
                if (tmp->_data->first >= key)
                    return tmp;
                tmp = successor(tmp);
            }
            return NULL;
        }

        node_type *upper_bound(node_type *node, key_type key)
        {
            node_type *tmp = min_node(node);
            while (tmp)
            {
                if (tmp->_data->first > key)
                    return tmp;
                tmp = successor(tmp);
            }
            return NULL;
        }

        node_type *upper_bound(node_type *node, key_type key) const
        {
            node_type *tmp = min_node(node);
            while (tmp)
            {
                if (tmp->_data->first > key)
                    return tmp;
                tmp = successor(tmp);
            }
            return NULL;
        }
    };

} // namespace ft
