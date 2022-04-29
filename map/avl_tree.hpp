#pragma once

#include <iostream>
#include <memory>
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"
#include "bidirectional_iterator.hpp"
#include <cstddef>

#define GREEN "\e[1;32m"
#define DEFAULT "\e[0;37m"
#define RED "\e[1;31m"

// * we will need node

namespace ft
{
    // * node class

    // node will be used as internal data for map and tree,
    // each node contains its data and a pointer to left node and a pointer to right node
    template <typename T>
    class Node
    {
    public:
        T *_data;
        Node<T> *_left;
        Node<T> *_right;
        Node<T> *_parent;
        int _height;
        int _balance_factor;
        Node() {}
        ~Node() {}
    };

    // * avl_tree class

    template <class Key,                                                     // map::key_type
              class Mapped_Type,                                             // map::mapped_type
              class Compare = std::less<Key>,                                // map::key_compare
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

        bool _equal(const key_type &key1, const key_type &key2) const
        {
            return (_compare(key1, key2) == false && _compare(key2, key1) == false);
        }

        bool __exists(node_type *node, mapped_type elem) const
        {
            // reached the end of the tree, value not found
            if (node == NULL)
                return false;

            // value found
            else if (_equal(node->_data->first, elem))
                return true;

            // move to the left subtree because the value is smaller than the current node
            else if (_compare(elem, node->_data->first))
                return __exists(node->_left, elem);

            // move to the right subtree because the value is greater than the current node
            else
                return __exists(node->_right, elem);
        }

        // ! end of private methods
        node_type *add(node_type *node, value_type value)
        {
            if (node == NULL)
                return (newNode(value));

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
                node->_data->second = value.second;
            update(node);
            return balance(node);
            // return node;
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
        node_type *remove(node_type *node, key_type key)
        {
            if (!node)
                return NULL;

            if (_compare(key, node->_data->first))
                node->_left = remove(node->_left, key);

            else if (_compare(node->_data->first, key))
                node->_right = remove(node->_right, key);

            else
            {
                if (!node->_left && !node->_right)
                {
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.deallocate(node->_data, 1);
                    _node_allocator.deallocate(node, 1);
                    return NULL;
                }

                else if (!node->_left)
                {
                    node_type *tmp = node->_right;
                    std::swap(node->_data, tmp->_data);
                    node->_right = remove(node->_right, key);
                    return node;
                }

                else if (!node->_right)
                {
                    node_type *tmp = node->_left;
                    std::swap(node->_data, tmp->_data);
                    node->_left = remove(node->_left, key);
                    return node;
                }

                else
                {
                    node_type *tmp = _min(node->_right);
                    std::swap(node->_data, tmp->_data);
                    node->_right = remove(node->_right, key);
                }
            }
            update(node);
            return balance(node);
        }

        void update(node_type *node)
        {
            if (node == NULL)
                return;
            node->_height = 1 + std::max(height(node->_left), height(node->_right));
            node->_balance_factor = height(node->_left) - height(node->_right);
            update(node->_left);
            update(node->_right);
        }

        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                           public methods                                  ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************

    public:
        // constructor
        avl_tree() { _root = NULL; }

        avl_tree(const avl_tree &other) : _root(NULL) { _root = copy(other._root); }

        // constructor with compare and allocator
        avl_tree(const Compare &comp, const allocator_type &alloc) : _root(NULL), _compare(comp), _pair_allocator(alloc), _node_allocator(alloc) {}

        // avl_tree &operator=(const avl_tree &other)
        // {
        //     if (this != &other)
        //     {
        //         clear();
        //         _root = copy(other._root);
        //     }
        //     return *this;
        // }

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
        }

        bool exists(mapped_type elem) { return (__exists(_root, elem)); }

        int height() const
        {
            if (_root == NULL)
                return 0;
            return _root->_height;
        }

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

        // node_type *_max(node_type *node)
        // {
        //     if (node->_right == NULL)
        //         return node;
        //     else
        //         return _max(node->_right);
        // }

        node_type *_min(node_type *node)
        {
            if (node->_left == NULL)
                return node;
            else
                return _min(node->_left);
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
            std::cout << "removing " << key << std::endl;
            _root = remove(_root, key);
            _size--;
            return true;
        }

        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                           balance methods                                 ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************

        node_type *balance(node_type *node)
        {
            if (node->_balance_factor > 1)
            {
                if (node->_left->_balance_factor >= 0)
                    return (right_rotate(node));
                else
                    return (lr_rotate(node));
            }
            // right heavy
            else if (node->_balance_factor < -1)
            {
                if (node->_right->_balance_factor <= 0)
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
            node_type *temp = node->_left;
            node->_left = temp->_right;
            if (temp->_right)
                temp->_right->_parent = node;
            temp->_parent = node->_parent;
            if (!node->_parent)
                _root = temp;
            else if (node == node->_parent->_left)
                node->_parent->_left = temp;
            else
                node->_parent->_right = temp;
            temp->_right = node;
            node->_parent = temp;
            update(node);
            update(temp);
            return temp;
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
        node_type *search(node_type *node, key_type key)
        {
            if (!node)
                return NULL;
            if (key == node->_data->first)
                return node;
            else
                return (key < node->_data->first) ? search(node->_left, key) : search(node->_right, key);
        }

        // ! min max

        node_type *min_node(node_type *node)
        {
            if (node == NULL)
                return (node);
            while (node->_left != NULL)
                node = node->_left;
            return (node);
        }

        // the max node of the given tree
        node_type *max_node(node_type *node)
        {
            if (node == NULL)
                return (node);
            while (node->_right != NULL)
                node = node->_right;
            return (node);
        }

        // test search

        // ! ********************* temp test *********************
        node_type *looking(key_type key)
        {
            node_type *tmp = search(_root, key);
            if (tmp)
            {
                std::cout << "found" << std::endl;
                std::cout << tmp->_data->second << std::endl;
            }
            else
                std::cout << "not found" << std::endl;
            return tmp;
        }

    // !
        bool empty() const
        {
            return (_size == 0);
        }

        // size of tree
        size_type size() const
        {
            return _size;
        }

        // test bidirectional iterator
    };
} // namespace ft
