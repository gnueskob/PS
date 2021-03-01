// https://www.acmicpc.net/problem/12865
#include "_fileRead.hpp"
GNUES::FileRead f("12865.txt");

#include <iostream>
#include <vector>
int main()
{
    int N, K;
    std::cin >> N >> K;

    // dp[i] : 배낭 무게 한도가 i 일때의 가중치 최댓값
    int dp[100001] = {0,};

    for (int i=0; i<N; ++i)
    {
        int w, v;
        std::cin >> w >> v;

        // 현재 물품이 들어갈 경우 무게 이상의 배낭 무게 한도에 대해서 최대값 갱신
        // 배낭의 한도가 w 이상일 때부터 물품을 넣어볼 수 있기 때문
        // 단, 이전까지의 물품으로 갱신한 가중치 최댓값에서
        // 무게를 뺀 값의 인덱스를 기준으로 비교하므로 무게 내림차순으로 비교
        // 오름차순으로 비교할 경우 이미 물품을 넣어 갱신한 가중치로 비교할 수 있음
        for (int j=K; j>=w; --j)
        {
            // 해당 배낭의 최대 가중치와 이 물품을 넣을때랑 비교
            dp[j] = std::max(dp[j], dp[j-w] + v);
        }
    }

    std::cout << dp[K];
}