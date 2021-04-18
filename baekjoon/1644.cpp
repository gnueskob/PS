// https://www.acmicpc.net/problem/1644
// #에라토스테네스의체, #소수, #투포인터
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("1644.txt");
#endif

#include <algorithm>
bool prime[4'000'001];
int main()
{
    int N = GNUES::readInt();
    std::fill(prime + 0, prime + N + 1, true);

    // N/2 이하 소수 계산
    prime[1] = false;
    for (long long i=2; i*i<=N; ++i)
        if (prime[i])
            for (long long j=i*i; j<=N; j+=i) prime[j] = false;

    int s = 2, e = 2, sum = 2, ans = 0;
    while (true)
    {
        if (N == sum)
            ++ans;

        // 현재 소수 구간 합이 N 이상이면 s 부터 이동
        // s 커서 이동
        if (sum >= N)
        {
            sum -= s;
            while (true)
            {
                ++s;
                if (prime[s] || s > N)
                    break;
            }
        }
        else
        {
            // e 커서 이동
            while (true)
            {
                ++e;
                if (e > N)
                    break;

                if (prime[e])
                {
                    sum += e;
                    break;
                }
            }
        }

        if (e > N && sum < N)
            break;
    }

    GNUES::writeInt(ans);
}