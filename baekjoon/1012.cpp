// https://www.acmicpc.net/problem/1012
#include "_fileRead.hpp"
GNUES::FileRead f("1012.txt");

#include <iostream>

int M, N;
int farm[50][50];
int pos[2500][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool dfs(int x, int y)
{
    // out of boundary
    if (x < 0 || x >= M || y < 0 || y >= N)
        return false;

    // already check or no cabbage cell
    if (farm[x][y] != 1)
        return false;

    farm[x][y] = -1;

    for (int i=0; i<4; ++i)
        dfs(x + dx[i], y + dy[i]);

    return true;
}

int main()
{
    int T; std::cin >> T;
    while (T--)
    {
        int cabbage;
        std::cin >> M >> N >> cabbage;
        std::fill(farm[0], farm[0] + 2500, 0);
        for (int i=0; i<cabbage; ++i)
        {
            int x, y; std::cin >> x >> y;
            farm[x][y] = 1;
            pos[i][0] = x;
            pos[i][1] = y;
        }

        int ans = 0;
        for (int i=0; i<cabbage; ++i)
            if (dfs(pos[i][0], pos[i][1]))
                ++ans;

        std::cout << ans << '\n';
    }
}