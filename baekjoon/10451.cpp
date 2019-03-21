// 순열 사이클
// https://www.acmicpc.net/problem/10451
#include<cstdio>

inline int readInt() {int a;scanf("%d",&a);return a;}

const int MAX = 1e3+1;
int vt[MAX];

int main() {
  int T = readInt(), i;
  while(T--) {
    int N = readInt(), res=0, next, now;
    for(i=1; i<=N; i++) vt[i] = readInt();
    for(i=1; i<=N; i++) {
      if(vt[now=i]) res++;
      while(vt[now]) next=vt[now], vt[now]=0, now=next;
    }
    printf("%d\n",res);
  }
  return 0;
}