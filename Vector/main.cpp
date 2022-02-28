#include "Vector.hpp"

template<typename T>
void printVector(const Vector<T> v)
{
	for (size_t i = 0; i < v.Size(); i++)
		std::cout << v[i] << std::endl;
}

int main()
{
	Vector<std::string> vector;
	Vector<std::string> vector2(vector);

	for(size_t i = 0; i < 400; i++)
		vector.pushBack("Hello");
	std::cout << "size: " << vector.Size() << std::endl;
	std::cout << "capacity: " << vector.Capacity() << std::endl;
}