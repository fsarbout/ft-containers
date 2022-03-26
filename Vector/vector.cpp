// test ft::vector

#include "vector.hpp"
#include "../Helpers.hpp"

int main()
{
    ft::vector<int> v;
    // test all the methods
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    v.pop_back();
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    v.pop_back();
    v.push_back(5);
    v.push_back(6);
    std::cout << v << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    v.reserve(10);
    std::cout << v.capacity() << std::endl;
    v.resize(10);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    v.resize(5);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    v.clear();
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    // v.assign(10, 1);
    std::cout << v << std::endl;
    // v.assign(10, 2);
    std::cout << v << std::endl;
    // assing with iterators
    ft::vector<int> v2;
    v2.assign(v.begin(), v.end());
    std::cout << v2 << std::endl;
    // test the iterator
    ft::vector<int>::iterator it = v.begin();
    it++;
}