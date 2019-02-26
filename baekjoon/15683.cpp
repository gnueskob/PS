// 감시
// https://www.acmicpc.net/problem/15683
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

#define isInGrid(nr, nc, n, m) (0 <= nr && nr < n && 0 <= nc && nc < m)

typedef tuple<int, int> t2;
typedef tuple<int, int, int> t3;
int dr[4] = {-1, 0, 1, 0}; // U, L, D, R
int dc[4] = {0, -1, 0, 1};

vector<t3> camera;
vector<t3> camera5;
char grid[8][8];
int n, m, cameraNum, ans = 64;

void display() {
  cout << "[Display]" << endl;
  for (int r=0; r<n; r++) {
    for (int c=0; c<m; c++)
      cout << grid[r][c] << ' ';
    cout << endl;
  }
}

int countBlindSpot();
void findMinimalBlindSpot(int currentCameraIdx);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/15683.txt", "r", stdin);

  cin >> n >> m;
  for (int r=0; r<n; r++) for (int c=0; c<m; c++) {
    cin >> grid[r][c];
    if (grid[r][c] != '0')
      switch(grid[r][c]) {
        case '1':
        case '2':
        case '3':
        case '4': camera.push_back({r, c, grid[r][c] - '0'}); cameraNum++; break;
        case '5': camera5.push_back({r, c, 5}); break;
        default: break;
      }
  }
  cout << "[input check] ";
  display();

  // update camera5 to grid
  int cameraRow, cameraCol;
  bool isDirBlocked[4] = { false, };
  for (auto it : camera5) {
    for (int i=1; i<8; i++) {
      tie(cameraRow, cameraCol, ignore) = it;
      for (int d=0; d<4; d++) {
        int nr = cameraRow + dr[d]*i, nc = cameraCol + dc[d]*i;
        if (isInGrid(nr, nc, n, m) && !isDirBlocked[d]) {
          if (grid[nr][nc] == '6') isDirBlocked[d] = true;
          else if(grid[nr][nc] == '0') grid[nr][nc] = '#';
        }
      }
    }
    for (int i=0; i<4; i++) isDirBlocked[i] = false;
  }
  cout << "[Camera 5 check] ";
  display();

  // Check all of camera
  findMinimalBlindSpot(0);

  cout << ans;
  return 0;
}

void findMinimalBlindSpot(int currentCameraIdx) {
  if (ans == 0) return;
  if (currentCameraIdx == cameraNum) {
    int bs = countBlindSpot();
    ans = bs < ans ? bs : ans;
    return;
  }
  int r, c, cameraNum, nr, nc;
  tie(r, c, cameraNum) = camera[currentCameraIdx];
  bool isDirBlocked[4] = { false, };
  queue<t2> currentWatchingPos;

  int watchCase = 0, watchingDir = 0, cameraDirInc = 0;
  switch(cameraNum) {
    default:
    case 1: watchCase = 4; watchingDir = 1; cameraDirInc = 1; break; // 4-cases, 1-direction
    case 2: watchCase = 2; watchingDir = 3; cameraDirInc = 2; break; // 2-cases, 2-direction
    case 3: watchCase = 4; watchingDir = 2; cameraDirInc = 1; break; // 4-cases, 2-direction
    case 4: watchCase = 4; watchingDir = 3; cameraDirInc = 1; break; // 4-cases, 3-direction
  }
  for (int d=0; d<watchCase; d++) {
    for (int dir=d; dir<d+watchingDir; dir+=cameraDirInc) {
      for (int i=0; i<8; i++) {
        nr = r + dr[dir%4]*i; nc = c + dc[dir%4]*i;
        if (isInGrid(nr, nc, n, m) && grid[nr][nc] != '6') {
          if (grid[nr][nc] == '0') {
            grid[nr][nc] = '#';
            currentWatchingPos.push({nr, nc});
          }
        } else { break; }
      }
    }
    // cout << "Current Camera : " << currentCameraIdx << endl;
    // display();
    findMinimalBlindSpot(currentCameraIdx + 1);
    // reset watching spots
    while (!currentWatchingPos.empty()) {
      tie(nr, nc) = currentWatchingPos.front(); currentWatchingPos.pop();
      grid[nr][nc] = '0';
    }
  }
}

int countBlindSpot() {
  int cnt = 0;
  for (int i=0; i<n; i++) for (int j=0; j<m; j++)
    if (grid[i][j] == '0') cnt++;
  return cnt;
}