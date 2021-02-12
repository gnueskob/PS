// 최댓값
// https://www.acmicpc.net/problem/2562
#include <iostream>
#include <limits.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cin.tie(NULL);
    int max = INT_MIN, idx = 0, tmp;
    for (int i=0; i<9; ++i)
    {
        std::cin >> tmp;
        if (tmp > max)
        {
            max = tmp;
            idx = i+1;
        }
    }
    std::cout << max << '\n' << idx;
}