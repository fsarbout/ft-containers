#include <iostream>

int negate(int i)
{
    std::cout << "negate" << std::endl;
    return -i;
}

template <typename T>
typename T::value_type negate(const T &t)
{
    std::cout << "template negate" << std::endl;
    return -T(t);
}

int main()
{
    std::cout << negate(42) << std::endl;
}