#include<iostream>
#include<queue>
#include<tuple>
#include<string>
using namespace std;

#define GRID_MAX_SIZE 500
#define isInGrid(nr, nc, n, m) (0 <= nr && nr < n && 0 <= nc && nc < m)

typedef struct Tile {
  int n;
  int idx;
} tile;
typedef tuple<int, int, int, string> t4;

int N;
tile grid[GRID_MAX_SIZE][GRID_MAX_SIZE*2];
int visit[GRID_MAX_SIZE][GRID_MAX_SIZE*2];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void display() {
  for (int r=0; r<N; r++) {
    for (int c=0; c<N*2; c++)
      cout << grid[r][c].n << ' ';
    cout << endl;
  }
}

#include<windows.h>
void displayV(string path) {
  cout << "Visit : " << path << endl;
  for (int r=0; r<N; r++) {
    for (int c=0; c<N*2; c++)
      cout << (visit[r][c] > 100 ? 0 : visit[r][c]) << ' ';
    cout << endl;
  }
  Sleep(500);
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
    visit[r][c] = N*N; visit[r][c+1] = N*N;
    c += 2;
    if (r%2 == 0 && c>=N*2) { r++; c = 1; }
    else if (r%2 == 1 && c>=N*2-1) { r++; c = 0; }
  }

  // display();

  queue<t4> q;
  q.push({0, 0, 1, "1"});
  visit[0][0] = true;
  int d, nr, nc; string path;
  int ansDist = 1;
  int ansIdx = 1;
  string ansPath = "1";
  while(!q.empty()) {
    tie(r, c, d, path) = q.front(); q.pop();
    if ((grid[r][c].idx > ansIdx) || (grid[r][c].idx == ansIdx && ansDist > d)) {
      ansDist = d; ansIdx = grid[r][c].idx; ansPath = path;
    }
    if (grid[r][c].idx == N*N-N/2) {
      cout << d << endl;
      for (auto c : path) {
        if (c != '-') cout << c;
        else cout << ' ';
      }
      return 0;
    }
    for (size_t dir=0; dir<4; dir++) {
      nr = r + dr[dir]; nc = c + dc[dir];
      if (!isInGrid(nr, nc, N, N*2) || !grid[nr][nc].n) continue;
      if (grid[r][c].idx == grid[nr][nc].idx && visit[nr][nc] > d) {
        q.push({nr, nc, d, path}); visit[nr][nc] = true;
      } else if (grid[r][c].n == grid[nr][nc].n && visit[nr][nc] > d+1) {
        q.push({nr, nc, d+1, path + "-" + to_string(grid[nr][nc].idx)});
        visit[nr][nc] = true;
      }
      displayV(path);
    }
  }
  cout << ansDist << endl;
  for (auto c : ansPath) {
    if (c != '-') cout << c;
    else cout << ' ';
  }

  return 0;
}