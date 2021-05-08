// https://www.acmicpc.net/problem/14003
// #LIS, #최단거리
#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("14002.txt");
#endif

// 14002 문제와 동일
#include <iostream>
#include <vector>
int main()
{
    std::vector<std::pair<int, int>> lis;
    std::vector<std::pair<int, int>> arr;
    int N = GNUES::readInt();
    lis.reserve(N);
    arr.reserve(N);

    auto pred = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
    {
        return lhs.first < rhs.first;
    };

    auto get_prev_index = [&lis](std::vector<std::pair<int, int>>::iterator itr)
    {
        if (itr == lis.begin()) return -1;
        return (--itr)->second;
    };

    int last_prev_idx = 0;
    for (int i=0; i<N; ++i)
    {
        int num = GNUES::readInt();
        auto find = std::lower_bound(lis.begin(), lis.end(), std::make_pair(num, 0), pred);
        int prev_idx = get_prev_index(find);
        arr.emplace_back(num, prev_idx);
        if (find == lis.end())
        {
            lis.emplace_back(num, i);
            last_prev_idx = prev_idx;
        }
        else
        {
            *find = { num, i };
            if (++find == lis.end())
                last_prev_idx = prev_idx;
        }
    }

    auto len = lis.size();
    std::vector<int> stack;
    stack.reserve(len);
    stack.push_back(lis[len-1].first);
    while (last_prev_idx != -1)
    {
        stack.push_back(arr[last_prev_idx].first);
        last_prev_idx = arr[last_prev_idx].second;
    }

    GNUES::writeInt(len, '\n');
    for (auto rbegin = stack.rbegin(); rbegin != stack.rend(); ++rbegin)
    {
        GNUES::writeInt(*rbegin, ' ');
    }
}