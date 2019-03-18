// 토마토
// https://www.acmicpc.net/problem/7569
#include<tuple>
#include<cstdio>
#include<queue>
using namespace std;

inline int readInt() {int a;scanf("%d",&a);return a;}

typedef tuple<char, char, char> t3;
char grid[100][100][100];
queue<t3> q;

int dr[] = {-1, 1, 0, 0, 0, 0};
int dc[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

int main() {
  int t(0), k(0), day(0), zero(0);
  char c = readInt(), r = readInt(), h = readInt();
  for(int k=0; k<h; k++) for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
    grid[k][i][j] = readInt();
    if(grid[k][i][j] == 1) q.push({k, i, j}), t++;
    else if(grid[k][i][j] == 0) zero++;
  }
  if(!zero) { puts("0"); return 0; }

  while(!q.empty()) {
    char height, row, col;
    tie(height, row, col) = q.front(); q.pop();
    for(int d=0; d<6; d++) {
      int nh = height + dh[d], nr = row + dr[d], nc = col + dc[d];
      if(!(0<=nh&&nh<h&&0<=nr&&nr<r&&0<=nc&&nc<c) || grid[nh][nr][nc]^0) continue;
      grid[nh][nr][nc] = 1, zero--;
      q.push({nh, nr, nc}), k++;
    }
    if(!(--t)) day++, t=k, k=0;
  }
  if(!zero) printf("%d",day-1);
  else puts("-1");
  return 0;
}