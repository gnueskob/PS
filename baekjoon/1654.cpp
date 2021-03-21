// https://www.acmicpc.net/problem/1654
#include "_fileRead.hpp"
GNUES::FileRead f("1654.txt");

#include <iostream>
#include <vector>
int main()
{
    int n, k, cable_len = 0;
    std::cin >> n >> k;

    std::vector<int> length(n);
    for (int i=0; i<n; ++i)
    {
        int num;
        std::cin >> num;
        length[i] = num;

        // 제일 작은 케이블 길이보다 긴 케이블이 정답으로 나올 수 있으므로
        // 제일 긴 케이블부터 탐색 시작
        cable_len = std::max(cable_len, num);
    }

    // parametric search (binary search +)
    // 자를 케이블 길이를 이분탐색해나가며 조건 체크
    int max_cable_len = cable_len;
    int min_cable_len = 1;
    while (true)
    {
        // 현재 탐색하는 케이블 길이로 자를때 나오는 랜선 개수
        // cable_len이 매우 작고, len이 클수록 cable_num은 int 범위 초과 가능
        long long cable_num = 0;
        for (auto len : length)
            cable_num += len / cable_len;

        // 자른 케이블 개수가 부족하면 max 갱신, 다음 탐색 길이 절반
        if (cable_num < k)
        {
            max_cable_len = cable_len;
            cable_len = std::max(min_cable_len, cable_len/2);
        }
        // 자른 케이블 개수가 충분하면 min 길이 갱신 및 종료 조건 검사
        else
        {
            min_cable_len = std::max(min_cable_len, cable_len);

            // 다음 조회할 숫자와 같으면 종료
            // int 최대 길이 plus로 인한 오버 플로우 고려
            int next = ((long long)max_cable_len + min_cable_len) / 2;
            if (cable_len == next)
                break;

            cable_len = next;
        }
    }

    std::cout << cable_len;
}