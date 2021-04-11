// https://www.acmicpc.net/problem/10217
// #다익스트라, #다이나믹프로그래밍
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("10217.txt");
#endif

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>

int inf = std::numeric_limits<int>::max();

using next_vertex = std::tuple<int, int, int>;
std::vector<next_vertex> graph[101];

// dist[v][m] = t; 시작 노드로부터 v 까지 m 비용드는 경로의 최단 거리
int dist[101][10001];

int main()
{
    int T = GNUES::readInt();
    while (T--)
    {
        auto [N, M, K] = GNUES::readInts<int, int, int>();

        for (int i=1; i<=N; ++i)
        {
            graph[i].clear();
            for (int j=0; j<=M; ++j)
                dist[i][j] = inf;
        }

        for (int i=0; i<K; ++i)
        {
            auto [u, v, c, d] = GNUES::readInts<int, int, int, int>();
            graph[u].emplace_back(v, c, d);
        }

        // priority queue 이용하니 더 느림
        std::queue<next_vertex> next;

        // 시작 노드 세팅
        next.emplace(1, 0, 0);
        while (next.empty() == false)
        {
            // 간선 중 가장 가중치 낮은 노드 기준 수행
            auto [cur_v, cur_cost, cur_dist] = next.front();
            next.pop();

            // 이미 해당 노드, 비용 기준 더 최단 거리가 존재한다면 스킵
            if (dist[cur_v][cur_cost] < cur_dist)
                continue;

            for (const auto& [next_v, next_c, next_d] : graph[cur_v])
            {
                // cur_v 에서 next_v 까지 걸리는 비용, 시간
                int total_cost = cur_cost + next_c;
                int total_dist = cur_dist + next_d;

                // 드는 비용이 허용 한도 초과하면 스킵
                if (total_cost > M)
                    continue;

                // 시간이 더 적게 걸린다면, 갱신
                if (dist[next_v][total_cost] > total_dist)
                {
                    // 현재 드는 비용이상의 경우들 모두 최단거리 갱신
                    // 현재 비용 미만은 비용이 부족한 것이므로 최단거리 갱신하지 않음
                    for (int i=total_cost; i<=M; ++i)
                    {
                        // 특정 비용 부터 최단거리가 더 짧다면
                        // 해당 비용으로 더 빠르게 가는 경로인 것
                        if (dist[next_v][i] > total_dist)
                            dist[next_v][i] = total_dist;
                        else
                            break;
                    }

                    next.emplace(next_v, total_cost, total_dist);
                }
            }
        }

        int ans = inf;
        for (int i=0; i<=M; ++i)
            ans = std::min(ans, dist[N][i]);

        if (ans < inf)
            GNUES::writeInt(ans, '\n');
        else
            GNUES::writeWord("Poor KCM\n");
    }
}