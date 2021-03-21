// https://www.acmicpc.net/problem/1920
#include "_fileRead.hpp"
GNUES::FileRead f("1920.txt");

#include <iostream>
#include <vector>
int main()
{
    int n, m;
    std::cin >> n;

    std::vector<int> arr;
    arr.reserve(n);
    while (n--)
    {
        int num;
        std::cin >> num;
        arr.emplace_back(num);
    }

    std::sort(arr.begin(), arr.end());

    std::cin >> m;
    while (m--)
    {
        int num;
        std::cin >> num;
        auto find = std::lower_bound(arr.begin(), arr.end(), num);
        std::cout << (find != arr.end() && *find == num) << '\n';
    }
}