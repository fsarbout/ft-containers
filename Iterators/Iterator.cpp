#include "Iterator.hpp"
#include <vector>
#include "../Helpers.hpp"

int main()
{
//     std::cout << GREEN << "split" << DEFAULT << std::endl;
//     std::cout << RED << "split" << DEFAULT << std::endl;
//     std::cout << PURPLE << "split" << DEFAULT << std::endl;
//     std::cout << BLUE << "split" << DEFAULT << std::endl;
//     std::cout << YELLOW << "split" << DEFAULT << std::endl;
    std::string str = "Hello World";
    std::string str2 = str;
    std::cout << "str2 " <<  &str2 << std::endl;
    ft::Iterator<std::string> it2;
    it2.setptr(&str2);
    ft::Iterator<std::string> it3(it2);
    ft::Iterator<std::string> it4 = it3;
    std::cout << it2.getptr() << std::endl;
    std::cout << *it2 << std::endl;
    std::cout << &it2 << std::endl;
    std::cout << &it3 << std::endl;

    std::cout << it2.getptr() << std::endl;
    std::cout << "3 from here" << std::endl;
    std::cout << &it2 << std::endl;
    ++it2;
    ++it2;
    std::cout << &it2 << std::endl;
    it2--;
    std::cout << &it2 << std::endl;

    return 0;
}