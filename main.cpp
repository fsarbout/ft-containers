#include "iterators/Iterator.hpp"
#include "vector/Vector.hpp"
#include <vector>

int main()
{
    // ! std::vector test
    // // std::cout << PURPLE << "std tests" << DEFAULT << std::endl;
    // // std::vector<int> values(10, 35);
    // // for (size_t i = 0; i < values.size(); i++)
    // //     std::cout << values[i] << std::endl;
    // // std::vector<int>::iterator it = values.begin();
    // // std::cout << "*it" << std::endl;
    // // std::cout << *it << std::endl;
    std::vector<int> vv;
    vv.push_back(161); // 1
    vv.push_back(24);  // 2
    vv.push_back(23);  // 3
    vv.push_back(45);  // 4
    vv.push_back(5);   // 4
    vv.push_back(4245);  // 4
    for (size_t i = 0; i < vv.size(); i++)
        std::cout << vv[i] << " ";
    std::cout << std::endl;
    vv.insert(vv.begin() + 2, 5, 42); // 5
    // std::vector<int>::iterator itw = vv.begin();
    for (size_t i = 0; i < vv.size(); i++)
        std::cout << vv[i] << " ";
    std::cout << std::endl;
    // std::cout << "after erase " << std::endl;
    // vv.erase(itw + 2, itw + 5);

    // for (size_t i = 0; i < vv.size(); i++)
    //     std::cout << vv[i] << " ";
    // std::cout << std::endl;
    
    // ! my tests
    std::cout << PURPLE << "my tests <ft>" << DEFAULT << std::endl;
    // ! vector test
    ft::vector<int> v;
    v.push_back(6);  // 1
    v.push_back(5);  // 2
    v.push_back(4);  // 3
    v.push_back(3);  // 4
    v.push_back(2);  // 5
    v.push_back(1);  // 6
    // v.push_back(7);  // 7
    // v.push_back(89);  // 8
    // v.push_back(79);  // 9
    // v.push_back(110); // 10

    // ! iterator test
    // ft::vector <int> v2 = v;
    ft::vector<int>::iterator it2 = v.begin();
    // ft::vector<int>::iterator it3 = v.end();
    std::cout << "before erase > v: " << v << std::endl;
    // v.erase(it2 + 5);
    // std::cout << "after erase > v: " << v << std::endl;
    // v.clear();
    // std::cout << "after clear > v: " << v << std::endl;
    // v.assign(10, 1);
    // std::cout << "after assign > v: " << v << std::endl;
    std::cout << "v.begin(): " << *(v.begin()) << std::endl;

    // v.insert(it2 + 1, 3, 12);
    // v.erase(it2 + 1);
    // 23, 63
    // v.erase(v.begin() + 7, v.begin() + 2);
    std::cout << "after erase > v: " << v << std::endl;

    // std::cout << "*it2" << std::endl;
    // std::cout << *it2 << std::endl;
    // std::cout << ++it2 << std::endl;
    // std::cout << ++it2 << std::endl;
    // operator -> the current position of iterator
}

// TODO: c
//