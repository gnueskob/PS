// 점프
// https://www.acmicpc.net/problem/1890
#include<cstdio>

typedef long long ll;

int main() {
  ll dp[100][100]{1,};
  int N, x;
  int i, j;
  scanf("%d",&N);
  for(i=0; i<N; i++) for(j=0; j<N; j++) {
    scanf("%d",&x);
    if(i+x<N && x) dp[i+x][j] += dp[i][j];
    if(j+x<N && x) dp[i][j+x] += dp[i][j];
  }
  printf("%lld",dp[N-1][N-1]);
  return 0;
}