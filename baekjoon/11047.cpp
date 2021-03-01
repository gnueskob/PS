// https://www.acmicpc.net/problem/11047
#include "_fileRead.hpp"
GNUES::FileRead f("11047.txt");

#include <iostream>
int main()
{
    int coin[10], N, K;
    std::cin >> N >> K;
    int idx = N;
    for (int i = 0; i<N; ++i)
    {
        std::cin >> coin[i];
        if (coin[i] > K)
        {
            idx = i;
            break;
        }
    }

    // 동전 숫자가 배수이므로 큰것부터 빼나감
    int remain = K, ans = 0;
    for (int i=idx-1; i>=0; --i)
    {
        ans += remain / coin[i];
        remain %= coin[i];
        if (remain == 0)
            break;
    }
    std::cout << ans;
}