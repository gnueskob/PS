// https://www.acmicpc.net/problem/4153
#include <iostream>
#include <algorithm>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cin.tie(NULL);

    int a, b, c;
    while (true)
    {
        std::cin >> a >> b >> c;
        if (a == 0)
            break;

        int max = std::max(a, std::max(b, c));
        if (2 * max * max == (a * a + b * b + c * c))
            std::cout << "right\n";
        else
            std::cout << "wrong\n";
    };
}