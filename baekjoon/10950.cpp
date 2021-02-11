// A+B - 3
// https://www.acmicpc.net/problem/10950

#include <iostream>
int main()
{
    int cnt, a, b;
    std::cin >> cnt;
    for (int i=0; i<cnt; ++i)
    {
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }
}