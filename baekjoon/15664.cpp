// N과 M (10)
// https://www.acmicpc.net/problem/15664
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define endl '\n'

int N, M, arr[8];

void dfs(int order, int isUsed, int j, string num) {
  if (order == M) {
    cout << num << endl; return;
  }
  int prev = 0;
  for (int i=j; i<N; i++) {
    if (isUsed & 1<<i) continue;
    if (prev == arr[i]) continue;
    prev = arr[i];
    string addedNum = num + to_string(arr[i]) + " ";
    dfs(order + 1, isUsed | 1<<i, i + 1, addedNum);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("./input/15658.txt", "r", stdin);
  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);
  dfs(0, 0, 0, "");
  return 0;
}