// https://www.acmicpc.net/problem/1450
// #투포인터, #중간자, #MITM
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("1450.txt");
#endif

#include <iostream>
#include <vector>

int max = 1E9;

void dfs(int end, int pos, int sum, const std::vector<int>& weight, std::vector<int>& cnt)
{
    if (pos >= end)
    {
        // 부분합 경우의 수 추가
        cnt.push_back(sum);
        return;
    }

    // pos 번째가 부분합에 포함 안되는 경우
    dfs(end, pos+1, sum, weight, cnt);

    // 합이 10^9 넘어가는건 구할 필요 없음
    if (sum + weight[pos] > max)
        return;

    // pos 번째가 부분합에 포함되는 경우
    dfs(end, pos+1, sum + weight[pos], weight, cnt);
}

int main()
{
    int n, c;
    std::cin >> n >> c;

    // MITM 방식을 위해 절반 나누어 따로 구함
    std::vector<int> weight, left, right;

    weight.reserve(n);
    for (int i=0; i<n; ++i)
    {
        int w; std::cin >> w;
        if (w > c)
            continue;
        weight.push_back(w);
    }

    int half_cnt = weight.size() / 2;
    dfs(half_cnt, 0, 0, weight, left);
    dfs(weight.size(), half_cnt, 0, weight, right);

    // 이분 탐색을 위한 정렬
    std::sort(right.begin(), right.end());

    int ans = 0;
    for (const auto& prev_sum : left)
    {
        // right 의 부분합 중 c - prev_sum 이하인 부분합 개수만큼 결과에 더함
        auto ub = std::upper_bound(right.begin(), right.end(), c - prev_sum);
        ans += std::distance(right.begin(), ub);
    }

    std::cout << ans;
}