// https://www.acmicpc.net/problem/2004
#include <iostream>

// 숫자 뒤에 0이 붙으려면, 2*5 혹은 10을 곱해야함
int cnt[2];

enum NUM
{
    TWO = 0,
    FIVE = 1,
};

void GetTwoFiveCountFromFactorial(int num, bool plus = true)
{
    int factor = -1;
    if (plus)
        factor = 1;

    // num <= 2'000'000'000
    for (long long i=2; i<=num; i*=2)
        cnt[NUM::TWO] += factor * num/i;

    for (long long i=5; i<=num; i*=5)
        cnt[NUM::FIVE] += factor * num/i;
}

int main()
{
    // nCr
    int n, r;
    std::cin >> n >> r;

    GetTwoFiveCountFromFactorial(n);
    GetTwoFiveCountFromFactorial(n-r, false);
    GetTwoFiveCountFromFactorial(r, false);

    long long ans = 0;

    std::cout << std::min(cnt[NUM::TWO], cnt[NUM::FIVE]);
}