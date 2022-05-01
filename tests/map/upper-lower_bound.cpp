#include "../../utils/make_pair.hpp"
#include "../../map/map.hpp"

#include <iostream> // std::cout
#include <map>      // std::map

// map.lower_bound(key) example
// ? *****************************************************************************
//   find(key) : returns iterator to the element with key equivalent to key.        *
//   If no such element is found, past-the-end (see end()) iterator is returned. *
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
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        // print content:
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout << GREEN;
    std::cout << "***********************************************************" << std::endl;
    std::cout << "*                            FT  TEST                     *" << std::endl;
    std::cout << "***********************************************************" << std::endl;
    std::cout << DEFAULT;
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        // print content:
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}