#include "iterators/Iterator.hpp"
#include "vector/Vector.hpp"
#include <vector>

int main()
{
    // ! std::vector test
    // std::cout << PURPLE << "std tests" << DEFAULT << std::endl;
    // std::vector<int> values(10, 35);
    // for (size_t i = 0; i < values.size(); i++)
    //     std::cout << values[i] << std::endl;
    // std::vector<int>::iterator it = values.begin();
    // std::cout << "*it" << std::endl;
    // std::cout << *it << std::endl;
    // ! my tests
    std::cout << PURPLE << "my tests <ft>" << DEFAULT << std::endl;
    // ! vector test
    ft::vector<int> v(10, 35);
    // ! iterator test
    // ft::vector <int> v2 = v;
    ft::vector<int>::iterator it2 = v.begin();
    ft::vector<int>::iterator it3 = v.end();
    v.erase(it2, it3);

    // std::cout << "*it2" << std::endl;
    // std::cout << *it2 << std::endl;
    // std::cout << ++it2 << std::endl;
    // std::cout << ++it2 << std::endl;
    // operator -> the current position of iterator
}

// TODO: c
//