// https://www.acmicpc.net/problem/1904
#include <iostream>
int main()
{
    int N, prev2, prev = 1, ans = 2;
    std::cin >> N;
    for (int i=3; i<=N; ++i)
    {
        prev2 = prev;
        prev = ans;
        ans = (prev + prev2) % 15746;
    }

    if (N == 1)
        ans = 1;
    std::cout << ans;
}