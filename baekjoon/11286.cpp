// https://www.acmicpc.net/problem/11286
#include "_fileRead.hpp"
GNUES::FileRead f("11286.txt");

#include <iostream>
#include <functional>
#include <queue>
int main()
{
    int n;  std::cin >> n;

    auto abs_greater = [](int l, int r)
    {
        auto abs_l = std::abs(l);
        auto abs_r = std::abs(r);
        if (abs_l == abs_r)
            return l > r;
        else
            return abs_l > abs_r;
    };

    std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>> pq(abs_greater);
    while (n--)
    {
        int num; std::cin >> num;
        if (num != 0)
            pq.emplace(num);
        else if (num == 0)
        {
            int top = 0;
            if (pq.empty() == false)
            {
                top = pq.top();
                pq.pop();
            }
            std::cout << top << '\n';
        }
    }
}