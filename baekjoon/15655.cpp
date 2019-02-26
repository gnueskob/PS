// N과 M (6)
// https://www.acmicpc.net/problem/15655
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'

int N, M, ans[8], arr[8];

void dfs(int order, int num) {
  if (order == M) {
    for (size_t i=0; i<M; i++) cout << ans[i] << ' ';
    cout << endl;
    return;
  }
  for (size_t i=num; i<N; i++) {
    ans[order] = arr[i];
    dfs(order + 1, i + 1);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("./input/15654.txt", "r", stdin);
  cin >> N >> M;
  for (size_t i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);
  dfs(0, 0);
  return 0;
}