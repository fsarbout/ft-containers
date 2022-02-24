#include <iostream>

int main()
{
	for (int i = 0; i < 10; i++)
	{

		std::cout.fill('.');
		std::cout.width(50);
		std::cout << i << std::endl;
	}
}