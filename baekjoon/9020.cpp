// 골드바흐의 추측
// https://www.acmicpc.net/problem/9020
#include<cstdio>

const int MAXN = 10000;
bool composite[MAXN];
int main() {
  int T, N, ans;
  for(int i=2; i*i<MAXN; i++)
    if(!composite[i]) for(int j=i*i; j<MAXN; j+=i) composite[j]=true;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    for(int i=N/2; i>=2; i--) if(!composite[i] && !composite[N-i]) { ans=i; break; }
    printf("%d %d\n", ans, N-ans);
  }
  return 0;
}