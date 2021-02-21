// https://www.acmicpc.net/problem/14888
#include "_fileRead.hpp"
GNUES::FileRead f("14888.txt");

#include <iostream>
#include <climits>

enum Operator
{
    PLUS = 0,
    MINUS = 1,
    MUL = 2,
    DIVIDE = 3,
    MAX = 4
};

int num[11], N, op[Operator::MAX];
int min = INT_MAX, max = INT_MIN;

void solve(int idx, int res)
{
    // 종료
    if (idx + 1 >= N)
    {
        min = std::min(min, res);
        max = std::max(max, res);
        return;
    }

    int next = num[idx + 1];

    for (int i=0; i<Operator::MAX; ++i)
    {
        if (op[i] > 0)
        {
            int temp = res;
            switch (i)
            {
            case Operator::PLUS:    temp += next;    break;
            case Operator::MINUS:   temp -= next;    break;
            case Operator::MUL:     temp *= next;    break;
            case Operator::DIVIDE:  temp /= next;    break;
            default:    break;
            }

            --op[i];
            solve(idx + 1, temp);
            ++op[i];
        }
    }
}

int main()
{
    std::cin >> N;
    for (int i=0; i<N; ++i)
        std::cin >> num[i];

    std::cin >> op[PLUS] >> op[MINUS] >> op[MUL] >> op[DIVIDE];

    solve(0, num[0]);

    std::cout << max << '\n' << min;
}