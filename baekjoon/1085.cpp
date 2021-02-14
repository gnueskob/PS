// https://www.acmicpc.net/problem/1085
#include <iostream>
#include <algorithm>
int main()
{
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;
    std::cout << std::min(std::min(y, h - y), std::min(x, w - x));
}