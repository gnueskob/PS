// https://www.acmicpc.net/problem/12852
// #다이나믹프로그래밍, #최단거리

#include <iostream>
#include <limits>
int arr[1'000'000][2];
int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N; std::cin >> N;
    for (int i=2; i<=N; ++i)
        arr[i][0] = std::numeric_limits<int>::max();

    auto update_path = [](int before, int next)
    {
        if (arr[next][0] <= arr[before][0] + 1)
            return;

        arr[next][0] = arr[before][0] + 1;
        arr[next][1] = before;
    };

    for (int i=1; i<=N; ++i)
    {
        if (i*3 <= N)   update_path(i, i*3);
        if (i*2 <= N)   update_path(i, i*2);
        if (i+1 <= N)   update_path(i, i+1);
    }

    std::cout << arr[N][0] << '\n';
    int path_idx = N;
    while (true)
    {
        std::cout << path_idx << ' ';
        if (path_idx <= 1)
            break;

        path_idx = arr[path_idx][1];
    }
}