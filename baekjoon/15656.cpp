// N과 M (7)
// https://www.acmicpc.net/problem/15656
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define endl '\n'

int N, M, ans[8], arr[8];

void dfs(int order, string num) {
  if (order == M) {
    cout << num << endl; return;
  }
  for (size_t i=0; i<N; i++) {
    string addedNum = num + to_string(arr[i]) + " ";
    dfs(order + 1, addedNum);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("./input/15654.txt", "r", stdin);
  cin >> N >> M;
  for (size_t i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);
  dfs(0, "");
  return 0;
}