// https://www.acmicpc.net/problem/1018
#include <iostream>
int main()
{
    int n, m;
    bool board[50][50] = {false, }; // true:white
    std::string color_str;
    std::cin >> n >> m;
    for (int r = 0; r < n; ++r)
    {
        std::cin >> color_str;
        for (int c = 0; c < m; ++c)
        {
            if (color_str.at(c) == 'W')
                board[r][c] = true;
        }
    }

    int min = 32;
    for (int r = 0; r <= n - 8; ++r)
    {
        for (int c = 0; c <= m - 8; ++c)
        {
            // count color
            int w = 0, b = 0;
            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    bool left_top = ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1));

                    if (left_top)
                    {
                        if (board[r + i][c + j])
                            ++b;    // left top 이 black인 체스판
                        else
                            ++w;    // left top 이 white인 체스판
                    }
                    else
                    {
                        if (board[r + i][c + j] == false)
                            ++b;
                        else
                            ++w;
                    }
                }
            }

            int tmp = std::min(w, b);
            if (tmp < min)
                min = tmp;
        }
    }

    std::cout << min;
}