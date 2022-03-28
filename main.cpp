#include "iterators/Iterator.hpp"
#include "vector/Vector.hpp"
#include <vector>


int main()
{
    ft::vector<int> v(10, 35);
    ft::vector<int>::iterator it = v.begin();


    v.insert(it, 5);
    std::cout << v << std::endl;
    

}