// 벽 부수고 이동하기 2
// https://www.acmicpc.net/problem/14442
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

#define GRID_MAX_SIZE 1000
#define DESTROY_MAX_SIZE 10
#define isInGrid(nr, nc, n, m) (0 <= nr && nr < n && 0 <= nc && nc < m)

typedef tuple<int, int, int, int> t4;

char grid[GRID_MAX_SIZE][GRID_MAX_SIZE];
bool visit[GRID_MAX_SIZE][GRID_MAX_SIZE][DESTROY_MAX_SIZE+1];
int n, m, k;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/14442.txt", "r", stdin);

  cin >> n >> m >> k;
  for (int r=0; r<n; r++)
    cin >> grid[r];

  queue<t4> path;
  path.push({0, 0, 1, 0});
  visit[0][0][0] = true;

  int r, c, d, cnt, nr, nc;
  while(!path.empty()) {
    tie(r, c, d, cnt) = path.front(); path.pop();
    for (int dir=0; dir<4; dir++) {
      nr = r + dr[dir]; nc = c + dc[dir];
      if (!isInGrid(nr, nc, n, m)) continue;
      int tcnt = grid[nr][nc] == '1' ? cnt+1 : cnt;
      if (visit[nr][nc][tcnt]) continue;
      if ((grid[nr][nc] == '1' && cnt < k) || grid[nr][nc] == '0') {
        if (nr == n-1 && nc == m-1) {
          cout << d+1 << '\n';
          return 0;
        }
        path.push({nr, nc, d+1, tcnt});
        visit[nr][nc][tcnt] = true;
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}