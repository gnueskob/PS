// https://www.acmicpc.net/problem/7562
#include "_fileRead.hpp"
GNUES::FileRead f("7562.txt");

#include <iostream>
#include <queue>
#include <tuple>
int main()
{
    int T; std::cin >> T;
    while (T--)
    {
        int size; std::cin >> size;
        int pos_x, pos_y; std::cin >> pos_x >> pos_y;
        int move_x, move_y; std::cin >> move_x >> move_y;

        bool visit[300][300] = {false,};
        std::queue<std::tuple<int, int, int>> next;
        next.push({ pos_x, pos_y, 0 });
        visit[pos_x][pos_y] = true;

        int ans = 0;
        while (next.empty() == false)
        {
            auto [x, y, depth] = next.front();
            next.pop();

            if (x == move_x && y == move_y)
            {
                ans = depth;
                break;
            }

            ++depth;
            std::pair<int, int> next_pos[8];
            next_pos[0] = {x - 2, y + 1};
            next_pos[1] = {x - 2, y - 1};
            next_pos[2] = {x + 2, y + 1};
            next_pos[3] = {x + 2, y - 1};
            next_pos[4] = {x + 1, y - 2};
            next_pos[5] = {x - 1, y - 2};
            next_pos[6] = {x + 1, y + 2};
            next_pos[7] = {x - 1, y + 2};
            for (const auto& [next_x, next_y] : next_pos)
            {
                if (next_x < 0 || next_x >= size || next_y < 0 || next_y >= size || visit[next_x][next_y])
                    continue;

                visit[next_x][next_y] = true;
                next.push({ next_x, next_y, depth });
            }
        }

        std::cout << ans << '\n';
    }
}