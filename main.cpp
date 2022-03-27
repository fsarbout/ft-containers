#include "Iterators/Iterator.hpp"
#include <vector>

int main()
{
    ft::iterator<int> it1;
    ft::iterator<int> it2;

    std::cout << it1 <<  std::endl;
    it1++;
    it1--;
    ++it1;
    --it1;
    std::cout << (it1 == it2) << std::endl;
    std::cout << (it1 + it2) << std::endl;
    std::cout << it1 << std::endl;

    // ft::Iterator<int> *it11 = NULL;

    std::cout << it1 + 34543 << std::endl;
    std::cout <<  34543 + it1  << std::endl;

    // std::cout << it11->ptr << std::endl; 
}