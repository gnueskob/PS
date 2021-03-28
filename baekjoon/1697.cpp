// https://www.acmicpc.net/problem/1697
#include "_fileRead.hpp"
GNUES::FileRead f("1697.txt");

#include <iostream>
#include <queue>
int main()
{
    int N, K;
    std::cin >> N >> K;
    bool visit[100'001] = {false,};

    std::queue<std::pair<int, int>> next;
    next.emplace(N, 0);
    visit[N] = true;

    int next_pos[3];
    while (next.empty() == false)
    {
        auto [pos, depth] = next.front();
        next.pop();

        if (pos == K)
        {
            std::cout << depth;
            break;
        }

        ++depth;
        next_pos[0] = pos + 1;
        next_pos[1] = pos - 1;
        next_pos[2] = pos * 2;
        for (int p : next_pos)
        {
            if (p < 0 || p > 100'000 || visit[p])
                continue;

            visit[p] = true;
            next.push({ p, depth });
        }
    }
}