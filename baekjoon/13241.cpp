// 최소공배수
// https://www.acmicpc.net/problem/13241
#include<iostream>
using namespace std;

long long gcd(long long a, long long b) {
  long long q, r;
  while(b) { q=a/b, r=a%b, a=b, b=r; }
  return a;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  long long a, b;
  cin >> a >> b;
  cout << a*b/gcd(a, b) << '\n';
  return 0;
}