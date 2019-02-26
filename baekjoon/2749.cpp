// 피보나치 수 3
// https://www.acmicpc.net/problem/2749
#include <cstdio>
const int M = (int)1e6;
const int P = M/10*15;
int main() {
  long long n; int ans=0, next=1, temp=0; scanf("%lld",&n); n=n%P;
  while(n--) temp=ans+next, temp-=temp>=M?M:0, ans=next, next=temp;
  printf("%d",ans);
  return 0;
}