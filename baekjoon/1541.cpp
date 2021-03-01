// https://www.acmicpc.net/problem/1541
#include "_fileRead.hpp"
GNUES::FileRead f("1541.txt");

#include <iostream>
int main()
{
    int plus = 0, minus = 0, num;
    while (std::cin >> num)
    {
        if (num < 0)
        {
            minus += num;
            continue;
        }

        if (minus < 0)
        {
            minus -= std::abs(num);
            continue;
        }

        plus += num;
    }

    std::cout << plus + minus;
}