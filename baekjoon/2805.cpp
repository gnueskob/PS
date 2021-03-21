// https://www.acmicpc.net/problem/2805
#include "_fileRead.hpp"
GNUES::FileRead f("2805.txt");

#include <iostream>
#include <vector>
int main()
{
    int N, M, height = 0;
    std::cin >> N >> M;

    std::vector<int> tree(N);
    for (int i=0; i<N; ++i)
    {
        int num;
        std::cin >> num;
        tree[i] = num;
        height = std::max(height, num);
    }

    // parametrix search
    int min_height = 0, max_height = height;
    while (true)
    {
        // 탐색중인 높이로 나무 잘랐을때, 얻을 수 있는 나무 길이
        long long total_cut = 0;
        for (auto h : tree)
        {
            total_cut += std::max(0, h - height);
            if (total_cut >= M)
                break;
        }

        // 나무 길이가 부족하므로 탐색 높이 더 낮게 세팅
        if (total_cut < M)
        {
            // 탐색 범위 최대길이 갱신
            max_height = height;

            // 다음 탐색 높이 절반
            height = std::max(min_height, height/2);
        }
        // 나무 길이가 충분하므로 탐색 높이 더 높게 세팅
        else
        {
            // 탐색 범위 최소길이 갱신
            min_height = std::max(min_height, height);

            // 다음 탐색 길이는 현재 탐색길이 ~ max 중간값
            int next = (max_height + height) / 2;

            // 다음 탐색길이도 같을경우 종료조건 (최대 높이)
            if (height == next)
                break;

            height = next;
        }
    }

    std::cout << height;
}