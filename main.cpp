#include "iterators/Iterator.hpp"
#include "vector/Vector.hpp"
#include <vector>

// TODO: why can't we access begin() of an empty vector (it's equal to end())
// TODO: but we can insert at it?

#define GREEN "\e[1;32m"
#define RED "\e[1;31m"
#define WHITE "\e[1;37m"
#define DEFAULT "\e[0;37m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define PURPLE "\e[1;35m"
#define COLOR "\e[1;36m"

int main()
{
    std::cout << COLOR;
    std::cout << "***********************************************************" << std::endl;
    std::cout << "*                       FILL CONSTRUCTOR                  *" << std::endl;
    std::cout << "***********************************************************" << std::endl;
    std::cout << DEFAULT;

    //! ***********************************************************************/
    //                           ! std::vector test                           */
    //! ***********************************************************************/

    std::string res, my_res;

    std::string str = "Hello World";

    std::cout << "***********************************************************" << std::endl;
    std::cout << "*                  \e[1;32mstd tests\e[0;37m  /  \e[1;34mft tests\e[0;37m                 *" << std::endl;
    std::cout << "***********************************************************" << std::endl;



    // fill constructor test
    std::vector<std::string> std_vector(1000, str);

    for (std::vector<std::string>::iterator it = std_vector.begin(); it != std_vector.end(); ++it) // fill res from std::vector
        res += *it;

    // std::cout << GREEN << "Vector content: " << DEFAULT;
    // for (size_t i = 0; i < std_vector.size(); i++)
    //     std::cout << "\"" << std_vector[i] << "\""
    //               << " ";
    // std::cout << std::endl;

    std::cout << GREEN << "Vector size: " << DEFAULT << std_vector.size() << std::endl;
    std::cout << GREEN << "Vector capacity: " << DEFAULT << std_vector.capacity() << std::endl;

    //! ***********************************************************************/
    //                           ! ft::vector test                            */
    //! ***********************************************************************/

    // fill constructor test
    ft::vector<std::string> ft_vector(1000, str);

    // std::cout << BLUE << "Vector content: " << DEFAULT;
    // for (size_t i = 0; i < ft_vector.size(); i++)
    //     std::cout << "\"" << ft_vector[i] << "\""
    //               << " ";
    // std::cout << std::endl;


    for (ft::vector<std::string>::iterator it = ft_vector.begin(); it != ft_vector.end(); ++it) // fill my_res from ft::vector
        my_res += *it;

    std::cout << BLUE << "Vector size: " << DEFAULT << ft_vector.size() << std::endl;
    std::cout << BLUE << "Vector capacity: " << DEFAULT << ft_vector.capacity() << std::endl;

    //! ****************************************************************************************************************/

    std::cout << COLOR;
    std::cout << "***********************************************************" << std::endl;
    std::cout << "*                          INSERT                         *" << std::endl;
    std::cout << "***********************************************************" << std::endl;
    std::cout << DEFAULT;

    //! ***********************************************************************/
    //                           ! std::vector test                           */
    //! ***********************************************************************/

    std::cout << "***********************************************************" << std::endl;
    std::cout << "*                  \e[1;32mstd tests\e[0;37m  /  \e[1;34mft tests\e[0;37m                 *" << std::endl;
    std::cout << "***********************************************************" << std::endl;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.insert(v.begin(), 5, 9);
    std::cout << GREEN << "Vector content: " << DEFAULT;
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << GREEN << "Vector size: " << DEFAULT << v.size() << std::endl;
    std::cout << GREEN << "Vector capacity: " << DEFAULT << v.capacity() << std::endl;

    //! ***********************************************************************/
    //                           ! ft::vector test                            */
    //! ***********************************************************************/

    ft::vector<int> my_v;
    ft::vector<int>::iterator it = my_v.begin();
    ft::vector<int>::iterator it2 = my_v.begin() + 3;
    my_v.push_back(1);
    my_v.push_back(2);
    my_v.push_back(3);
    my_v.push_back(4);
    my_v.push_back(5);
    my_v.push_back(6);
    my_v.push_back(1);
    my_v.push_back(2);
    my_v.push_back(3);
    my_v.push_back(4);
    my_v.push_back(5);
    my_v.push_back(6);
    my_v.insert(it, 5, 9);
    std::cout << BLUE << "Vector content: " << DEFAULT;
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << BLUE << "Vector size: " << DEFAULT << v.size() << std::endl;
    std::cout << BLUE << "Vector capacity: " << DEFAULT << v.capacity() << std::endl;
}