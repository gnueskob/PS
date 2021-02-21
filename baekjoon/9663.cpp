// https://www.acmicpc.net/problem/9663
// #include <iostream>

// int N, ans;
// bool board[15][15];

// bool InBoundary(int x, int y)
// {
//     return (0 <= x && x < N && 0 <= y && y < N);
// }

// bool PossiblePlace(int x, int y)
// {
//     // 이전 row 까지만 세팅했으므로 현재 row 부터는 볼 필요가 없음
//     // 현재 row(x) 위로만 비교
//     for (int i=0; i<x; ++i)
//     {
//         // 현재 row 기준 위쪽 검사
//         if (board[i][y] == true)
//             return false;
//     }

//     for (int i=1; i<=x; ++i)
//     {
//         // left-top 방향 체크
//         int xx = x-i, yy = y-i;
//         if (InBoundary(xx, yy) == false)    // 범위밖이면 그 이상 대각선 판별 스킵
//             break;

//         if (board[xx][yy] == true)
//             return false;
//     }

//     for (int i=1; i<=x; ++i)
//     {
//         // left-bottom 방향 체크
//         int xx = x-i, yy = y+i;
//         if (InBoundary(xx, yy) == false)    // 범위밖이면 그 이상 대각선 판별 스킵
//             break;

//         if (board[xx][yy] == true)
//             return false;
//     }

//     return true;
// }

// void solve(int row, int cnt)
// {
//     // 현재 row 기준 col 별로 가능한 위치라면 퀸 세팅하고 다음 row로 넘기기
//     for (int col=0; col<N; ++col)
//     {
//         // i 번째 col 에 배치가 가능하다면
//         if (PossiblePlace(row, col))
//         {
//             board[row][col] = true;   // 퀸 배치
//             ++cnt;
//             if (cnt >= N)   // 개수만큼 배치가 완료되었다면
//             {
//                 ++ans;

//                 // for (int i=0; i<N; ++i)
//                 // {
//                 //     for (int j=0; j<N; ++j)
//                 //     {
//                 //         std::cout << board[i][j] << ' ';
//                 //     }
//                 //     std::cout << '\n';
//                 // }
//                 // std::cout << '\n';4
//                 board[row][col] = false;
//                 return;
//             }

//             // 배치가 아직 덜됐다면 다음 col 에서 찾기
//             solve(row + 1, cnt);
//             board[row][col] = false;   // 해당 경우 확인 후 퀸 제거
//             --cnt;
//         }
//     }
// }

// int main()
// {
//     std::cin >> N;
//     solve(0, 0);
//     std::cout << ans;
// }

#include <iostream>
#include <cmath>
int col[15], N, ans;

bool check(int col_idx)
{
    for (int i=0; i<col_idx; ++i)
    {
        // 같은 행이 있는지 체크
        if (col[i] == col[col_idx])
            return false;

        // 대각선에 있는지 체크
        if (std::abs(col[i] - col[col_idx]) == (col_idx - i))
            return false;
    }

    return true;
}

void solve(int col_idx)
{
    // 확인하려는 col 번호가 N까지 커진다면 배치 완료된 것.
    if (col_idx == N)
    {
        ++ans;
        return;
    }

    // row 별로 체스말 체크
    for (int row=0; row<N; ++row)
    {
        // col 배열에 해당 col 몇번째 row 에 체스말이 존재하는지 row 번호 저장
        col[col_idx] = row;
        if (check(col_idx))
            solve(col_idx + 1);
    }
}

int main()
{
    std::cin >> N;
    solve(0);
    std::cout << ans;
}