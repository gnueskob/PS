// https://www.acmicpc.net/problem/11053
#include "_fileRead.hpp"
GNUES::FileRead f("11053.txt");

/*
#include <iostream>
int main()
{
    int N, arr[1000], dp[1000], max = 1;
    std::cin >> N;
    for (int i=0; i<N; ++i)
        std::cin >> arr[i];

    // dp[i] = arr[i] 로 끝나는 최장 부분수열 길이
    for (int i=0; i<N; ++i)
    {
        // 자기 자신이 마지막
        dp[i] = 1;

        // 이전값까지 돌면서 체크
        for (int j=0; j<i; ++j)
        {
            // 자기 자신보다 낮은 수가 있다면
            if (arr[j] < arr[i])
            {
                // 그 수로 끝나는 최장 부분수열 길이 값 + 1
                // 자기 자신보다 작은 값이 여러개 있을 수 있고
                // 그 중에서 최장 부분수열 길이가 다를 수 있으므로
                // 최대치로만 갱신
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    max = std::max(max, dp[i]);
                }
            }
        }
    }

    std::cout << max;
}*/

/** #LIS(최장 증가 부분수열)
 * lower_bound 이분 탐색을 이용한 vector 처리 방식
 * i번째 원소 : 현재까지 만들 수 있는 i개의 원소를 가진 IS(증가 수열)들 중 가장 작은 수열의 i번째 원소
 * 만일 현재 value가 x 번째 인덱스로 들어가게 된다면, x-1번째의 원소는 x-1개의 IS중 가장 작은 x-1번째 원소기 때문에
 * value 보다 순서상 먼저 나타났고 value 보다 값이 작기 때문에 x번째 인덱스로 value가 들어가는 것이 타당하며
 * lowerbound의 값(value이상)을 value로 대체했기 때문에 value는 x개의 원소를 가진 IS중 x번째 원소가 가장 작은 IS의 x번째 원소이다.
 * 따라서 vector의 마지막 원소 는 현재까지 의 LIS 중 vector의 size개의 원소를 가진 LIS 중 가장 마지막 값이 작은 값을 만족하므로
 * 보다 큰 값이 나타났을 때, push 되는 것이 타당
 * 원소가 새롭게 중간의 위치로 들어가거나, push 될 때, 바로 이전 index의 값은 자신이 만들 수열의 바로 이전 값이므로
 * 이 값을 저장하면 백트래킹을 통해 LIS의 원소들을 구할 수 있음
 */
#include <iostream>
#include <vector>
#include <climits>
int main()
{
    std::vector<int> lis;
    int N, num;
    std::cin >> N;
    lis.reserve(N);
    lis.push_back(INT_MIN);
    while (N--)
    {
        std::cin >> num;
        auto find = std::lower_bound(lis.begin(), lis.end(), num);
        if (find == lis.end())
        {
            lis.push_back(num);
        }
        else
        {
            *find = num;
        }
    }

    std::cout << lis.size() - 1;
}