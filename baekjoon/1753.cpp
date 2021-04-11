// https://www.acmicpc.net/problem/1753
// #다익스트라
#include "_fileRead.hpp"
GNUES::FileRead f("1753.txt");

#include <iostream>
#include <vector>
#include <queue>
int main()
{
    int V, E, start;
    std::cin >> V >> E >> start;

    std::vector<std::vector<std::pair<int, int>>> graph(V+1);
    std::vector<int> dist(V+1, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    while (E--)
    {
        int s, e, w;
        std::cin >> s >> e >> w;
        graph[s].emplace_back(e, w);
    }

    dist[start] = 0;
    pq.push({0, start});

    while (pq.empty() == false)
    {
        const auto [prev_dist, next_idx] = pq.top();
        pq.pop();

        // 노드의 모든 인접 간선 기준으로 적재하기 때문에 중복해서 적재될 수도 있음
        if (prev_dist > dist[next_idx])
            continue;

        for (const auto& [adjacent, weight] : graph[next_idx])
        {
            if (dist[adjacent] > dist[next_idx] + weight)
            {
                dist[adjacent] = dist[next_idx] + weight;
                pq.push({ dist[adjacent], adjacent });
            }
        }
    }

    for (int i=1; i<=V; ++i)
    {
        if (dist[i] >= std::numeric_limits<int>::max())
            std::cout << "INF\n";
        else
            std::cout << dist[i] << '\n';
    }
}