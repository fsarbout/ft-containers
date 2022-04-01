#include "iterators/Iterator.hpp"
#include "vector/Vector.hpp"
#include <vector>

int main()
{
    // ! std::vector test
    std::cout << PURPLE << "<std> tests" << DEFAULT << std::endl;
    std::vector<int> vv;
    vv.push_back(161);  // 1
    vv.push_back(24);   // 2
    vv.push_back(23);   // 3
    vv.push_back(45);   // 4
    vv.push_back(5);    // 4
    vv.push_back(4245); // 4
    for (size_t i = 0; i < vv.size(); i++)
        std::cout << vv[i] << " ";
    std::cout << std::endl;
    // vv.insert(vv.begin() + 2, 5); // 5
    vv.insert(vv.begin() + 2, 5); // 5
    for (size_t i = 0; i < vv.size(); i++)
        std::cout << vv[i] << " ";
    std::cout << std::endl;
    std::cout << "size" << vv.size() << std::endl;
    std::cout << "capacity" << vv.capacity() << std::endl;

    // ! my tests
    std::cout << PURPLE << "my tests <ft>" << DEFAULT << std::endl;
    // ! vector test
    ft::vector<int> v;
    v.push_back(161);  // 1
    v.push_back(24);   // 2
    v.push_back(23);   // 3
    v.push_back(45);   // 4
    v.push_back(5);    // 4
    v.push_back(4245); // 4
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    v.insert(v.begin(), 5); // 5
    // v.erase(v.begin() + 2);
    // vv.insert(v.begin() + 2, 5, 42); // 5
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << "size" << vv.size() << std::endl;
    std::cout << "capacity" << vv.capacity() << std::endl;
}