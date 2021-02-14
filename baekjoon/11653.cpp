// https://www.acmicpc.net/problem/11653

#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for (int divisor = 2; divisor * divisor <= n; ++divisor)
    {
        int remainder = n % divisor;
        while (remainder == 0)
        {
            n /= divisor;
            std::cout << divisor << '\n';

            remainder = n % divisor;
        }
    }

    if (n > 1)
        std::cout << n;
}