// N과 M
// https://www.acmicpc.net/problem/15649
#include<iostream>
using namespace std;

#define endl '\n'

int N, M;
bool isNumUsed[8];
char ans[16];

void dfs(int order) {
  if (order == M) { cout << ans << endl; return; }
  for (size_t i=0; i<N; i++) {
    if (isNumUsed[i]) continue;
    isNumUsed[i] = true;
    ans[order + order] = i + 1 + '0';
    if (order + 1 != M) ans[order + order + 1] = ' ';
    dfs(order + 1);
    isNumUsed[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("./input/15649.txt", "r", stdin);
  cin >> N >> M;
  dfs(0);
  return 0;
}