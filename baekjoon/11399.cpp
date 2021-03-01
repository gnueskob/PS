// https://www.acmicpc.net/problem/11399
#include "_fileRead.hpp"
GNUES::FileRead f("11399.txt");

#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    int N;
    std::cin >> N;

    std::vector<int> time;
    time.reserve(N);
    while(N--)
    {
        int each_time;
        std::cin >> each_time;
        time.emplace_back(each_time);
    }

    std::sort(time.begin(), time.end());

    int sum = 0, accumulated_sum = 0;
    for (const auto& t : time)
    {
        accumulated_sum += t;
        sum += accumulated_sum;
    }

    std::cout << sum;
}