#include "iterators/Iterator.hpp"
#include "vector/Vector.hpp"
#include <vector>

// TODO: why can't we access begin() of an empty vector (it's equal to end())
// TODO: but we can insert at it? 


int main()
{
    /**************************************************************************/
    /*                           ! std::vector test                           */
    /**************************************************************************/
    std::cout << PURPLE << "<std> tests" << DEFAULT << std::endl;

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vv;
    std::cout << vv.size();



    std::vector<int>::iterator it = vv.begin();
    std::cout << "size" << vv.size() << std::endl;
    std::cout << "capacity" << vv.capacity() << std::endl;
    vv.insert( it, v.begin(), v.end());
    std::cout << "size=>" << vv.size() << std::endl;
    std::cout << "capacity" << vv.capacity() << std::endl;

    //  ! print vector elements
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    // *** second vector
    //  ! print vector elements
    for (size_t i = 0; i < vv.size(); i++)
        std::cout << vv[i] << " ";
    std::cout << std::endl;

    /**************************************************************************/
    /*                           ! ft::vector test                            */
    /**************************************************************************/
    std::cout << PURPLE << "my tests <ft>" << DEFAULT << std::endl;

    ft::vector<int> mv(10, 30);

    for (size_t i = 0; i < mv.size(); i++)
        std::cout << mv[i] << " ";
    std::cout << std::endl;

    ft::vector<int> mvv;
    // mvv.insert(mvv.begin(), mv.begin(), mv.end());
    mvv.insert(mvv.begin() + 1, 5, 23);

    std::cout << " size " << mvv.size() << std::endl;
    std::cout << " capacity " << mvv.capacity() << std::endl;

    for (size_t i = 0; i < mvv.size(); i++)
        std::cout << mvv[i] << " ";
    std::cout << std::endl;
}