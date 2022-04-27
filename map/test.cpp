#include "avl_tree.hpp"
#include "bidirectional_iterator.hpp"

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
    ft::pair< int, int> pair7;
    ft::pair< int, int> pair8;
    ft::pair< int, int> pair9;
    ft::pair< int, int> pair10;
    ft::pair< int, int> pair11;
    ft::pair< int, int> pair12;
    ft::pair< int, int> pair13;
    ft::pair< int, int> pair14;
    ft::pair< int, int> pair15;

    pair = ft::make_pair(2, 3);
    pair1 = ft::make_pair(5, 65);
    pair2 = ft::make_pair(1, 79);
    pair3 = ft::make_pair(30, 4);
    pair4 = ft::make_pair(43, 5);
    pair5 = ft::make_pair(63, 51346);
    pair6 = ft::make_pair(71, 71);
    pair7 = ft::make_pair(-2, 72);
    pair8 = ft::make_pair(-3, 0);
    pair9 = ft::make_pair(0, 0);
    pair10 = ft::make_pair(1415, 1415);
    pair11 = ft::make_pair(7, 1);
    pair12 = ft::make_pair(33, 11);
    pair13 = ft::make_pair(11, 33);
    pair14 = ft::make_pair(42, 11);
    pair15 = ft::make_pair(13, 37);


    tree.insert(pair); 
    tree.insert(pair1);
    tree.insert(pair2);
    tree.insert(pair3);
    tree.insert(pair4);
    tree.insert(pair5);
    tree.insert(pair6);
    tree.insert(pair7);
    tree.insert(pair8);
    tree.insert(pair9);
    tree.insert(pair10);
    tree.insert(pair11);
    tree.insert(pair12);
    tree.insert(pair13);
    tree.insert(pair14);
    tree.insert(pair15);


    std::cout << "tree height: " << tree.height() << std::endl << std::endl;
    tree.print_it(tree);
    // tree.remove(pair.first);
    // tree.remove(pair1.first);
    // tree.remove(pair5.first);
    // std::cout << std::endl;
    // tree.remove(pair2.first);
    // std::cout << "after remove " << std::endl << std::endl;
    // system("leaks ft_containers");

    // ! tmp tests   
    tree.looking(13);

    tree.test();

}