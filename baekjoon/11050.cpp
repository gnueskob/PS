// 이항 계수 1
// https://www.acmicpc.net/problem/11050
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, K, ans=1; cin >> N >> K;
  for(int i=N; i>N-K; i--) ans *= i;
  for(int i=K; i>=1; i--) ans /= i;
  cout << ans;
  return 0;
}