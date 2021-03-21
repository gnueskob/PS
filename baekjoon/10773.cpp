// https://www.acmicpc.net/problem/10773
#include "_fileRead.hpp"
GNUES::FileRead f("10773.txt");

#include <iostream>
#include <stack>
int main()
{
    std::stack<int> stk;
    int N, ans = 0;
    std::cin >> N;
    while (N--)
    {
        int num;
        std::cin >> num;
        if (num == 0)
        {
            ans -= stk.top();
            stk.pop();
        }
        else
        {
            ans += num;
            stk.emplace(num);
        }
    }

    std::cout << ans;
}