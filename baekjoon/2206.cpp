// https://www.acmicpc.net/problem/2206
#include "_fileRead.hpp"
GNUES::FileRead f("2206.txt");

#include <iostream>
#include <queue>
#include <tuple>
#include <string>

bool grid[1001][1001];
bool visit[1001][1001];
bool visitBrokenWall[1001][1001];

int main()
{
    int N, M;
    std::cin >> N >> M;
    for (int i=0; i<N; ++i)
    {
        std::string str; std::cin >> str;
        for (int j=0; j<M; ++j)
        {
            grid[i+1][j+1] = (str.at(j) == '1');
        }
    }

    std::queue<std::tuple<int, int, bool, int>> next;
    next.emplace(1, 1, true, 1);
    visit[1][1] = true;

    int ans = -1;
    std::pair<int, int> next_pos[4];
    while (next.empty() == false)
    {
        auto [x, y, can_destroy_wall, depth] = next.front();
        next.pop();

        if (x == N && y == M)
        {
            ans = depth;
            break;
        }

        ++depth;
        next_pos[0] = {x+1, y};
        next_pos[1] = {x-1, y};
        next_pos[2] = {x, y+1};
        next_pos[3] = {x, y-1};
        for (const auto [next_x, next_y] : next_pos)
        {
            // 범위 밖이면 스킵
            if (next_x < 1 || next_x > N || next_y < 1 || next_y > M)
                continue;

            // 방문 이력은 벽뚫 전후로 다르게 체크해야함
            if (can_destroy_wall == false)
            {
                // 벽뚫 기회 썻다면 벽뚫 전 방문한 곳도 그 이상 체크해볼 필요 없음
                if (visitBrokenWall[next_x][next_y] || visit[next_x][next_y])
                    continue;
            }
            else if (visit[next_x][next_y])
                continue;

            // 다음 칸이 벽이고, 벽뚫 기회가 없다면 스킵
            bool next_destory_wall = can_destroy_wall;
            if (grid[next_x][next_y])
            {
                if (next_destory_wall == false)
                    continue;

                next_destory_wall = false;
            }

            if (next_destory_wall)
                visit[next_x][next_y] = true;
            else
                visitBrokenWall[next_x][next_y] = true;
            next.push({ next_x, next_y, next_destory_wall, depth });
        }
    }

    std::cout << ans;
}