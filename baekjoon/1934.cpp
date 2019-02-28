// 최소공배수
// https://www.acmicpc.net/problem/1934
#include<iostream>
using namespace std;

int gcd(int a, int b) {
  int q, r;
  while(b) { q=a/b, r=a%b, a=b, b=r; }
  return a;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, a, b; cin >> T;
  while(T--) {
    cin >> a >> b;
    cout << a*b/gcd(a, b) << '\n';
  }
  return 0;
}