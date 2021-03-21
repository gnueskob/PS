// https://www.acmicpc.net/problem/11279
#include "_fileRead.hpp"
GNUES::FileRead f("11279.txt");

#include <iostream>
#include <queue>
int main()
{
    int n;  std::cin >> n;
    std::priority_queue<int> pq;
    while (n--)
    {
        int num; std::cin >> num;
        if (num > 0)
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