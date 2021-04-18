// https://www.acmicpc.net/problem/3273
// #투포인터
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("3273.txt");
#endif

#include <vector>
int main()
{
    int n = GNUES::readInt();
    std::vector<int> arr(n);
    for (int i=0; i<n; ++i)
        arr[i] = GNUES::readInt();

    std::sort(arr.begin(), arr.end());

    int x = GNUES::readInt();

    int ans = 0, s = 0, e = n-1;
    while (true)
    {
        if (s >= e)
            break;

        int sum = arr[s] + arr[e];
        // 서로 다른 수열이므로 해당 쌍은 더이상 사용 안함
        if (sum == x)
            ++ans, ++s, --e;
        // 합이 더 크면 뒤쪽 포인터 내림
        else if (sum > x)
            --e;
        // 합이 더 작으면 앞쪽 포인터 올림
        else
            ++s;
    }

    GNUES::writeInt(ans);
}

// 해쉬 사용 빠른 버전
/*bool arr[1'000'001];
int main()
{
    int n = GNUES::readInt();
    for (int i=0; i<n; ++i)
        arr[GNUES::readInt()] = true;

    int x = GNUES::readInt();

    int ans = 0;
    for (int i=1; i<=1'000'000; ++i)
    {
        if (arr[i] == false || x <= i)
            continue;

        if (arr[x - i])
        {
            ++ans;
        }
    }

    GNUES::writeInt(ans/2);
}*/
