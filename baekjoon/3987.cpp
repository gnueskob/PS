// 보이저 1호
// https://www.acmicpc.net/problem/3987
#include<iostream>
using namespace std;

#define GIRD_MAX_SIZE 500
#define isInGrid(nr, nc, n, m) (0 <= nr && nr < n && 0 <= nc && nc < m)
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

char grid[GIRD_MAX_SIZE][GIRD_MAX_SIZE];
char direction[] = {'U', 'R', 'D', 'L'};
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int N, M, pr, pc;

#include<Windows.h>
void display(int lr, int lc) {
  cout << "[Grid Display]" << endl;
  for (int r=0; r<N; r++) {
    for (int c=0; c<M; c++) {
      if (r==lr && c==lc) cout << "* ";
      else cout << grid[r][c] << ' ';
    }
    cout << endl;
  }
  Sleep(1000);
}
int signal(int direction);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/3987.txt", "r", stdin);
  cin >> N >> M;
  for (int r=0; r<N; r++)
    cin >> grid[r];
  cin >> pr >> pc;
  pr--, pc--;

  int ans = 0, sec = 0, ansDir = 0;
  for (int dir=0; dir<4; dir++) {
    if ((sec = signal(dir)) == -1 ) {
      cout << direction[dir] << endl;
      cout << "Voyager";
      return 0;
    }
    else if (ans < sec) {
      ans = sec; ansDir = dir;
    }
  }
  cout << direction[ansDir] << endl;
  cout << ans;
  return 0;
}

int signal(int direction) {
  int sec = 1, currentDir = direction, nr = pr, nc = pc;
  while(true) {
    // display(nr, nc);
    nr = nr + dr[currentDir], nc = nc + dc[currentDir];
    if (!isInGrid(nr, nc, N, M) || grid[nr][nc] == 'C') break;
    if (nr == pr && nc == pc && currentDir == direction) return -1;
    sec++;
    if (grid[nr][nc] == '/') {
      if (currentDir == UP) currentDir = RIGHT;
      else if (currentDir == DOWN) currentDir = LEFT;
      else if (currentDir == LEFT) currentDir = DOWN;
      else currentDir = UP;
    } else if (grid[nr][nc] == '\\') {
      if (currentDir == UP) currentDir = LEFT;
      else if (currentDir == DOWN) currentDir = RIGHT;
      else if (currentDir == LEFT) currentDir = UP;
      else currentDir = DOWN;
    }
  }
  return sec;
}