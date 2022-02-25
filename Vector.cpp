#include <iostream>
#include <vector>
#include "Vector.hpp"

Test::Test(float f, float f2)
{
	_f = f;
	_f2 = f2;
}

Test::Test()
{
}

Test::~Test()
{
}


int Test::cast() const
{
	return _f;
}

Test::operator int() const
{
	return _f;
}

int main()
{
	Test test(4.54684516, 98.394583);

	std::cout << test << std::endl;
	
	std::cout << static_cast<int>(test.cast()) << std::endl;

	std::cout << test.cast() << std::endl;
}