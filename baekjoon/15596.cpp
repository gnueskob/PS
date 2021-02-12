// 정수 N개의 합
// https://www.acmicpc.net/problem/15596
#include <vector>
long long sum(std::vector<int> &a);
{
    long long sum = 0;
    for (auto& n : a)
        sum += n;
    return sum;
}