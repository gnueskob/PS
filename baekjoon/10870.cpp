// 피보나치 수 5
// https://www.acmicpc.net/problem/10870
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, ans=0, n=1, t; cin >> N;
  while(N--) t=ans+n, ans=n, n=t;
  cout << ans;
  return 0;
}