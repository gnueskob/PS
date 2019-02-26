// 계단 오르기
// https://www.acmicpc.net/problem/2579
#include<iostream>
using namespace std;
#define max(a,b) (a>b?a:b)

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, t, pp=0, p1, p2; cin >> n;
  cin >> p1; p2=0;
  while(--n) {
    cin >> t;
    int t1=p1, t2=p2;
    p2 = t + p1;
    p1 = t + pp;
    pp = max(t1, t2);
  }
  cout << max(p1, p2);
  return 0;
}