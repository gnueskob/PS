// https://www.acmicpc.net/problem/2164
/*
#include <iostream>
#include <queue>
int main()
{
    int N;
    std::cin >> N;

    std::queue<int> q;
    for (int i=1; i<=N; ++i)
        q.emplace(i);

    while (true)
    {
        if (q.size() == 1)
            break;

        q.pop();
        q.push(q.front());
        q.pop();
    }

    std::cout << q.front();
}*/

// 규칙성
#include <iostream>
int main()
{
    int N, two_pow = 1;
    std::cin >> N;

    // N이하 최대 2의 거듭제곱
    while (two_pow < N)
        two_pow *= 2;

    std::cout << 2*N - two_pow;
}

// 1 : 1 (1*2 - 1)
// 2 : 2 (2*2 - 2)
// 3 : 2 (3*2 - 4)
// 4 : 4 (4*2 - 4)
// 5 : 2 (5*2 - 8)
// 6 : 4 (6*2 - 8)
// 7 : 6 (7*2 - 8)
// 8 : 8 (8*2 - 8)
// 9 : 2 (9*2 - 8)
// N : (N*2 - N이하 최대 2의 거듭제곱)