#include "iterators/Iterator.hpp"
#include "vector/Vector.hpp"
#include <vector>

int main()
{
    /**************************************************************************/
    /*                           ! std::vector test                            */
    /**************************************************************************/
    std::cout << PURPLE << "<std> tests" << DEFAULT << std::endl;

    std::vector<int> vv;
    vv.push_back(161); 
    vv.push_back(24);  
    vv.push_back(23);  
    vv.push_back(45);  
    vv.push_back(5);   
    vv.push_back(4245);
    //  ! print vector elements before changes
    for (size_t i = 0; i < vv.size(); i++)
        std::cout << vv[i] << " ";
    std::cout << std::endl;
    vv.insert(vv.begin() + 2, 111111111);
    // vv.erase(vv.begin() + 4);
    //  ! print vector elements after changes
    for (size_t i = 0; i < vv.size(); i++)
        std::cout << vv[i] << " ";
    std::cout << std::endl;
    // ! check for size and capacity
    std::cout << "size " << vv.size() << std::endl;
    std::cout << "capacity " << vv.capacity() << std::endl;

    /**************************************************************************/
    /*                           ! ft::vector test                            */
    /**************************************************************************/
    std::cout << PURPLE << "my tests <ft>" << DEFAULT << std::endl;

    ft::vector<int> v;
    v.push_back(161);
    v.push_back(24);
    v.push_back(23);
    v.push_back(45);
    v.push_back(5);
    v.push_back(4245);
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "==" << std::endl;
    v.insert(v.begin() + 2, 111111111);
    // v.erase(v.begin() + 4);
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << "size " << vv.size() << std::endl;
    std::cout << "capacity " << vv.capacity() << std::endl;
}