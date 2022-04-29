#include "map.hpp"

int main()
{
    ft::map< int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > tree;
    
    // iterator 
    ft::map< int, int, std::less<int>, std::allocator<ft::pair<const int, int> > >::iterator it1, it2, it3, it4;
    
    it1 = tree.begin(); 
    it2 = tree.end();
    // it3 = tree.rbegin();
    // it4 = tree.rend();

    std::cout << "empty method: " << tree.empty() << std::endl;
    std::cout << "size method: " << tree.size() << std::endl;
    std::cout << "max_size method: " << tree.max_size() << std::endl;
    
}