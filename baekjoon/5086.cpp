// https://www.acmicpc.net/problem/5086
#include "_fileRead.hpp"
GNUES::FileRead f("5086.txt");

#include <iostream>
int main()
{
    int a, b;
    while (true)
    {
        std::cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        // 양쪽 어디든 modulo 연산이 되면 factor or muliple
        if (b % a == 0 || a % b == 0)
        {
            if (a > b)
                std::cout << "multiple\n";
            else
                std::cout << "factor\n";
            continue;
        }

        std::cout << "neither\n";
    }
}
