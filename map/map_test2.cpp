#include "map.hpp"

#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define TIME_FAC 20

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}
struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

void testmapConstructors()
{
    time_t start, end, diff;
    /*------------------ std::maps ---------------------*/
    std::map<int, std::string> m1;
    ft::map<int, std::string> ft_m1;
    for (size_t i = 0; i < 1e6; i++)
    {
        m1.insert(std::make_pair(i, "string2"));
        ft_m1.insert(ft::make_pair(i, "string2"));
    }

    start = get_time();
    m1.erase(m1.begin(), m1.end());
    end = get_time();
    diff = end - start;
    diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
    /*-----------------------------------------------------*/
    /*------------------ ft::maps ---------------------*/
    ualarm(diff * 1e3, 0);
    ft_m1.erase(ft_m1.begin(), ft_m1.end());
    ualarm(0, 0);
}

int main()
{
    testmapConstructors();
    return 0;
}