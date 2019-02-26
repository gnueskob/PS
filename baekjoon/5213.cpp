// 과외맨
// https://www.acmicpc.net/problem/5213
#include<iostream>
#include<queue>
#include<tuple>
#include<string>
using namespace std;

#define GRID_MAX_SIZE 1000
#define isInGrid(nr, nc, n, m) (0 <= nr && nr < n && 0 <= nc && nc < m)

typedef struct Tile {
  int n;
  int idx;
} tile;
typedef tuple<int, int, int> t3;

int N;
tile grid[GRID_MAX_SIZE][GRID_MAX_SIZE];
int visit[GRID_MAX_SIZE][GRID_MAX_SIZE];
int path[GRID_MAX_SIZE*GRID_MAX_SIZE-GRID_MAX_SIZE/2+1];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void printPath(int idx, bool isLast);

#include<Windows.h>
void display() {
  cout << "visit" << endl;
  for (int r=0; r<N; r++) {
    for (int c=0; c<N*2; c++)
      cout << visit[r][c] << ' ';
    cout << endl;
  }
  Sleep(1000);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	freopen("./input/5213.txt", "r", stdin);

  cin >> N;
  int idx = 1, r = 0, c = 0;
  for (size_t i=1; i<=N*N-N/2; i++) {
    cin >> grid[r][c].n >> grid[r][c+1].n;
    grid[r][c].idx = i; grid[r][c+1].idx = i;
    c += 2;
    if (r%2 == 0 && c>=N*2) { r++; c = 1; }
    else if (r%2 == 1 && c>=N*2-1) { r++; c = 0; }
  }

  queue<t3> q;
  q.push({0, 0, 1});
  visit[0][0] = true; visit[0][1] = true;
  path[1] = 0;
  int d, nr, nc;
  int ansDist = 1;
  int ansIdx = 1;
  while(!q.empty()) {
    tie(r, c, d) = q.front(); q.pop();
    if ((grid[r][c].idx > ansIdx) || (grid[r][c].idx == ansIdx && ansDist > d)) {
      ansDist = d; ansIdx = grid[r][c].idx;
    }
    if (grid[r][c].idx == N*N-N/2) break;

    for (size_t i=0; i<2; i++) {
      for (size_t dir=0; dir<4; dir++) {
        nr = r + dr[dir]; nc = c + dc[dir];
        if (!isInGrid(nr, nc, N, N*2) || !grid[nr][nc].n) continue;
        int vc;
        if (0 <= nc-1 && grid[nr][nc].idx == grid[nr][nc-1].idx) vc = nc-1;
        else if (nc+1 < N*2 && grid[nr][nc].idx == grid[nr][nc+1].idx) vc = nc+1;
        if (visit[nr][nc] || visit[nr][vc]) continue;
        if (grid[r][c].idx != grid[nr][nc].idx && grid[r][c].n == grid[nr][nc].n) {
          q.push({nr, nc, d+1});
          visit[nr][nc] = true; visit[nr][vc] = true;
          path[grid[nr][nc].idx] = grid[r][c].idx;
        }
      }
      // check half tile
      if (0 <= c-1 && grid[r][c].idx == grid[r][c-1].idx) c = c-1;
      else if (c+1 < N*2 && grid[r][c].idx == grid[r][c+1].idx) c = c+1;
    }
  }
  cout << ansDist << endl;
  printPath(ansIdx, true);
  return 0;
}

void printPath(int idx, bool isLast) {
  if (idx <= 1) { cout << 1 << ' '; return; }
  printPath(path[idx], false);
  cout << idx;
  if (!isLast) cout << ' ';
}