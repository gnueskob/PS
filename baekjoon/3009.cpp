// https://www.acmicpc.net/problem/3009
#include <iostream>
int main()
{
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int x = x1 ^ x2 ^ x3;
    int y = y1 ^ y2 ^ y3;
    std::cout << x << " " << y;
}