// 나머지
// https://www.acmicpc.net/problem/3052
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cin.tie(NULL);

    constexpr int divisor = 42;
    int remainder_cnt[divisor] = {0,};
    int dividend, cnt = 0;

    while (std::cin >> dividend)
    {
        int remainder = dividend % divisor;
        if (remainder_cnt[remainder] == 0)
        {
            ++cnt;
        }

        ++remainder_cnt[remainder];
    }

    std::cout << cnt;
}