#include <vector>
#include <map>
#include "map.hpp"

int main()
{

    ft::map<int, int> mp;

    for (int i = 0, j = 10; i < 20 * 10000; ++i, ++j)
        mp.insert(ft::make_pair(i, j));

    ft::map<int, int> mp2;

    for (int i = 20 * 10000, j = 200010; i < 40 * 10000; ++i, ++j)
        mp2.insert(ft::make_pair(i, j));

    mp2 = mp;

    // std same test

    std::map<int, int> std_map;
    
    for (int i = 0, j = 10; i < 20 * 10000; ++i, ++j)
        std_map.insert(std::make_pair(i, j));

    std::map<int, int> std_map2;

    for (int i = 20 * 10000, j = 200010; i < 40 * 10000; ++i, ++j)
        std_map2.insert(std::make_pair(i, j));

    std_map2 = std_map;
}