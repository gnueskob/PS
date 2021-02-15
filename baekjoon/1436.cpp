// https://www.acmicpc.net/problem/1436
#include <iostream>
int main()
{
    int N, cnt = 0;
    std::cin >> N;
    int i = 665;    // 666 부터 검사
    do
    {
        ++i;

        // 연속된 666포함하는 숫자인지 검사
        int current = i;
        int six_cnt = 0;
        do
        {
            if (current % 10 == 6)
            {
                ++six_cnt;
                if (six_cnt >= 3)
                {
                    ++cnt;
                    break;
                }
            }
            else
                six_cnt = 0;

            current /= 10;

        } while (current > 0);

    } while (cnt < N);

    std::cout << i;
}