// https://www.acmicpc.net/problem/13305
#include "_fileRead.hpp"
GNUES::FileRead f("13305.txt");

#include <iostream>
#include <climits>
int main()
{
    int N;
    std::cin >> N;
    int length[100'000];

    // 도로 길이
    for (int i=0; i<N-1; ++i)
        std::cin >> length[i];

    int min_price;
    std::cin >> min_price;

    long long ans = 0;
    for (int i=1; i<N; ++i)
    {
        // 현재 도시까지 왔을때, 최소 기름값 기준으로 더해줌
        // for type promotion
        ans += (long long)length[i-1] * min_price;

        // 현재 도시의 기름값이 더 싸면, 최소 기름값 갱신
        // 다음 여행시 이 도시 기름값 기준으로 추가됨
        int price;
        std::cin >> price;
        if (price < min_price)
            min_price = price;
    }

    std::cout << ans;
}