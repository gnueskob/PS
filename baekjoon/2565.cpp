// https://www.acmicpc.net/problem/2565
#include "_fileRead.hpp"
GNUES::FileRead f("2565.txt");

#include <iostream>
#include <vector>
#include <map>
#include <climits>
int main()
{
    // 결국 전깃줄 B의 LIS(최장 증가 부분수열)의 길이를 찾는 문제
    std::vector<int> lis;
    std::map<int, int> link;    // (a, b)
    int N;
    std::cin >> N;
    lis.reserve(N + 1);
    lis.push_back(INT_MIN);

    for (int i=0; i<N; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        link.emplace(a, b);
    }

    for (const auto& [a, b] : link)
    {
        auto itr = std::upper_bound(lis.begin(), lis.end(), b);
        if (itr == lis.end())
        {
            lis.push_back(b);
        }
        else
        {
            *itr = b;
        }
    }

    std::cout << N - lis.size() + 1;
}
