// https://www.acmicpc.net/problem/11404
// #플로이드와셜
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("11404.txt");
#endif

#include <iostream>
#include <vector>
int main()
{
    auto [n, m] = GNUES::readInts<int, int>();

    int inf = std::numeric_limits<int>::max();
    std::vector<std::vector<long long>> graph(n+1, std::vector<long long>(n+1, inf));
    while (m--)
    {
        auto [a, b, c] = GNUES::readInts<int, int, long long>();
        graph[a][b] = std::min(graph[a][b], c);
    }

    for (int v=1; v<=n; ++v) graph[v][v] = 0;

    // 각 노드를 거쳐가는 모든 경우의 최단거리 갱신
    for (int v=1; v<=n; ++v)
    {
        for (int s=1; s<=n; ++s)
        {
            for (int e=1; e<=n; ++e)
            {
                graph[s][e] = std::min(graph[s][e], graph[s][v] + graph[v][e]);
            }
        }
    }

    for (int s=1; s<=n; ++s)
    {
        for (int e=1; e<=n; ++e)
        {
            GNUES::writeInt((graph[s][e] >= inf ? 0 : graph[s][e]), ' ');
        }
        GNUES::writeChar('\n');
    }
}