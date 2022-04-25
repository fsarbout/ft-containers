#pragma once

#include <iostream>
#include <memory>
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"

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

        Node(T *data, Node<T> *right, Node<T> *left, Node<T> *parent) : _data(data), _left(left), _right(right), _parent(parent) {}

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

        bool __exists(node_type *node, T elem) const
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
            // balance(node);
            return node;
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
                    std::cout << "end" << std::endl;
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
                    node_type *tmp = min_node(node->_right);
                    std::swap(node->_data, tmp->_data);
                    node->_right = remove(node->_right, key);
                }
            }
            update(node);
            // I have to return the balanced node
            return node;
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
                return max_node(node->_right);
        }

        // return min with recursive (smallest value in the tree(left most))
        node_type *min_node(node_type *node)
        {
            if (node->_left == NULL)
                return node;
            else
                return min_node(node->_left);
        }

        // ! print tree
        void printTree(node_type *node, std::string indent, bool last)
        {
            (void)last;
            if (node != nullptr)
            {
                std::cout << indent;
                if (last)
                {
                    std::cout << "R----";
                    indent += "   ";
                }
                else
                {
                    std::cout << "L----";
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

        // ! ***********************************************************************************
        // ! ***********************************************************************************
        // ! ****                           balance methods                                 ****
        // ! ***********************************************************************************
        // ! ***********************************************************************************
        
        // TODO : is_balanced(tree)
        // TODO : balance(tree)
        // TODO : left_rotate(tree)
        // TODO : right_rotate(tree)
        // TODO : left_right_rotate(tree)
        // TODO : right_left_rotate(tree)
        // TODO : balance_factor(tree)
        
        // bool is_balanced(node_type *node)
        // {
        //     if (node == NULL)
        //         return true;
        //     if (abs(balance_factor(node)) > 1)
        //         return false;
        //     return is_balanced(node->_left) && is_balanced(node->_right);
        // }

        // void balance(node_type &node)
        // {
        //     if (balance_factor(node) > 1)
        //     {
        //         if (balance_factor(node->_left) < 0)
        //             left_rotate(node->_left);
        //         right_rotate(node);
        //     }
        //     else if (balance_factor(node) < -1)
        //     {
        //         if (balance_factor(node->_right) > 0)
        //             right_rotate(node->_right);
        //         left_rotate(node);
        //     }
        // }

        // void left_rotate(node_type &node)
        // {
        //     (void)node;
        //     std::cout << "left_rotate" << std::endl;
        // }
        // void right_rotate(node_type &node)
        // {
        //     (void)node;
        //     std::cout << "right_rotate" << std::endl;
        // }
        // void left_right_rotate(node_type &node)
        // {
        //     (void)node;
        //     std::cout << "left_right_rotate" << std::endl;
        // }
        // void right_left_rotate(node_type &node)
        // {
        //     (void)node;
        //     std::cout << "right_left_rotate" << std::endl;
        // }



        

    };
} // namespace ft
