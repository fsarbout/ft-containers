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

	vector.pushBack("fatima zahra");
}