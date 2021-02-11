// A+B - 7
// https://www.acmicpc.net/problem/11021

#include <iostream>
int main()
{
    int cnt, a, b;
    std::cin >> cnt;
    for (int i=1; i<=cnt; ++i)
    {
        std::cin >> a >> b;
        std::cout << "Case #" << i << ": " << a+b << "\n";
    }
}