// https://www.acmicpc.net/problem/17298
#include "_fileRead.hpp"
GNUES::FileRead f("17298.txt");

#include <iostream>
#include <vector>
#include <stack>
int main()
{
    int N;
    std::cin >> N;

    std::stack<std::pair<int, int>> stk;        // (숫자, 인덱스)
    stk.emplace(-1, 0); // 초기 조건
    std::vector<int> ans(N+1, -1);

    // 조회하면서, 자기 자신보다 큰 수가 첫번째로 나오는 것이 NGE(오큰수, 앞으로 나올 수 자신보다 큰 첫번째 수)
    // 그보다 더 큰수는 볼 필요가 없다.

    // 스택에 값을 쌓아가면서 NGE를 찾는다.
    // top이 현재 수보다 크면 계속 스택에 쌓아나간다. (아직 NGE를 찾지 못함)
    // top이 현재 수보다 작으면 더 큰 값이 나올때 까지의 쌓인 모든 수의 NGE가 현재 숫자
    // 결과를 찾은 인덱스는 이미 스택에서 제거된 상태
    for (int i=1; i<=N; ++i)
    {
        int num;
        std::cin >> num;

        // num 보다 큰 수가 나올때까지 스택 pop 및 해당위치 ans 갱신
        while (true)
        {
            auto& [stk_num, cur_idx] = stk.top();
            if (stk_num >= num || cur_idx <= 0)
                break;

            ans[cur_idx] = num;
            stk.pop();
        }

        stk.emplace(num, i);
    }

    for (int i=1; i<=N; ++i)
        std::cout << ans[i] << ' ';
}