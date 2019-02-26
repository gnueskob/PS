// 이항 계수 3
// https://www.acmicpc.net/problem/11401
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod = (int) 1e9 + 7;

int main() {
  int N, K; scanf("%d%d",&N,&K); if(K>N/2) K=N-K;
  ll n=1, d=1, ans=1;
  for(int i=0; i<K; i++) { n*=N-i; n%=mod; d*=K-i; d%=mod; }
  for(ll i=mod-2; i; i/=2) {
    if(i&1) { ans*=d; ans%=mod; }
    d*=d; d%=mod;
  }
  printf("%d",n*ans%mod);
  return 0;
}