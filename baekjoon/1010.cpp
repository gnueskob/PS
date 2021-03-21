// https://www.acmicpc.net/problem/1010
#include "_fileRead.hpp"
GNUES::FileRead f("1010.txt");

#include <iostream>
unsigned long long combination(int n, int r)
{
    // n! / ((n-r)! * r!)
    // = n*(n-1)...(n-r+1) / r*(r-1)...2*1
    // 분자 1부터 나눠가는데 알맞게 나눠떨어짐

    unsigned long long ans = 1;
    int k = 1, n_minus_r = std::max(n-r, r);
    for (int i=n; i>n_minus_r; --i)
        ans = ans * i / k++;

    return ans;
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int N, M;
        std::cin >> N >> M;
        std::cout << combination(M, N) << '\n';
    }
}