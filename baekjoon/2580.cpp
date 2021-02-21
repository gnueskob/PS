// https://www.acmicpc.net/problem/2580
#include <iostream>
#include "_fileRead.hpp"
GNUES::FileRead f("2580.txt");

void solve(int x, int y);
void printSudoku();

int sudoku[9][9];
int main()
{
    for (int i=0; i<9; ++i)
        for (int j=0; j<9; ++j)
            std::cin >> sudoku[i][j];

    solve(0,0);
    printSudoku();
}

std::pair<int, int> getBoxLeftTop(int x, int y)
{
    // 3x3 상자 구석 좌표 0 ~ 2 : 0, 3 ~ 5 : 3, 6 ~ 8 : 6
    return { (x / 3) * 3, (y / 3) * 3 };
}

bool promising(int x, int y, int num)
{
    // 해당 셀에 num 이 들어갈 수 있는지 판단
    if (sudoku[x][y] != 0)
        return false;

    // 행, 열 체크
    for (int i=0; i<9; ++i)
    {
        if (sudoku[x][i] == num)
            return false;

        if (sudoku[i][y] == num)
            return false;
    }

    // 해당 3x3 Box 체크
    auto [box_x, box_y] = getBoxLeftTop(x, y);
    for (int i=0; i<3; ++i)
    {
        for (int j=0; j<3; ++j)
        {
            if (sudoku[box_x + i][box_y + j] == num)
                return false;
        }
    }

    return true;
}

std::pair<int, int> getNextCell(int x, int y)
{
    int next_x = x, next_y = y + 1;
    if (next_y > 8)
    {
        next_x += 1;
        next_y = 0;
    }
    return { next_x, next_y };
}

void printSudoku()
{
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<8; ++j)
            std::cout << sudoku[i][j] << ' ';
        std::cout << sudoku[i][8] << '\n';
    }
}

bool finished = false;
void solve(int x, int y)
{
    // 종료
    if (x > 8)
    {
        finished = true;
        return;
    }

    // 이미 차있는 cell 인 경우
    if (sudoku[x][y] != 0)
    {
        auto [next_x, next_y] = getNextCell(x, y);
        solve(next_x, next_y);
        return;
    }

    // 채워야하는 cell 인 경우
    for (int num=1; num<=9; ++num)
    {
        if (promising(x, y, num))
        {
            sudoku[x][y] = num;
            auto [next_x, next_y] = getNextCell(x, y);
            solve(next_x, next_y);

            if (finished)
                return;

            sudoku[x][y] = 0;
        }
    }
}