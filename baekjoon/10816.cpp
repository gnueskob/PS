// https://www.acmicpc.net/problem/10816
#include "_fileRead.hpp"
GNUES::FileRead f("10816.txt");

// #include <iostream>
// #include <vector>
// int main()
// {
//     int n;
//     std::cin >> n;

//     std::vector<int> card;
//     card.reserve(n);
//     while (n--)
//     {
//         int num;
//         std::cin >> num;
//         card.emplace_back(num);
//     }

//     std::sort(card.begin(), card.end());

//     int m;
//     std::cin >> m;
//     while (m--)
//     {
//         int num;
//         std::cin >> num;
//         auto lower = std::lower_bound(card.begin(), card.end(), num);
//         auto upper = std::upper_bound(card.begin(), card.end(), num);

//         std::cout << std::distance(lower, upper) << '\n';
//     }
// }

#include <iostream>
constexpr int SIZE = 10'000'000;
int card[SIZE * 2 + 1];
int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        int num;
        std::cin >> num;
        ++card[num + SIZE];
    }

    int m;
    std::cin >> m;
    while (m--)
    {
        int num;
        std::cin >> num;
        std::cout << card[num + SIZE] << '\n';
    }
}