#include "map.hpp"

int main()
{
    ft::map< int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > tree;
    ft::map< int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > tree1;

    std::map<int, int> std_tree;
    ft::map<int, int> ft_tree;
    
    // iterator 
    ft::map< int, int, std::less<int>, std::allocator<ft::pair<const int, int> > >::iterator it, it1;
    
    

    tree1.insert(ft::pair<int, int>(34, 3415));
    tree1.insert(ft::pair<int, int>(1, 435));
    tree1.insert(ft::pair<int, int>(145, 513));
    tree1.insert(ft::pair<int, int>(12, 513));

    tree.insert(ft::pair<int, int>(34, 3415));
    tree.insert(ft::pair<int, int>(1, 435));
    tree.insert(ft::pair<int, int>(145, 513));
    tree.insert(ft::pair<int, int>(12, 513));

    it = tree1.begin(); 
    it1 = tree1.end();
    
    // insert range
    // tree.insert(it, it1);

    // tree.insert(tree1.begin(), tree1.end());

    // reverse_iterator
    ft::map< int, int, std::less<int>, std::allocator<ft::pair<const int, int> > >::reverse_iterator rit, rit1;

    
    rit = tree.rend();
    rit1 = tree.rbegin();


    std::cout << "empty method: " << tree.empty() << std::endl;
    std::cout << "size method: " << tree.size() << std::endl;
    std::cout << "max_size method: " << tree.max_size() << std::endl;

    // std::cout << it->first << " " << it->second  << std::endl;

    std::cout << "tree : " << std::endl;
    tree.print();
    std::cout << "tree2 : " << std::endl;
    tree1.print();
    
}