// https://www.acmicpc.net/problem/1300
#include "_fileRead.hpp"
GNUES::FileRead f("1300.txt");

#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    long long N, K;
    std::cin >> N >> K;

    int ans = K;
    int max_num = K;    // K번째 수는 항상 K 이하이므로 초기 max 값 K로 설정
    int min_num = 1;
    while (true)
    {
        // K 10억이하이므로 overflow 발생하지 않음
        int next = (min_num + max_num) / 2;

        // N*N 행렬에 탐색중인 num 이하인 수가 몇개 있는지 체크..
        long long cnt = 0;
        long long duplicated = 0;
        // sqrt(next)까지 찾고 대각대칭 기준 겹치는 개수 제외
        // next가 제곱수이면 행렬 대각선에 위치한 숫자까지 포함됨
        for (long long i=1; i*i<=next; ++i)
        {
            // num/i의 몫이 i번째 행(i, i*2, i*3 ...)에서 num 보다 작은 수의 개수
            // 단, N*N 행렬크기만큼 잘릴수 있으므로 min(N, num/i)
            cnt += std::min(N, next/i);
            duplicated = i*i;
        }
        cnt = 2 * cnt - duplicated;

        // cnt는 맞는 K번째 수라도 중복숫자로 더 높게 나올 수 있음
        if (cnt >= K)
        {
            ans = next;
            max_num = std::min(max_num, next - 1);
        }
        else
            min_num = std::max(min_num, next + 1);

        // min max 역전시 비로소 정답 찾은것
        if (min_num > max_num)
            break;
    }

    std::cout << ans;
}
