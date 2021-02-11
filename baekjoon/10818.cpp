// 최소, 최대
// https://www.acmicpc.net/problem/10818

#include <iostream>
#include <limits.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cin.tie(NULL);

    int cnt, max = INT_MIN, min = INT_MAX, tmp;
    std::cin >> cnt;
    for (int i=0; i<cnt; ++i)
    {
        std::cin >> tmp;
        if (max < tmp) max = tmp;
        if (min > tmp) min = tmp;
    }

    std::cout << min << " " << max;

    return 0;
}
