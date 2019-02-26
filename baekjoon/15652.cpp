// N과 M (4)
// https://www.acmicpc.net/problem/15652
#include<iostream>
using namespace std;

#define endl '\n'

int N, M;
char ans[16];

void dfs(int order, int num) {
  if (order == M) { cout << ans << endl; return; }
  for (size_t i=num; i<=N; i++) {
    ans[order<<1] = i + '0';
    dfs(order + 1, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("./input/15649.txt", "r", stdin);
  cin >> N >> M;
  for (int i=0; i<(M<<1); i++) ans[i] = ' ';
  dfs(0, 1);
  return 0;
}