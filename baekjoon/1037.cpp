// https://www.acmicpc.net/problem/1037
#include <iostream>
#include <climits>
int main()
{
    int N, num, min = INT_MAX, max = INT_MIN;
    std::cin >> N;
    // 1, N을 제외한 N의 '진짜' 약수 중 최소, 최대 곱은 N
    // 진짜 약수가 하나여도 min, max 제곱 처리
    while (N--)
    {
        std::cin >> num;
        min = std::min(min, num);
        max = std::max(max, num);
    }

    std::cout << min * max;
}