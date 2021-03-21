// https://www.acmicpc.net/problem/2630
#include "_fileRead.hpp"
GNUES::FileRead f("2630.txt");

#include <iostream>

bool paper[128][128];
int blue, white;
void divide(const int size, int r, int c)
{
    // (r, c) 부터 size 크기만한 종이가 같은 색인지 검사
    bool color = paper[r][c];
    bool diff = false;
    for (int i=r; i<r+size; ++i)
    {
        for (int j=c; j<c+size; ++j)
        {
            if (color != paper[i][j])
            {
                // 다른 색이 있다면 즉각 종료 4분할해서 재귀
                diff = true;
                break;
            }
        }
        if (diff)
            break;
    }

    if (diff)
    {
        // 4분할 재실행
        divide(size/2, r, c);
        divide(size/2, r+size/2, c);
        divide(size/2, r, c+size/2);
        divide(size/2, r+size/2, c+size/2);
        return;
    }

    if (color)
        ++blue;
    else
        ++white;
}

int main()
{
    int N;
    std::cin >> N;

    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            bool num;
            std::cin >> num;
            paper[i][j] = num;
        }
    }

    divide(N, 0, 0);
    std::cout << white << '\n' << blue;
}