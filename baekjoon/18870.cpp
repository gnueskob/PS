// https://www.acmicpc.net/problem/18870
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("18870.txt");
#endif

#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int N = GNUES::readInt();
    std::vector<int> arr(N);
    std::vector<std::pair<int, int>> arr_sort(N);

    for (int i=0; i<N; ++i)
    {
        arr[i] = GNUES::readInt();
        arr_sort[i] = {arr[i], i};
    }

    std::sort(arr_sort.begin(), arr_sort.end());

    int compressed_idx = 0, prev_num = arr_sort[0].first;
    for (auto [num, idx] : arr_sort)
    {
        if (prev_num != num) ++compressed_idx, prev_num = num;
        arr[idx] = compressed_idx;
    }

    for (int x : arr) GNUES::writeInt(x, ' ');
}