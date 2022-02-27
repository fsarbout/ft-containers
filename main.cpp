#include "Vector.hpp"

template<typename T>
void printVector(const Vector<T> v)
{
	for (size_t i = 0; i < v.Size(); i++)
		cout << v[i] << endl;
}

int main()
{
	Vector<string> vector;

	for(size_t i = 0; i < 40; i++)
	{

		cout << "push back" << endl;
		cout << "size: " << vector.Size() << endl;
		cout << "capacity: " << vector.Capacity() << endl;
		vector.pushBack("Hello");
	}

	for(size_t i = 0; i < vector.Capacity(); i++)
	{
		cout << "print" << endl;
		cout << "size: " << vector.Size() << endl;
		cout << "capacity: " << vector.Capacity() << endl;
		// printVector(vector);
	}
}