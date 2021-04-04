// https://www.acmicpc.net/problem/2309
#include<iostream>
#include<algorithm>

int tall[9];
bool isDwarf[9];

bool solve(int idx, int sum, int cnt)
{
    // idx 난쟁이 미포함
    for (int i = idx + 1; i < 9; i++)
        if (solve(i, sum, cnt))
            return true;

    // 포함
    ++cnt;
    isDwarf[idx] = true;
    sum += tall[idx];
    if (cnt >= 7)
    {
        if (cnt == 7 && sum == 100)
            return true;

        isDwarf[idx] = false;
        return false;
    }

    for (int i = idx + 1; i < 9; i++)
        if (solve(i, sum, cnt))
            return true;

    isDwarf[idx] = false;
    return false;
}

int main()
{
    for (int i=0; i<9; ++i)
        std::cin >> tall[i];

    std::sort(tall, tall + 9);

    solve(0, 0, 0);

    for (int i=0; i<9; ++i)
        if (isDwarf[i])
            std::cout << tall[i] << '\n';
}