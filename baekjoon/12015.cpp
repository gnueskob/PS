// https://www.acmicpc.net/problem/12015
#include "_fileRead.hpp"
GNUES::FileRead f("12015.txt");

#include <iostream>
#include <vector>
int main()
{
    int N; std::cin >> N;
    std::vector<int> arr;
    arr.reserve(N);

    while (N--)
    {
        int num; std::cin >> num;
        auto find = std::lower_bound(arr.begin(), arr.end(), num);
        if (find == arr.end())
            arr.emplace_back(num);
        else
            *find = num;
    }

    std::cout << arr.size();
}