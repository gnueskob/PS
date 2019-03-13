// 덩치
// https://www.acmicpc.net/problem/7568
#include<cstdio>

int main() {
  int N;
  char t[50], w[50];
  scanf("%d",&N);
  for(int i=0; i<N; i++) scanf("%d%d",&w[i],&t[i]);
  for(int i=0; i<N; i++) {
    int rank = 1;
    for(int j=0; j<N; j++) if(t[i] < t[j] && w[i] < w[j]) rank++;
    printf("%d ",rank);
  }
  return 0;
}