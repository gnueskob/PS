// https://www.acmicpc.net/problem/10942
#include "_fileRead.hpp"
GNUES::FileRead f("10942.txt");

#include <iostream>

enum RESULT
{
    NONE = 0,
    PALINDROME = 1,
    NOT_PALINDROME = 2,
};

// dp[S][E] : S ~ E 숫자 팰린드롬 여부
RESULT dp[2000][2000];
int arr[2000];

RESULT solve(int s, int e)
{
    if (dp[s][e] != RESULT::NONE)
        return dp[s][e];

    if (arr[s] != arr[e])
    {
        dp[s][e] = RESULT::NOT_PALINDROME;
        return RESULT::NOT_PALINDROME;
    }

    RESULT ret = RESULT::PALINDROME;
    if (s < e + 1)
    {
        ret = solve(s+1, e-1);
    }

    dp[s][e] = ret;
    return ret;
}

int main()
{
    int N; std::cin >> N;
    for (int i=0; i<N; ++i)
        std::cin >> arr[i];

    for (int i=0; i<N; ++i)
        dp[i][i] = RESULT::PALINDROME;

    int M; std::cin >> M;
    while (M--)
    {
        int S, E;
        std::cin >> S >> E;
        std::cout << (solve(S-1, E-1) == RESULT::PALINDROME) << '\n';
    }
}