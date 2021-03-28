// https://www.acmicpc.net/problem/1707
#include "_fileRead.hpp"
GNUES::FileRead f("1707.txt");

#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;
bool check_valid_cycle(int vertex, int depth, const Graph& graph, std::vector<int>& visit)
{
    if (visit[vertex] > 0)
        return ((depth - visit[vertex]) % 2 == 0);

    visit[vertex] = depth;
    ++depth;
    for (const int adjacent : graph[vertex])
    {
        if (check_valid_cycle(adjacent, depth, graph, visit) == false)
            return false;
    }

    return true;
}

int main()
{
    int T; std::cin >> T;
    while (T--)
    {
        int V, E; std::cin >> V >> E;
        Graph graph = Graph(V+1);
        std::vector<int> visit(V+1, 0);

        while (E--)
        {
            int s, e; std::cin >> s >> e;
            if (s == e) continue;
            graph[s].emplace_back(e);
            graph[e].emplace_back(s);
        }

        bool ans = true;
        for (int i=1; i<=V; ++i)
        {
            if (visit[i] > 0)
                continue;

            if (check_valid_cycle(i, 1, graph, visit) == false)
            {
                ans = false;
                break;
            }
        }

        std::cout << (ans ? "YES\n" : "NO\n");
    }
}
