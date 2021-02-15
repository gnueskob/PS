// https://www.acmicpc.net/problem/11651
#include <iostream>

inline int readInt() {int a;scanf("%d",&a);return a;}

#include <vector>
#include <algorithm>
int main()
{
    std::vector<std::pair<int, int>> point;

    int N = readInt();
    point.reserve(N);
    while (N--)
    {
        int x = readInt();
        int y = readInt();
        point.emplace_back(y, x);
    }

    std::sort(point.begin(), point.end());

    for (const auto& p : point)
        std::cout << p.first << ' ' << p.second << '\n';
}