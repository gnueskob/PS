// 1로 만들기
// https://www.acmicpc.net/problem/1463
#include<iostream>
#include<algorithm>
using namespace std;

// const int MAX = 1e6;
// int dp[MAX+1];

int makeOne(int n) {
  if(n<2) return 0;
  if(dp[n]) return dp[n];
  int op2 = makeOne(n/2) + n%2 + 1;
  int op3 = makeOne(n/3) + n%3 + 1;
  dp[n] = min(op2, op3);
  return dp[n];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N; cin >> N;
  // for(int i=2; i<=N; i++) {
  //   dp[i] = dp[i-1];
  //   if(!(i%2)) dp[i] = min(dp[i], dp[i/2]);
  //   if(!(i%3)) dp[i] = min(dp[i], dp[i/3]);
  //   dp[i]++;
  // }
  // cout << dp[N];
  cout << makeOne(N);
  return 0;
}