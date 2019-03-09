#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> t3;

/**
 * 확장된 유클리드 호제법 알고리즘
 * O(max(logA, logB))
 * Ax + By = gcd(A,B) 일 때,
 * {gcd(A,B), s, t} 값을 리턴 (s, t : k=0일때의 일반 해)
 * x = s + k*B/gcd
 * y = t - k*A/gcd
 */
t3 extendedGCD(int a, int b) {
  int s1=1, s2=0, s, t1=0, t2=1, t, q, r;
  while(b) {
    q=a/b, r=a%b, a=b, b=r;
    s=s1-q*s2, s1=s2, s2=s;
    t=t1-q*t2, t1=t2, t2=t;
  }
  return {a, s1, t1};
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int a, b; cin >> a >> b;
  int gcd, s, t;
  tie(gcd, s, t) = extendedGCD(a,b);
  cout << '(' << a << ")*(" << s << ") + (" << b << ")*(" << t << ") = " << gcd << '\n';

  // GCC 내장 함수 : __gcd(a, b);
  cout << "builtin gcc __gcd : " << __gcd(a, b);
  return 0;
}