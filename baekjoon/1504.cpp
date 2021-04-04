// https://www.acmicpc.net/problem/1504
#include "_fileRead.hpp"
GNUES::FileRead f("1504.txt");

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
int main()
{
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<std::pair<int, int>>> graph(V+1);
    while (E--)
    {
        int s, e, w;
        std::cin >> s >> e >> w;
        graph[s].emplace_back(e, w);
        graph[e].emplace_back(s, w);
    }

    int wp1, wp2; std::cin >> wp1 >> wp2;

    auto findDist = [&graph, V](int start, int dest1, int dest2, int dest3) -> std::tuple<long long, long long, long long>
    {
        std::vector<int> dist(V+1, std::numeric_limits<int>::max());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

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

        return { dist[dest1], dist[dest2], dist[dest3] };
    };

    auto [start_to_wp1, start_to_wp2, start_to_dest] = findDist(1, wp1, wp2, V);
    auto [wp1_to_start, wp1_to_wp2, wp1_to_dest] = findDist(wp1, 1, wp2, V);
    auto [wp2_to_start, wp2_to_wp1, wp2_to_dest] = findDist(wp2, 1, wp1, V);

    long long min_dist = std::numeric_limits<long long>::max();
    min_dist = std::min(min_dist, start_to_wp1 + wp1_to_wp2 + wp2_to_dest); // start -> way point1 -> way point2 -> dest
    min_dist = std::min(min_dist, start_to_wp2 + wp2_to_wp1 + wp1_to_dest); // start -> way point2 -> way point1 -> dest

    min_dist = std::min(min_dist, start_to_wp1 + wp1_to_wp2 + wp2_to_start + start_to_dest); // start -> way point1 -> way point2 -> start -> dest
    min_dist = std::min(min_dist, start_to_wp2 + wp2_to_wp1 + wp1_to_start + start_to_dest); // start -> way point2 -> way point1 -> start -> dest

    min_dist = std::min(min_dist, start_to_wp1 + wp1_to_start + start_to_wp2 + wp2_to_dest); // start -> way point1 -> start -> way point2 -> dest
    min_dist = std::min(min_dist, start_to_wp2 + wp2_to_start + start_to_wp1 + wp1_to_dest); // start -> way point2 -> start -> way point1 -> dest

    min_dist = std::min(min_dist, start_to_wp1 + wp1_to_start + start_to_wp2 + wp2_to_start + start_to_dest); // start -> way point1 -> start -> way point2 -> start -> dest
    min_dist = std::min(min_dist, start_to_wp2 + wp2_to_start + start_to_wp1 + wp1_to_start + start_to_dest); // start -> way point2 -> start -> way point1 -> start -> dest

    if (min_dist >= std::numeric_limits<int>::max())
        min_dist = -1;

    std::cout << min_dist;
}