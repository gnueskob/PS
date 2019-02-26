#include<cstdio>
int n[5000];
int main() {
  int N, M, idx; scanf("%d %d",&N,&M);
  for(int i=1; i<=N; i++) n[i]=i; n[0] = N; idx=M--%N;
  printf("<%d", n[idx]);
  while(N>1) {
    for(int i=idx; i<N; i++) n[i]=n[i+1]; N--;
    idx=(idx+M)%N; printf(", %d",n[idx]);
  }
  printf(">");
  return 0;
}