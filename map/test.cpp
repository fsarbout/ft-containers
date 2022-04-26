#include "avl_tree.hpp"

int main()
{
    ft::avl_tree<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > tree;

    ft::pair< int, int> pair;
    ft::pair< int, int> pair1;
    ft::pair< int, int> pair2;
    ft::pair< int, int> pair3;
    ft::pair< int, int> pair4;
    ft::pair< int, int> pair5;
    ft::pair< int, int> pair6;



    pair = ft::make_pair(2, 3);
    pair1 = ft::make_pair(5, 65);
    pair2 = ft::make_pair(1, 79);
    pair3 = ft::make_pair(30, 4);
    pair4 = ft::make_pair(43, 5);

    // pair5 = ft::make_pair(63, 51346);
    // pair6 = ft::make_pair(71, 71);



    tree.insert(pair); 
    tree.insert(pair1);
    tree.insert(pair2);
    tree.insert(pair3);
    tree.insert(pair4);
    // tree.insert(pair5);
    // tree.insert(pair6);



    std::cout << "tree height: " << tree.height() << std::endl << std::endl;
    tree.print_it(tree);
    // tree.remove(pair.first);
    // tree.remove(pair1.first);
    // tree.remove(pair5.first);
    // std::cout << std::endl;
    // tree.remove(pair2.first);
    // std::cout << "after remove " << std::endl << std::endl;
    // tree.print_it(tree);
    // system("leaks ft_containers");
}