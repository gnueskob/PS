// https://www.acmicpc.net/problem/2110
#include "_fileRead.hpp"
GNUES::FileRead f("2110.txt");

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int main()
{
    int N, C;
    std::cin >> N >> C;
    std::vector<int> house(N);

    int left = INT_MAX, right = 0;
    for (int i=0; i<N; ++i)
    {
        int pos = 0;
        std::cin >> pos;
        house[i] = pos;
        left = std::min(left, pos);
        right = std::max(right, pos);
    }

    int distance = right - left;

    std::sort(house.begin(), house.end());

    int min_dist = 0, max_dist = distance;
    while (true)
    {
        // 현재 탐색중인 최소 공유기 인접거리 기준으로 배치해보기
        int wifi_cnt = 1, prev_pos = house.front();
        for (int i=1; i<N; ++i)
        {
            // 다음 집 거리가 최소 공유기 인접거리 이상이면 공유기 설치
            if (house[i] - prev_pos >= distance)
            {
                prev_pos = house[i];
                ++wifi_cnt;
                // 충분히 설치할 수 있다면 다음 테스트로 넘어가보기
                if (wifi_cnt >= C)
                    break;
            }
        }

        // 공유기를 다 설치하지 못한다면, 인접거리 줄여서 탐색
        if (wifi_cnt < C)
        {
            // 최대 탐색 거리 갱신
            max_dist = distance;

            // 다음 탐색 거리는 절반
            distance = std::max(min_dist, distance / 2);
        }
        // 공유기를 충분히 설치할 수 있는 인접거리라면, 인접거리 늘려서 탐색
        else
        {
            // 최소 탐색 거리 갱신
            min_dist = std::max(min_dist, distance);

            // 다음 탐색 거리는 max까지의 중간값
            int next = (max_dist + distance) / 2;
            if (distance == next)
                break;

            distance = next;
        }
    }

    std::cout << distance;
}