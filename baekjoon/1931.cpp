// https://www.acmicpc.net/problem/1931
#include "_fileRead.hpp"
GNUES::FileRead f("1931.txt");

#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int N;
    std::cin >> N;

    // 가장 빨리 끝나는 회의부터 고르는 식
    std::vector<std::pair<int, int>> schedule;    // (finish time, start time)
    schedule.reserve(N);
    while (N--)
    {
        int finish, start;
        std::cin >> start >> finish;
        schedule.emplace_back(finish, start);
    }

    // 끝나는 시간 오름차순으로 정렬
    std::sort(schedule.begin(), schedule.end());

    // 각 구간은 (start, finish] 로 고려
    // 가장 빨리 끝나는 회의부터 확인
    int last_finished_time = 0, ans = 0;
    for (const auto& [finish, start] : schedule)
    {
        // 이전에 골랐던 회의와 겹치지 않을 때 다음 회의로 배정
        if (last_finished_time <= start)
        {
            ++ans;
            last_finished_time = finish;
        }
    }

    std::cout << ans;
}