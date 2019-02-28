// 최대공약수와 최소공배수
// https://www.acmicpc.net/problem/2609
#include<iostream>
using namespace std;

int gcd(int a, int b) {
  int q, r;
  while(b) { q=a/b, r=a%b, a=b, b=r; }
  return a;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int a, b;
  cin >> a >> b;
  cout << gcd(a,b) << '\n';
  cout << a*b/gcd(a, b);
  return 0;
}