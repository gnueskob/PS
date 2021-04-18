// https://www.acmicpc.net/problem/1806
// #투포인터
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("1806.txt");
#endif

#include <vector>
int main()
{
    auto [N, S] = GNUES::readInts<int, int>();
    std::vector<int> arr(N);
    for (int i=0; i<N; ++i)
        arr[i] = GNUES::readInt();

    int inf = std::numeric_limits<int>::max();
    int s = 0, e = 0, sum = 0, min = inf;
    while (true)
    {
        // 최후에는 e가 먼저 끝에 도달
        // 해가 없을 경우 s == e 되며 sum이 0이 되므로 종료조건 만족
        if (sum <= S && e >= N)
        {
            if (min == inf)
                min = 0;
            break;
        }

        // 다음 커서 위치 및 구간 합 갱신
        if (s == e || sum < S)
            sum += arr[e++];
        else
            sum -= arr[s++];

        // 구간 합 조건 만족시 수열 길이 갱신 [s, e)
        // 구간합 조건이 0인 경우 아무 것도 없는 수열(s==e)의 길이로 갱신될 수 있음
        if (sum >= S && s != e)
            min = std::min(min, e - s);
    }

    GNUES::writeInt(min);
}