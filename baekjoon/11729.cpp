// https://www.acmicpc.net/problem/11729
#include <iostream>
void solve(int from, int to, int size);
int main()
{
    ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << (1 << n) - 1 << '\n';
    solve(1, 3, n);
}


void solve(int from, int to, int size)
{
    if (size <= 0 || from == to)
        return;

    int remain = 1 ^ 2 ^ 3 ^ from ^ to;     // 남는 위치

    solve(from, remain, size - 1);              // 최하단 원판 위의 것들을 남는 곳으로 이동
    std::cout << from << ' ' << to << '\n';     // 최하단 원판 목적지로 이동
    solve(remain, to, size - 1);                // 이동시켜놨던 위의 판 원래 목적지로 이동
}