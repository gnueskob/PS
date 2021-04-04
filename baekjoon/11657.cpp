// https://www.acmicpc.net/problem/11657
#include "_fileRead.hpp"
GNUES::FileRead f("11657.txt");

#include <iostream>
#include <vector>
#include <queue>
int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> graph(n+1);
    while (m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    static const int INF = std::numeric_limits<int>::max();
    std::vector<long long> dist(n+1, INF);
    std::vector<int> visit_cnt(n+1, 0); // negative-cycle 판단용 방문 횟수
    std::vector<bool> inQueue(n+1, false);  // 방문 여부 체크용
    std::queue<int> next;

    auto next_visit = [&](int idx, long long cost)
    {
        if (dist[idx] <= cost)
            return true;

        dist[idx] = cost;
        if (inQueue[idx] == false)
        {
            // 같은 단계(반복 횟수)의 방문은 중복해서 일어나지 않게 하기위해
            // 실제 방문 시에만 카운팅
            // 때문에 최대 노드 개수 - 1 만큼의 방문이 일어나고
            // negative-cycle 이 있는 경우엔 노드 개수 이상의 방문이 일어남
            ++visit_cnt[idx];
            if (visit_cnt[idx] >= n)
                return false;

            inQueue[idx] = true;
            next.push(idx);
        }

        return true;
    };

    next_visit(1, 0);
    while (next.empty() == false)
    {
        auto next_idx = next.front();
        next.pop();
        inQueue[next_idx] = false;

        for (const auto& [adjacent, cost] : graph[next_idx])
        {
            if (next_visit(adjacent, dist[next_idx] + cost) == false)
            {
                std::cout << "-1";
                return 0;
            }
        }
    }

    for (int idx = 2; idx <= n; ++idx)
        std::cout << (dist[idx] >= INF ? -1 : dist[idx]) << '\n';
}
