// N과 M (3)
// https://www.acmicpc.net/problem/15651
#include<iostream>
using namespace std;

#define endl '\n'

int N, M;
char ans[16];

void dfs(int order, int num) {
  if (order == M) { cout << ans << endl; return; }
  for (size_t i=0; i<N; i++) {
    ans[order + order] = i + 1 + '0';
    dfs(order + 1, i + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("./input/15649.txt", "r", stdin);
  cin >> N >> M;
  for (int i=0; i<M+M; i++) ans[i] = ' ';
  dfs(0, 0);
  return 0;
}