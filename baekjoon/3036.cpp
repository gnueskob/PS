// 링
// https://www.acmicpc.net/problem/3036
#include<iostream>
using namespace std;

int getGCD(int a, int b) {
  int c;
  while(b) c=a%b, a=b, b=c;
  return a;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, r, nr, gcd; cin >> N >> r;
  while(--N) {
    cin >> nr;
    gcd = getGCD(r, nr);
    cout << r/gcd << '/' << nr/gcd << '\n';
  }
  return 0;
}