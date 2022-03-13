#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
    template <typename T>
    class Iterator
    {

    public:
            typedef T    value_type;
			typedef T*   pointer;
			typedef T& reference;
			typedef ptrdiff_t difference_type;
            // typedef Category  iterator_category;
    
    private:
        pointer _ptr;

    public:
        pointer getptr()
        {
            return _ptr;
        }
        void setptr(pointer ptr)
        {
            _ptr = ptr;
        }
        Iterator()
        {
            std::cout << "default ctor" << std::endl;
        }

        Iterator(const Iterator &obj)
        {
            std::cout << "const copy ctor" << std::endl;
            _ptr = obj._ptr;
        }

        Iterator(Iterator &obj)
        {
            std::cout << "copy ctor" << std::endl;
            _ptr = obj._ptr;
        }

        ~Iterator()
        {
            std::cout << "~ctor" << std::endl;
        }
        Iterator &operator=(const Iterator &obj)
        {
            std::cout << "const assignation operator" << std::endl;
            _ptr = obj._ptr;
            return *this;
        }
        Iterator &operator=(Iterator &obj)
        {
            std::cout << "assignation operator" << std::endl;
            _ptr = obj._ptr;
            return *this;
        }
        Iterator &operator++()
        {
            std::cout << "++operator" << std::endl;
            _ptr++;
            return *this;
        }
        Iterator &operator--()
        {
            std::cout << "--operator" << std::endl;
            _ptr--;
            return *this;
        }
        Iterator operator++(int)
        {
            std::cout << "operator++" << std::endl;
            Iterator tmp(*this);
            _ptr++;
            return tmp;
        }
        Iterator operator--(int)
        {
            std::cout << "operator--" << std::endl;
            Iterator tmp(*this);
            _ptr--;
            return tmp;
        }
        Iterator &operator+=(int n)
        {
            std::cout << "operator+=" << std::endl;
            _ptr += n;
            return *this;
        }
        Iterator &operator-=(int n)
        {
            std::cout << "operator-=" << std::endl;
            _ptr -= n;
            return *this;
        }
        Iterator operator+(int n)
        {
            std::cout << "operator+" << std::endl;
            Iterator tmp(*this);
            tmp._ptr += n;
            return tmp;
        }
        Iterator operator-(int n)
        {
            std::cout << "operator-" << std::endl;
            Iterator tmp(*this);
            tmp._ptr -= n;
            return tmp;
        }
        bool operator==(const Iterator &obj)
        {
            std::cout << "operator==" << std::endl;
            return _ptr == obj._ptr;
        }
        bool operator!=(const Iterator &obj)
        {
            std::cout << "operator!=" << std::endl;
            return _ptr != obj._ptr;
        }
        reference operator*()
        {
            std::cout << "operator*" << std::endl;
            return *_ptr;
        }
        pointer operator->()
        {
            std::cout << "operator->" << std::endl;
            return _ptr;
        }
    };
}


// lvalue  is something that point to a  specific memory location
// rvalue is something that is not a specific memory location (they are temp)


#endif