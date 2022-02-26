#include <iostream>
#include <vector>
#include "Test.hpp"
#include "Helpers.hpp"

Test::Test()
{
}

Test::~Test()
{
}

int main()
{
	std::vector<int> Vc;
	
	for (int i = 0; i < 100; i++)
	{
		Vc.push_back(i);
	}
	cout << Vc.capacity() << endl;
	cout << "&vs: " << &Vc << endl;
	cout << "vc[0]: " <<  Vc[0] << " &vc[0]: " << &Vc[0] << endl;
	for (int i =200; i < 401; i++)
	{
		Vc.push_back(i);
	}
	cout << Vc.capacity() << endl;
	cout << "&vs: " << &Vc << endl;
	cout << "vc[0]: " <<  Vc[0] << " &vc[0]: " << &Vc[0] << endl;
}