#include "map.hpp"

int main()
{
    ft::map<int, std::string> ft_m1;
    for (size_t i = 0; i < 1e6; i++)
    {
        // m1.insert(std::make_pair(i, "string2"));
        ft_m1.insert(ft::make_pair(i, "string2"));
            ft_m1.erase(ft_m1.begin(), ft_m1.end());

    }
}