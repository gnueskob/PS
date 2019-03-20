// Count Circle Groups
// https://www.acmicpc.net/problem/10216
#include<cstdio>

inline int readInt() {int a;scanf("%d",&a);return a;}

/**
 * Find-Union Algorithm
 */
#define pow(a) ((a)*(a))
typedef struct pos { int x, y, r, g; } pos;

int f(int x, pos* p) { return p[x].g < 0 ? x : p[x].g = f(p[x].g, p); }

void u(int x, int y, pos* p) {
  x = f(x, p), y = f(y, p);
  if(x==y) return;
  p[y].g = x;
}

int main() {
  int T = readInt(), a[3000], idx=0;
  while(T--) {
    pos p[3000];
    int N = readInt(), i, j, ans=0;
    for(i=0; i<N; i++) {
      p[i] = {readInt(),readInt(),readInt(),-1};
      for(j=0; j<i; j++)
        if(pow(p[i].x-p[j].x) + pow(p[i].y-p[j].y) <= pow(p[i].r+p[j].r)) u(i,j,p);
    }
    for(i=0; i<N; i++) ans += p[i].g < 0;
    printf("%d\n",ans);
  }
  return 0;
}