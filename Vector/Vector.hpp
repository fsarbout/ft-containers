#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
	template <typename T>
	class Vector
	{

	public:
		typedef value_type T;
		typedef allocator_type std::allocator;
		typedef reference T &;
		typedef const_reference const T &;
		typedef pointer T *;
		typedef const_pointer const T *;
		// typedef iterator const_iterator;
		// typedef reverse_iterator ;
		// typedef const_reverse_iterator ;
		typedef difference_type ptrdiff_t;
		typedef size_type size_t;

	private:
		T *_arr;
		size_type _size;
		size_type _capacity;
		allocator_type allocator

	public:
		Vector();
		~Vector();
		Vector &operator=(const Vector &obj)
		{
			std::cout << GREEN << "OPERATOR =" << DEFAULT << std::endl;
			this->_arr = obj._arr;
		}
		// Iterators
		// ! mashi daba
		// * CAPACITY
		size_type size()
		{
			return _size;
		}
		// size_type max_size()
		// {
		// 	return std::distance(_arr[0], _arr[_size]);
		// }
		void resize(size_type n, value_type val)
		{
			// n => new container size
			// val => value to inset at index n
			if (n > _size)
			{
				_arr[n] = val;
			}
			// else I think I have to delete elment from n index to end
			// else
			// 	_arr = allocator.deallocate(_arr, );
		}
		void resize(size_type n)
		{
			if (n > _size)
				_size = n;
			// else 
			// 	deallocate the extra memory
		}
		type_size capacity()
		{
			return _capacity;
		}
		bool empty()
		{
			return (_size == 0);
		}
		void reserve(size_type n)
		{
			if (n > _capacity)
			{
				_capacity = n;
				// n or greater
			}
		}
		// * ELEMENT ACCESS
		T* &operator[](size_type n)
		{
			return _arr[n]; 
		}
		T& at(size_type n)
		{
			if (n >= _size)
				std::cout << RED << "OUT OF RANGE EXCEPTION" << DEFAULT << std::endl;
			return _arr[n];
			// Notice that the first element has a position of 0 (not 1). ????!!
		}
		T& front()
		{
			return _arr[0];
		}
		T& front()
		{
			return _arr[0];
		}
		T& back()
		{
			return _arr[_size];
		}
		// * MODIFIERS
		void assign(iterator it1,iterator  it1, size_type n, )
		{

		}
		void push_back(value_type val)
		{
			_arr[_size + 1]  = val;
		}
		void push_back(value_type val)
		{
			//  deallocate _arr[_size];
		}
		// insert()
		


	};
}

#endif

// ? SHOULD WE HANDLE EXCEPTIONS ??