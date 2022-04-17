#include "vector/iterator.hpp"
#include "vector/vector.hpp"
#include <vector>

// TODO: why can't we access begin() of an empty vector (it's equal to end())
// TODO: but we can insert at it?

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

#define GREEN "\e[1;32m"
#define RED "\e[1;31m"
#define WHITE "\e[1;37m"
#define DEFAULT "\e[0;37m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define PURPLE "\e[1;35m"
#define COLOR "\e[1;36m"
class dd {
public:
    std::string name;
    dd() {
        std::cout << "dd()" << std::endl;
    }
    ~dd() {
        std::cout << "~dd()" << std::endl;
    }
};

int main()
{
    // /*
    //  * strings to store the resutls
    //  */
    // std::string str, ft_str;
    // /*
    //  * var to store the size and the capacity
    //  */
    // ft::vector<std::string>::size_type s, ft_s;
    // ft::vector<std::string>::size_type c, ft_c;
    // /*
    //  * bool to store the comparison
    //  */
    // bool cond;

    // /*------------------------------- test 1: empty vector ----------------------------------------*/
    // // insert at the begin
    // {
    //     std::vector<std::string> v1(300, "string");
    //     std::vector<std::string> v;
    //     ft::vector<std::string> ft_v;
    //     v.insert(v.begin(), v1.begin(), v1.end());
    //     ft_v.insert(ft_v.begin(), v1.begin(), v1.end());
    //     ft_v.begin()->length();

    //     s = v.size();
    //     ft_s = ft_v.size();
    //     c = v.capacity();
    //     ft_c = ft_v.capacity();
    //     for (size_t i = 0; i < v.size(); ++i)
    //         str += v[i];
    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         ft_str += ft_v[i];
    //     cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));

    //     std::cout << GREEN;

    //     for (size_t i = 0; i < v.size(); ++i)
    //         std::cout << v.at(i) << " ";
    //     std::cout << v.size() << " " << v.capacity() << std::endl;

    //     // std::cout << "oiaheioehgiouhigh eiuherheiugh iufhewgh iuhegipuehwehg" << std::endl;
    //     std::cout << DEFAULT;

    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         std::cout << ft_v.at(i) << " ";
    //     std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
    // }
    // // insert at the end
    // {
    //     std::vector<std::string> v;
    //     ft::vector<std::string> v1(300, "string");
    //     ft::vector<std::string> ft_v;

    //     v.insert(v.end(), v1.begin(), v1.end());
    //     ft_v.insert(ft_v.end(), v1.begin(), v1.end());
    //     ft_v.begin()->length();

    //     str.clear();
    //     ft_str.clear();

    //     s = v.size();
    //     ft_s = ft_v.size();
    //     c = v.capacity();
    //     ft_c = ft_v.capacity();
    //     for (size_t i = 0; i < v.size(); ++i)
    //         str += v[i];
    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         ft_str += ft_v[i];
    //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));

    //     std::cout << GREEN;

    //     for (size_t i = 0; i < v.size(); ++i)
    //         std::cout << v.at(i) << " ";
    //     std::cout << v.size() << " " << v.capacity() << std::endl;

    //     // std::cout << "oiaheioehgiouhigh eiuherheiugh iufhewgh iuhegipuehwehg" << std::endl;
    //     std::cout << DEFAULT;

    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         std::cout << ft_v.at(i) << " ";
    //     std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
    // }
    // /*---------------------------------------------------------------------------------------------------*/
    // /*------------------------------- test 2: the vector capacity >= size + n ----------------------------------------*/
    // {
    //     std::vector<std::string> v1(70, "hello");
    //     std::vector<std::string> v(20, "string");
    //     ft::vector<std::string> ft_v(20, "string");
    //     ft::vector<std::string>::iterator valid_it;

    //     v.reserve(100);
    //     ft_v.reserve(100);
    //     valid_it = ft_v.begin();
    //     v.insert(v.begin() + 15, v1.begin(), v1.end());
    //     ft_v.insert(ft_v.begin() + 15, v1.begin(), v1.end());

    //     str.clear();
    //     ft_str.clear();
    //     s = v.size();
    //     ft_s = ft_v.size();
    //     c = v.capacity();
    //     ft_c = ft_v.capacity();
    //     for (size_t i = 0; i < v.size(); ++i)
    //         str += v[i];
    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         ft_str += ft_v[i];
    //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));

    //     std::cout << GREEN;

    //     for (size_t i = 0; i < v.size(); ++i)
    //         std::cout << v.at(i) << " ";
    //     std::cout << v.size() << " " << v.capacity() << std::endl;

    //     // std::cout << "oiaheioehgiouhigh eiuherheiugh iufhewgh iuhegipuehwehg" << std::endl;
    //     std::cout << DEFAULT;

    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         std::cout << ft_v.at(i) << " ";
    //     std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
    // }
    // /*---------------------------------------------------------------------------------------------------*/
    // /*------------------------------- test 3: the vector capacity < size + n && n > size ----------------------------------------*/
    // {
    //     ft::vector<std::string> v1(100, "hello");
    //     std::vector<std::string> v(20, "string");
    //     ft::vector<std::string> ft_v(20, "string");

    //     v.insert(v.begin() + 10, v1.begin(), v1.end());
    //     ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());

    //     str.clear();
    //     ft_str.clear();
    //     s = v.size();
    //     ft_s = ft_v.size();
    //     c = v.capacity();
    //     ft_c = ft_v.capacity();
    //     for (size_t i = 0; i < v.size(); ++i)
    //         str += v[i];
    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         ft_str += ft_v[i];
    //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));

    //     std::cout << GREEN;

    //     for (size_t i = 0; i < v.size(); ++i)
    //         std::cout << v.at(i) << " ";
    //     std::cout << v.size() << " " << v.capacity() << std::endl;

    //     // std::cout << "oiaheioehgiouhigh eiuherheiugh iufhewgh iuhegipuehwehg" << std::endl;
    //     std::cout << DEFAULT;

    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         std::cout << ft_v.at(i) << " ";
    //     std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
    // }
    // /*---------------------------------------------------------------------------------------------------*/
    // /*------------------------------- test 4: the vector capacity < size + n && n <= size ----------------------------------------*/
    // {
    //     std::vector<std::string> v1(15, "hello");
    //     std::vector<std::string> v(20, "string");
    //     ft::vector<std::string> ft_v(20, "string");

    //     v.insert(v.begin() + 10, v1.begin(), v1.end());
    //     ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());

    //     str.clear();
    //     ft_str.clear();
    //     s = v.size();
    //     ft_s = ft_v.size();
    //     c = v.capacity();
    //     ft_c = ft_v.capacity();
    //     for (size_t i = 0; i < v.size(); ++i)
    //         str += v[i];
    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         ft_str += ft_v[i];
    //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));

    //     std::cout << GREEN;

    //     for (size_t i = 0; i < v.size(); ++i)
    //         std::cout << v.at(i) << " ";
    //     std::cout << v.size() << " " << v.capacity() << std::endl;

    //     // std::cout << "oiaheioehgiouhigh eiuherheiugh iufhewgh iuhegipuehwehg" << std::endl;
    //     std::cout << DEFAULT;

    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         std::cout << ft_v.at(i) << " ";
    //     std::cout << ft_v.size() << " " << ft_v.capacity() << std::endl;
    // }
    /*---------------------------------------------------------------------------------------------------*/

    // /*---------------------------------------------------------------------------------------------------*/
    // EQUAL(cond);

    //  print vector elements

    // ! iuhiuhiuwehg

    // ! iuhiuhiuwehg

    // EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));

    // std::cout << COLOR;
    // std::cout << "***********************************************************" << std::endl;
    // std::cout << "*                       FILL CONSTRUCTOR                  *" << std::endl;
    // std::cout << "***********************************************************" << std::endl;
    // std::cout << DEFAULT;

    // //! ***********************************************************************/
    // //                           ! std::vector test                           */
    // //! ***********************************************************************/

    // std::string res, my_res;

    // std::string str = "Hello World";

    // std::cout << "***********************************************************" << std::endl;
    // std::cout << "*                  \e[1;32mstd tests\e[0;37m  /  \e[1;34mft tests\e[0;37m                 *" << std::endl;
    // std::cout << "***********************************************************" << std::endl;

    // // fill constructor test
    // std::vector<std::string> std_vector(1000, str);

    // for (std::vector<std::string>::iterator it = std_vector.begin(); it != std_vector.end(); ++it) // fill res from std::vector
    //     res += *it;

    // // std::cout << GREEN << "Vector content: " << DEFAULT;
    // // for (size_t i = 0; i < std_vector.size(); i++)
    // //     std::cout << "\"" << std_vector[i] << "\""
    // //               << " ";
    // // std::cout << std::endl;

    // std::cout << GREEN << "Vector size: " << DEFAULT << std_vector.size() << std::endl;
    // std::cout << GREEN << "Vector capacity: " << DEFAULT << std_vector.capacity() << std::endl;

    // //! ***********************************************************************/
    // //                           ! ft::vector test                            */
    // //! ***********************************************************************/

    // // fill constructor test
    // ft::vector<std::string> ft_vector(1000, str);

    // // std::cout << BLUE << "Vector content: " << DEFAULT;
    // // for (size_t i = 0; i < ft_vector.size(); i++)
    // //     std::cout << "\"" << ft_vector[i] << "\""
    // //               << " ";
    // // std::cout << std::endl;

    // for (ft::vector<std::string>::iterator it = ft_vector.begin(); it != ft_vector.end(); ++it) // fill my_res from ft::vector
    //     my_res += *it;

    // std::cout << BLUE << "Vector size: " << DEFAULT << ft_vector.size() << std::endl;
    // std::cout << BLUE << "Vector capacity: " << DEFAULT << ft_vector.capacity() << std::endl;

    // std::cout << RED << "************************************************************************" << DEFAULT << std::endl;

    // std::cout << COLOR;
    // std::cout << "***********************************************************" << std::endl;
    // std::cout << "*                          INSERT                         *" << std::endl;
    // std::cout << "***********************************************************" << std::endl;
    // std::cout << DEFAULT;

    // //! ***********************************************************************/
    // //                           ! std::vector test                           */
    // //! ***********************************************************************/

    // std::cout << "***********************************************************" << std::endl;
    // std::cout << "*                  \e[1;32mstd tests\e[0;37m  /  \e[1;34mft tests\e[0;37m                 *" << std::endl;
    // std::cout << "***********************************************************" << std::endl;

    // std::vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.insert(v.begin(), 5, 9);
    // std::cout << GREEN << "Vector content: " << DEFAULT;
    // for (size_t i = 0; i < v.size(); i++)
    //     std::cout << v[i] << " ";
    // std::cout << std::endl;
    // std::cout << GREEN << "Vector size: " << DEFAULT << v.size() << std::endl;
    // std::cout << GREEN << "Vector capacity: " << DEFAULT << v.capacity() << std::endl;

    // //! ***********************************************************************/
    // //                           ! ft::vector test                            */
    // //! ***********************************************************************/

    // ft::vector<int> my_v;
    // ft::vector<int>::iterator it = my_v.begin();
    // ft::vector<int>::iterator it2 = my_v.begin() + 3;
    // my_v.push_back(1);
    // my_v.push_back(2);
    // my_v.push_back(3);
    // my_v.push_back(4);
    // my_v.push_back(5);
    // my_v.push_back(6);
    // my_v.push_back(1);
    // my_v.push_back(2);
    // my_v.push_back(3);
    // my_v.push_back(4);
    // my_v.push_back(5);
    // my_v.push_back(6);
    // my_v.insert(it, 5, 9);
    // std::cout << BLUE << "Vector content: " << DEFAULT;
    // for (size_t i = 0; i < v.size(); i++)
    //     std::cout << v[i] << " ";
    // std::cout << std::endl;
    // std::cout << BLUE << "Vector size: " << DEFAULT << v.size() << std::endl;
    // std::cout << BLUE << "Vector capacity: " << DEFAULT << v.capacity() << std::endl;
        ft::vector<dd> v;
        dd d;
        d.name = "s";
        v.push_back(d);
      const   ft::vector<dd>::const_iterator it = v.begin();
        // it->name = "2ffdfds";
        // it-> .
        std::cout << it->name << std::endl;
}

// TODO: THIS TEST SEGVAULT WITHOUT FSANITIZE=ADDRESS
// TODO: VECTOR MUST BE DONE TODAY, SO TOMORROW INSHALLAH MAP
