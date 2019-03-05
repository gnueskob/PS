// 행렬 곱셈
// https://www.acmicpc.net/problem/2740
#include<cstdio>
int A[100][100], B[100][100];
int main() {
  int N, M, K, t;
  scanf("%d%d",&N,&M);
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d",&A[i][j]);
  scanf("%d%d",&M,&K);
  for(int i=0; i<M; i++) for(int j=0; j<K; j++) scanf("%d",&B[i][j]);

  for(int i=0; i<N; i++)
    for(int j=0; j<K; j++) {
      int t = 0;
      for(int k=0; k<M; k++)
        t += A[i][k] * B[k][j];
      printf("%d%c",t,(j==K-1?'\n':' '));
    }
  return 0;
}