// https://www.acmicpc.net/problem/14889
#include "_fileRead.hpp"
GNUES::FileRead f("14889.txt");

/*
#include <iostream>
#include <climits>

int synergy[20][20], N, min = INT_MAX;
bool member[20];

void solve(int member_idx, int team_count, int synergy_sum, int other_sum)
{
    // 종료 - 각 팀 시너지 총합을 계산해야하므로 member_idx 끝까지 돌려봐야함
    if (member_idx >= N)
    {
        min = std::min(min, std::abs(other_sum - synergy_sum));
        return;
    }

    // 1) member_idx가 팀에 합류하지 않을 때
    // 미가입 남은 인원(N - member_idx)이 팀 남은 자리보다 많은 경우 합류 안할 수 있음
    if ((N/2 - team_count) < (N - member_idx))
    {
        int team_synergy = other_sum;
        for (int i=0; i<member_idx; ++i)
        {
            if (member[i] == false)  // 다른 팀원이라면
                team_synergy += (synergy[member_idx][i] + synergy[i][member_idx]);
        }
        solve(member_idx + 1, team_count, synergy_sum, team_synergy);
    }

    // 2) member_idx가 팀에 합류할 때
    // 이미 팀이 꽉 찼다면 스킵
    if ((N/2 - team_count) <= 0)
        return;

    ++team_count;
    member[member_idx] = true;

    // 오름차순으로 팀에 합류시킴
    // 이미 합류한 팀원인지 검사할 필요 없음
    // 이미 합류한 팀원은 검사하는 idx 보다 낮음

    // 현재까지의 시너지 총합에 이미 합류한 팀원들과의 시너지 총합 계산
    int team_synergy = synergy_sum;
    for (int i=0; i<member_idx; ++i)
    {
        if (member[i])  // 팀원이라면
            team_synergy += (synergy[member_idx][i] + synergy[i][member_idx]);
    }
    solve(member_idx + 1, team_count, team_synergy, other_sum);
    member[member_idx] = false;
}

int main()
{
    std::cin >> N;
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            std::cin >> synergy[i][j];

    solve(0, 0, 0, 0);
    std::cout << min;
}
*/

#include <iostream>
#include <climits>

int N, total = 0;       // total : synergy 테이블 총합
int synergy_sum[20];    // idx 번째 row, col 총합
int min = INT_MAX;

void solve(int idx, int team_cnt, int remain_total)
{
    // 팀에 사람이 충분해졌으면 종료
    if (team_cnt >= N / 2)
    {
        int abs = std::abs(remain_total);
        if (min > abs)
            min = abs;
        return;
    }

    // idx 번째 사람이 팀 합류하는지에 따라 분기
    if (idx < N - 1)
    {
        // 합류하는 경우
        // 팀에 합류시에 시너지 점수 row, col 총합을 빼나가면
        // 팀이 나뉜 후 남은 값이 각 팀간 시너지 합의 차이가 됨
        solve(idx + 1, team_cnt + 1, remain_total - synergy_sum[idx]);

        // 합류하지 않는 경우 (모두 합류하지 않는 경우가 생기는데 최소값이 아니라 상관없음)
        solve(idx + 1, team_cnt, remain_total);
    }
}

int main() {
    int in;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> in;
            total += in;
            synergy_sum[i] += in;
            synergy_sum[j] += in;
        }
    }

    solve(0, 0, total);
    std::cout << min;
}