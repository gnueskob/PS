// A+B - 8
// https://www.acmicpc.net/problem/11022

#include <iostream>
int main()
{
    int cnt, a, b;
    std::cin >> cnt;
    for (int i=1; i<=cnt; ++i)
    {
        std::cin >> a >> b;
        std::cout << "Case #" << i << ": " << a << " + " << b << " = " << a+b << "\n";
    }
}