// https://www.acmicpc.net/problem/1520
#include "_fileRead.hpp"
GNUES::FileRead f("1520.txt");

int N, M, ans, grid[500][500];
int visit[500][500];
int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
inline bool isInGrid(int r, int c) { return 0 <= r && r < N && 0 <= c && c < M; }

int dfs(int r, int c)
{
    if (visit[r][c] != 0)
        return visit[r][c];

    int total = 0;
    for (int d=0; d<4; d++)
    {
        int nr = r + dr[d], nc = c + dc[d];
        if (isInGrid(nr, nc) == false || grid[r][c] <= grid[nr][nc])
            continue;

        // 다음 방향으로 갈때 경우의 수
        int cnt = dfs(nr, nc);
        if (cnt == -1)
            continue;

        total += cnt;
    }

    // 모든 방향으로 체크해봤을때, 이 칸에서 목표지점까지 도달할 수 없는 경우
    if (total == 0)
        total = -1;

    visit[r][c] = total;
    return total;
}

int main()
{
    std::cin >> N; std::cin >> M;
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) std::cin >> grid[i][j];
    int ans = dfs(0,0);
    std::cout << (ans == -1 ? 0 : ans);
}