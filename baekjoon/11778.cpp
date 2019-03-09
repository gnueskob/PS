// 피보나치 수와 최대공약수
// https://www.acmicpc.net/problem/11778
#include<cstdio>
#include<utility>
using namespace std;

#define F first
#define S second
typedef long long ll;
typedef pair<pair<ll, ll>, pair<ll, ll>> Matrix_2by2;
const ll mod = 1e9 + 7;

ll getGCD(ll n, ll m) {
  ll t;
  while(m) t=n%m, n=m, m=t;
  return n;
}

Matrix_2by2 operator * (const Matrix_2by2& a, const Matrix_2by2& b) {
  int size = 2;
  return {{(a.F.F*b.F.F + a.F.S*b.S.F) % mod, (a.F.F*b.F.S + a.F.S*b.S.S) % mod},
          {(a.S.F*b.F.F + a.S.S*b.S.F) % mod, (a.S.F*b.S.F + a.S.S*b.S.S) % mod}};
}

int main() {
  ll n, m; scanf("%lld%lld",&n,&m);
  ll gcd = getGCD(n,m);
  Matrix_2by2 ans = {{1LL,0LL},{0LL,1LL}};
  Matrix_2by2 I = {{1LL,1LL},{1LL,0LL}};
  while(gcd) {
    if(gcd&1) ans = ans * I;
    I = I * I;
    gcd/=2;
  }
  printf("%lld",ans.F.S);
  return 0;
}