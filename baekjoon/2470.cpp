// https://www.acmicpc.net/problem/2470
// #투포인터
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("2470.txt");
#endif

#include <vector>
int main()
{
    int N = GNUES::readInt();
    std::vector<int> arr(N);
    for (int i=0; i<N; ++i)
        arr[i] = GNUES::readInt();

    std::sort(arr.begin(), arr.end());

    int s = 0, e = N-1;
    int min_s, min_e, min = std::numeric_limits<int>::max();
    while (true)
    {
        // 같은 용액을 중복 사용 할 수는 없음
        if (s >= e) break;

        // 최소 차이값에 근접하면 갱신
        int abs = std::abs(arr[s] + arr[e]);
        if (min > abs)
            min_s = s, min_e = e, min = abs;

        // 다음으로 체크할 방향 결정
        if (std::abs(arr[s] + arr[e-1]) > std::abs(arr[s+1] + arr[e]))
            ++s;
        else
            --e;
    }

    GNUES::writeInts(' ', 0, arr[min_s], arr[min_e]);
}