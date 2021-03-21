// https://www.acmicpc.net/problem/7579
#include "_fileRead.hpp"
GNUES::FileRead f("7579.txt");

#include <iostream>
#include <vector>
int mem[100];
int cost[100];
int dp[10001];  // 해당 비용에 따른 확보 최대 메모리

int main()
{
    int N, M;
    std::cin >> N >> M;
    for (int i=0; i<N; ++i)
        std::cin >> mem[i];

    int total_cost = 0;
    for (int i=0; i<N; ++i)
    {
        std::cin >> cost[i];
        total_cost += cost[i];
    }

    for (int i=0; i<N; ++i)
    {
        // i 번째 앱 측정 기준
        // cost 오름차순으로 체크시 i 번째 앱의 비활성화 경우가 중복으로 들어갈 수 있음
        for (int j=total_cost; j>=cost[i]; --j)
        {
            dp[j] = std::max(dp[j], dp[j-cost[i]] + mem[i]);
        }
    }

    for (int i=0; i<=total_cost; ++i)
    {
        if (dp[i] >= M)
        {
            std::cout << i;
            break;
        }
    }
}