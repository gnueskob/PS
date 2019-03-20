// 단지번호붙이기
// https://www.acmicpc.net/problem/2667
#include<cstdio>
#include<algorithm>

typedef struct pos { char r, c; } pos;

char dr[] = {-1,1,0,0};
char dc[] = {0,0,-1,1};
char grid[25][25];
int N;
pos q[625];

int connect(int i, int j) {
  int f=0, b=0;
  q[b++] = {i,j};
  grid[i][j] = -1;
  while(f != b) {
    int r=q[f].r, c=q[f++].c;
    for(int d=0; d<4; d++) {
      char nr = r + dr[d], nc = c + dc[d];
      if(!(0<=nr&&nr<N&&0<=nc&&nc<N) || grid[nr][nc]^1) continue;
      q[b++] = {nr,nc};
      grid[nr][nc] = -1;
    }
  }
  return b;
}

int main() {
  int i, j, h[625], idx=0;
  scanf("%d",&N);
  for(i=0; i<N; i++) for(j=0; j<N; j++) scanf("%1d",&grid[i][j]);
  for(i=0; i<N; i++) for(j=0; j<N; j++)
    if(grid[i][j] == 1) h[idx++] = connect(i, j);
  std::sort(h, h+idx);
  printf("%d\n",idx);
  for(i=0; i<idx; i++) printf("%d\n",h[i]);
  return 0;
}