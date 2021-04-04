// https://www.acmicpc.net/problem/9370
#include "_fileRead.hpp"
GNUES::FileRead f("9370.txt");

#include <iostream>
#include <vector>
#include <queue>
int main()
{
    int T; std::cin >> T;
    while (T--)
    {
        int n, m, t, s, g, h;
        std::cin >> n >> m >> t >> s >> g >> h;

        std::vector<std::vector<std::pair<int, int>>> graph(n+1);
        while (m--)
        {
            int a, b, d;
            std::cin >> a >> b >> d;
            // 간선 가중치 2배, g-h 도로일 경우 홀수로 세팅.
            // 최단거리가 홀수이면 g-h 포함하는 경로
            d *= 2;
            if ((a == g && b == h) || (a == h && b == g)) --d;
            graph[a].emplace_back(b, d);
            graph[b].emplace_back(a, d);
        }

        std::vector<int> dest;
        dest.reserve(t);
        while (t--)
        {
            int dest_point;
            std::cin >> dest_point;
            dest.emplace_back(dest_point);
        }

        std::sort(dest.begin(), dest.end());

        std::vector<int> dist(n+1, std::numeric_limits<int>::max());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        dist[s] = 0;
        pq.push({0, s});

        while (pq.empty() == false)
        {
            const auto [prev_dist, next_idx] = pq.top();
            pq.pop();

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

        for (const int dest_point : dest)
        {
            if (dist[dest_point] < std::numeric_limits<int>::max() && dist[dest_point] % 2 != 0)
                std::cout << dest_point << ' ';
        }

        std::cout << '\n';
    }
}