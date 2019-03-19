// 미로 탐색
// https://www.acmicpc.net/problem/2178
#include<cstdio>
using namespace std;

typedef struct pos { char r, c; } pos;

int main() {
  int n, m, len(1), t(1), k(0), front(0), back(0);
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  char grid[100][100];
  pos q[10000];
  scanf("%d%d",&n,&m);
  for(int r=0; r<n; r++) for(int c=0; c<m; c++) scanf("%1d",&grid[r][c]);
  q[back++] = {0, 0};
  grid[0][0] = 2;
  while(front != back) {
    char r = q[front].r, c = q[front].c; front++;
    if(r == n-1 && c == m-1) { printf("%d",len); break; }
    for(int d=0; d<4; d++) {
      char nr = r + dr[d], nc = c + dc[d];
      if(!(0<=nr&&nr<n&&0<=nc&&nc<m) || grid[nr][nc]^1) continue;
      grid[nr][nc] = 2, k++;
      q[back++] = {nr,nc};
    }
    if(!(--t)) len++, t=k, k=0;
  }
  return 0;
}