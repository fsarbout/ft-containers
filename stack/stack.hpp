#pragma once

#include <iostream>
#include <stack>
#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename Container::size_type size_type;

        explicit stack(const container_type &container = container_type()) : _container(container)  {}

        void push(const T &value) { _container.push_back(value); }

        void pop() { _container.pop_back(); }

        value_type& top()  { return _container.back(); }

        const value_type &top() const { return _container.back(); }

        bool empty() const { return _container.empty(); }

        size_type size() const { return _container.size(); }

        friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return lhs._container == rhs._container;
        }
        friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return lhs._container != rhs._container;
        }
        friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return lhs._container > rhs._container;
        }
        friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return lhs._container < rhs._container;
        }
        friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return lhs._container >= rhs._container;
        }
        friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return lhs._container <= rhs._container;
        }

    protected:
        container_type _container;
    };
}