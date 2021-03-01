// https://www.acmicpc.net/problem/11054
#include "_fileRead.hpp"
GNUES::FileRead f("11054.txt");

#include <iostream>

enum DIREC
{
    INC = 0,
    DEC = 1,
    MAX = 2,
};

int main()
{
    int dp[1000][DIREC::MAX], arr[1000], N, max = 1;
    std::cin >> N;
    for (int i=0; i<N; ++i)
    {
        std::cin >> arr[i];
        // dp[i][INC] : i 번째 수가 증가하면서 끝나는 최장 바이토닉 부분수열 길이
        // dp[i][DEC] : i 번째 수가 감소하면서 끝나는 최장 바이토닉 부분수열 길이
        dp[i][INC] = dp[i][DEC] = 1;

        // i 이전까지 순회하며 비교
        for (int j=0; j<i; ++j)
        {
            // j 번째 수가 더 작은 경우 (증가하는 부분수열)
            // dp[j][INC] + 1 보다 작다면 j 번째 다음으로 i 가 오는 부분수열이
            // i 번째로 증가하며 끝나는 부분 수열 중 가장 긴 것
            if (arr[j] < arr[i] && dp[i][INC] < dp[j][INC] + 1)
            {
                dp[i][INC] = dp[j][INC] + 1;
                max = std::max(max, dp[i][INC]);
            }
            // j 번째 수가 더 큰 경우 (감소하는 부분수열)
            else if (arr[j] > arr[i])
            {
                // j 번째까지 증가하다가 i 번째에서 감소하는 부분수열이 가장 길 때
                if (dp[i][DEC] < dp[j][INC] + 1)
                {
                    dp[i][DEC] = dp[j][INC] + 1;
                    max = std::max(max, dp[i][DEC]);
                }

                // j 번째도 이미 감소하는 부분수열이면서 i 번째가 부분수열이 추가될 때
                if (dp[i][DEC] < dp[j][DEC] + 1)
                {
                    dp[i][DEC] = dp[j][DEC] + 1;
                    max = std::max(max, dp[i][DEC]);
                }

                // 두 경우 중 dp[i][DEC] 가 더 큰 값으로..
            }
        }
    }

    std::cout << max;
}

// 다른 풀이
// dp[i] : i 번째로 끝나는 최장 부분 수열 길이
// r_dp[i] : 뒤에서부터 i 번째로 끝나는 최장 부분 수열 길이
// dp[i] + r_dp[i] - 1(i번째 원소 중복) 이 i번째가 최대가 되는 바이토닉 부분 수열 길이