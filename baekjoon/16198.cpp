// 에너지 모으기
// https://www.acmicpc.net/problem/16198
#include<iostream>
using namespace std;

int n, res = 0;
int e[10] = {0,};
bool chk[10] = {0,};

void solve(int cnt, int sum) {
  if (cnt == n-2) {
    if (res < sum) res = sum;
    return;
  }
  for (int i=1; i<n-1; i++) {
    if (chk[i]) continue;
    int left = i-1, right = i+1;
    while(chk[left] && left > 0) left--;
    while(chk[right] && right <= n) right++;
    chk[i] = true;
    solve(cnt + 1, sum + e[left] * e[right]);
    chk[i] = false;
  }
}

int main() {
  freopen("./input/16198.txt", "r", stdin);

  cin >> n;
  if (cin.eof()) return 0;

  for (int i=0; i<n; i++) cin >> e[i];

  solve(0, 0);

  cout << res;

  return 0;
}