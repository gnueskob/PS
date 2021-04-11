// https://www.acmicpc.net/problem/1956
// #플로이드와셜
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("1956.txt");
#endif

#include <iostream>
#include <vector>
int main()
{
    auto [V, E] = GNUES::readInts<int, int>();

    int inf = std::numeric_limits<int>::max();
    std::vector<std::vector<long long>> graph(V+1, std::vector<long long>(V+1, inf));
    while (E--)
    {
        auto [a, b, c] = GNUES::readInts<int, int, long long>();
        graph[a][b] = std::min(graph[a][b], c);
    }

    // 플로이드와셜을 통해 모든 노드간 최단거리 갱신
    // graph[v][v] 자기 자신으로 되돌아 올 수 있다면 사이클
    for (int v=1; v<=V; ++v)
    {
        for (int s=1; s<=V; ++s)
        {
            for (int e=1; e<=V; ++e)
            {
                graph[s][e] = std::min(graph[s][e], graph[s][v] + graph[v][e]);
            }
        }
    }

    long long ans = inf;
    for (int v=1; v<=V; ++v)
        ans = std::min(ans, graph[v][v]);

    GNUES::writeInt((ans >= inf ? -1 : ans));
}