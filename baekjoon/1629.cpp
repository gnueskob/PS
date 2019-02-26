// 곱셈
// https://www.acmicpc.net/problem/1629
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  long long A, B, C, ans=1; cin >> A >> B >> C;
  while(B) { if(B&1) ans=ans*A%C; A=A*A%C; B/=2; }
  cout << ans;
  return 0;
}