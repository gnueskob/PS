// 분해합
// https://www.acmicpc.net/problem/2231
#include<cstdio>
#define max(a,b) (a>b?a:b)
int getDecomSum(int a) {
  int ans = a;
  while(a) ans += a%10, a/=10;
  return ans;
}

int main() {
  int n; scanf("%d",&n);
  int ans = 0;
  for(int i=max(1,n-54); i<n; i++) {
    int s = getDecomSum(i);
    if(s == n) { ans = i; break; }
  }
  printf("%d",ans);
  return 0;
}