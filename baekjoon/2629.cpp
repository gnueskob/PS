// https://www.acmicpc.net/problem/2629
#include "_fileRead.hpp"
GNUES::FileRead f("2629.txt");

#include <iostream>

int N;
int weight[30];  // 추 무게, 사용 여부
bool dp[31][30*500 + 1]; // n번째 무게까지만 사용했을때 만들 수 있는 무게 여부


void solve(int idx, int w)
{
    // idx 개수의 추를 이용해서 w를 만들수 있는 경우
    if (idx > N)
        return;

    if (dp[idx][w])
        return;

    dp[idx][w] = true;

    // 구슬 반대쪽에 추 사용한 경우
    solve(idx + 1, w + weight[idx]);
    // 구슬 쪽에 추 사용한 경우
    solve(idx + 1, std::abs(w - weight[idx]));
    // 추를 사용 안한경우
    solve(idx + 1, w);
}

int main()
{
    std::cin >> N;
    for (int i=0; i<N; ++i)
    {
        int w; std::cin >> w;
        weight[i] = w;
    }

    solve(0, 0);

    int beads; std::cin >> beads;
    while (beads--)
    {
        int bw; std::cin >> bw;

        bool find;
        if (bw > 30*500) find = false;
        else find = dp[N][bw];

        std::cout << (find ? "Y " : "N ");
    }
}