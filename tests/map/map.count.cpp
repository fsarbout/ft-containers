#include "../../utils/make_pair.hpp"
#include "../../map/map.hpp"

#include <iostream> // std::cout
#include <map>      // std::map

// map.count(key) example
// ? *****************************************************************************
//   count(key) : return 1 if element with key key fount                         *
//   0 otherwise                                                                 *
// ? *****************************************************************************

#define GREEN "\e[1;32m"
#define DEFAULT "\e[0;37m"

int main()
{
    std::cout << GREEN;
    std::cout << "***********************************************************" << std::endl;
    std::cout << "*                            STD TEST                     *" << std::endl;
    std::cout << "***********************************************************" << std::endl;
    std::cout << DEFAULT;
    {
        std::map<char, int> mymap;
        char c;

        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;

        for (c = 'a'; c < 'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
    std::cout << GREEN;
    std::cout << "***********************************************************" << std::endl;
    std::cout << "*                            FT  TEST                     *" << std::endl;
    std::cout << "***********************************************************" << std::endl;
    std::cout << DEFAULT;
    {
        ft::map<char, int> mymap;
        char c;

        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;

        for (c = 'a'; c < 'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
    return 0;
}