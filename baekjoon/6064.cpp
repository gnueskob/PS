// 카잉 달력
// https://www.acmicpc.net/problem/6064
#include<iostream>
#include<cmath>
#include<tuple>
using namespace std;
typedef tuple<int, int, int> t3;

t3 gcd(int a, int b) {
  int s1=1, s2=0, s, t1=0, t2=1, t, q, r;
  // if(a<b) a^=b, b^=a, a^=b;
  while(b) {
    q=a/b, r=a%b, a=b, b=r;
    s=s1-q*s2, s1=s2, s2=s;
    t=t1-q*t2, t1=t2, t2=t;
  }
  return {a, s1, t1};
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, M, N, x, y, g, s, t, l;
  long long idx, ans;
  cin >> T;
  while(T--) {
    cin >> M >> N >> x >> y;
    if(x==y) { cout << x << '\n'; continue; }
    tie(g, s, t) = gcd(M,N); s*=(y-x)/g, t*=(y-x)/g;
    l = M*N/g;
    if((y-x)%g != 0) { cout << -1 << '\n'; continue; }
    int i=0;
    while(true) {
      ans = s+i*N/g, idx = ans*M + x;
      if(1 > idx) i++;
      else if(idx > l) i--;
      else { cout << idx << '\n'; break; }
    }
  }
  return 0;
}