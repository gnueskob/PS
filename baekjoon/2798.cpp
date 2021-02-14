// https://www.acmicpc.net/problem/2798
#include <iostream>
#include <vector>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cin.tie(NULL);

    std::vector<int> card;
    int cnt, m, num;
    std::cin >> cnt >> m;
    card.reserve(cnt);
    while (cnt--)
    {
        std::cin >> num;
        card.emplace_back(num);
    }

    int sum = 0;
    auto begin = card.cbegin();
    auto end = card.cend();

    auto e1 = std::prev(end, 2);
    for (auto b1 = begin; b1 != e1; ++b1)
    {
        auto e2 = std::prev(end, 1);
        for (auto b2 = std::next(b1, 1); b2 != e2; ++b2)
        {
            for (auto b3 = std::next(b2, 1); b3 != end; ++b3)
            {
                int tmp = *b1 + *b2 + *b3;
                if (m == tmp)
                {
                    std::cout << tmp;
                    return 0;
                }
                else if (m < tmp)
                    continue;

                if (sum < tmp)
                    sum = tmp;
            }
        }
    }

    std::cout << sum;
}