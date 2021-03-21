// https://www.acmicpc.net/problem/1655
#include "_fileRead.hpp"
GNUES::FileRead f("1655.txt");

#include <iostream>
#include <queue>
int main()
{
    int n; std::cin >> n;

    // lower_pq : 중간값 미만 수가 저장되는 큐 (top : 가장 큰 수)
    // uppwer_pq : 중간값 이상 수가 저장되는 큐 (top : 가장 작은 수)
    std::priority_queue<int, std::vector<int>, std::less<int>> lower_pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper_pq;

    lower_pq.emplace(std::numeric_limits<int>::min());
    upper_pq.emplace(std::numeric_limits<int>::max());

    while (n--)
    {
        int num; std::cin >> num;

        // 받은 수를 크기에 따라 알맞은 pq에 적재
        if (num <= upper_pq.top())
            lower_pq.emplace(num);
        else
            upper_pq.emplace(num);

        int size_diff = (int)upper_pq.size() - (int)lower_pq.size();
        if (size_diff > 1)
        {
            lower_pq.push(upper_pq.top());
            upper_pq.pop();
        }
        else if (size_diff < -1)
        {
            upper_pq.push(lower_pq.top());
            lower_pq.pop();
        }

        int top = lower_pq.top();
        if (upper_pq.size() > lower_pq.size())
            top = upper_pq.top();
        std::cout << top << '\n';
    }
}