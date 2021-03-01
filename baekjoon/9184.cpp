// https://www.acmicpc.net/problem/9184
#include "_fileRead.hpp"
GNUES::FileRead f("9184.txt");

#include <iostream>
int dp[21][21][21];
int solve(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);

    if (dp[a][b][c] != 0)
        return dp[a][b][c];

    if (a < b && b < c)
    {
        int res = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
        dp[a][b][c] = res;
        return res;
    }

    int res = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
    dp[a][b][c] = res;
    return res;
}

int main()
{
    int a, b, c;
    while (true)
    {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << '\n';
    }
}

/*
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a, b, c;
    for (int i=0; i<=20; ++i)
        for (int j=0; j<=20; ++j)
            dp[0][i][j] = dp[i][0][j] = dp[i][j][0] = 1;

    for (int i=1; i<=20; ++i)
        for (int j=1; j<=20; ++j)
            for (int k=1; k<=20; ++k)
                if (i < j && j < k)
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];

    while (true)
    {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        int res = 0;
        if (a <= 0 || b <= 0 || c <= 0)
            res = 1;
        else if (a > 20 || b > 20 || c > 20)
            res = dp[20][20][20];
        else
            res = dp[a][b][c];

        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << res << '\n';
    }
}*/