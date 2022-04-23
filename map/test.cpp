#include "avl_tree.hpp"

int main()
{
    ft::avl_tree<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > tree;
    tree.insert(ft::pair<int, int>(2, 3)); //
    tree.insert(ft::pair<int, int>(5, 65)); //
    tree.insert(ft::pair<int, int>(7, 79)); //
    tree.insert(ft::pair<int, int>(6, 9)); //
    tree.insert(ft::pair<int, int>(3, 45)); //
    tree.insert(ft::pair<int, char>(1, 14)); //
    tree.insert(ft::pair<int, int>(4, 2)); //
    tree.insert(ft::pair<int, int>(8, 143)); //

    std::cout << "tree height: " << tree.height() << std::endl;
    tree.print_it(tree);
}