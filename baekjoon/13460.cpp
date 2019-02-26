// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

#define GRID_MAX_SIZE 10
#define RED 0
#define BLUE 1
#define U 0
#define L 1
#define D 2
#define R 3

typedef tuple<int, int, int, int> t4;

char grid[GRID_MAX_SIZE][GRID_MAX_SIZE];
bool visit[GRID_MAX_SIZE][GRID_MAX_SIZE][GRID_MAX_SIZE][GRID_MAX_SIZE];
int N, M, br[2], bc[2], gr, gc;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

#include<Windows.h>
void display(int depth) {
  cout << "Current Grid : " << depth << endl;
  for (int r=0; r<N; r++) {
    for (int c=0; c<M; c++)
      cout << grid[r][c] << ' ';
    cout << endl;
  }
  Sleep(1000);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/13460.txt", "r", stdin);
  cin >> N >> M;
  for (size_t r=0; r<N; r++)
    for (size_t c=0; c<M; c++) {
      cin >> grid[r][c];
      if (grid[r][c] == 'R') br[RED] = r, bc[RED] = c, grid[r][c] = '.';
      else if (grid[r][c] == 'B') br[BLUE] = r, bc[BLUE] = c, grid[r][c] = '.';
      else if (grid[r][c] == 'O') gr = r, gc = c;
    }

  queue<t4> q;
  q.push({br[RED], bc[RED], br[BLUE], bc[BLUE]});
  visit[br[RED]][bc[RED]][br[BLUE]][bc[BLUE]] = true;
  int ans = 1, qSize, nr, nc, pr[2], pc[2];
  bool fall[2] = {false, };
  while(!q.empty()) {
    qSize = q.size();
    while(qSize--) {
      tie(br[RED], bc[RED], br[BLUE], bc[BLUE]) = q.front(); q.pop();
      // find 4-direction gravity movement
      for (size_t dir=0; dir<4; dir++) {
        int currentBallIndex;
        switch(dir) {
          default:
          case U: currentBallIndex = br[RED] <= br[BLUE] ? RED : BLUE; break;
          case L: currentBallIndex = bc[RED] <= bc[BLUE] ? RED : BLUE; break;
          case D: currentBallIndex = br[RED] >= br[BLUE] ? RED : BLUE; break;
          case R: currentBallIndex = bc[RED] >= bc[BLUE] ? RED : BLUE; break;
        }
        // check RED, BLUE ball
        bool isFirstCheck = true;
        int tempRow = 0, tempCol = 0; // use to reset grid character for checking collision between balls
        fall[RED] = false, fall[BLUE] = false;
        for (size_t ball=0; ball<2; ball++) {
          char obj;
          nr = br[currentBallIndex], nc = bc[currentBallIndex];
          while(true) { // check iteratively until meet among the goal, wall and different ball
            nr += dr[dir], nc += dc[dir];
            if (grid[nr][nc] == 'O') { fall[currentBallIndex] = true; break; }
            if (grid[nr][nc] != '.') {
              if (isFirstCheck) {
                isFirstCheck = false;
                tempRow = nr - dr[dir], tempCol = nc - dc[dir];
                grid[tempRow][tempCol] = 'X';
              }
              pr[currentBallIndex] = nr - dr[dir], pc[currentBallIndex] = nc - dc[dir];
              break;
            }
          }
          currentBallIndex = (currentBallIndex + 1) % 2;
        }
        grid[tempRow][tempCol] = '.';
        if (fall[RED] && !fall[BLUE]) { cout << ans; return 0; }
        else if (!fall[RED] && !fall[BLUE] && !visit[pr[RED]][pc[RED]][pr[BLUE]][pc[BLUE]]) {
          q.push({pr[RED], pc[RED], pr[BLUE], pc[BLUE]});
          visit[pr[RED]][pc[RED]][pr[BLUE]][pc[BLUE]] = true;
        }
      }
    }
    ans++;
    if (ans > 10) break;
  }
  cout << -1;
  return 0;
}