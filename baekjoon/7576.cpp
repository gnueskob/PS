// 토마토
// https://www.acmicpc.net/problem/7576
#include<tuple>
#include<cstdio>
#include<queue>
using namespace std;

inline int readInt() {int a;scanf("%d",&a);return a;}

typedef tuple<short, short> t2;
char grid[1000][1000];
queue<t2> q;

short dr[] = {-1, 1, 0, 0};
short dc[] = {0, 0, -1, 1};

int main() {
  short c = readInt(), r = readInt();
  int t(0), k(0), day(0), zero(0);
  for(short i=0; i<r; i++) for(short j=0; j<c; j++) {
    grid[i][j] = readInt();
    if(grid[i][j] == 1) q.push({i, j}), t++;
    else if(grid[i][j] == 0) zero++;
  }
  if(!zero) { puts("0"); return 0; }

  while(!q.empty()) {
    short row, col;
    tie(row, col) = q.front(); q.pop();
    for(int d=0; d<4; d++) {
      short nr = row + dr[d], nc = col + dc[d];
      if(!(0<=nr&&nr<r&&0<=nc&&nc<c) || grid[nr][nc]^0) continue;
      grid[nr][nc] = 1, zero--;
      q.push({nr, nc}), k++;
    }
    if(!(--t)) day++, t=k, k=0;
  }
  if(!zero) printf("%d",day-1);
  else puts("-1");
  return 0;
}