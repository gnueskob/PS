// https://www.acmicpc.net/problem/11049
#include "_fileRead.hpp"
GNUES::FileRead f("11049.txt");

#include <iostream>
#include <vector>
#include <limits>

int ans = std::numeric_limits<int>::max();
std::vector<std::pair<int, int>> arr;
std::vector<std::vector<int>> dp;
int solve(int begin, int end)
{
    // begin 번째 행렬부터 end번째 행렬까지의 곱셈 최소 수

    // 곱할 수 있는 수가 없음..
    if (begin >= end)
        return 0;

    if (dp[begin][end] != 0)
        return dp[begin][end];

    const auto& [n, m] = arr[begin];
    const auto& [l, k] = arr[end];

    // 인접 두 행렬이라면 종료
    if (end - begin == 1)
    {
        dp[begin][end] = n * m * k;
        return dp[begin][end];
    }

    // i 기준 반으로 나눠 곱했을때 최소값 찾기
    int min = std::numeric_limits<int>::max();
    for (int i=begin; i<end; ++i)
    {
        int left = solve(begin, i);
        int right = solve(i+1, end);
        const auto& [r, c] = arr[i];
        min = std::min(min, left + right + n * c * k);
    }

    dp[begin][end] = min;
    return min;
}

int main()
{
    int n; std::cin >> n;
    arr.reserve(n);
    dp.assign(n, std::vector<int>(n, 0));
    while (n--)
    {
        int r, c; std::cin >> r >> c;
        arr.emplace_back(r, c);
    }

    std::cout << solve(0, arr.size()-1);
}