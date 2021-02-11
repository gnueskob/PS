// A+B - 5
// https://www.acmicpc.net/problem/10952

#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int a, b;
    do
    {
        std::cin >> a >> b;
        if (a == 0)
            return 0;

        std::cout << a+b << "\n";
    } while(true);
}