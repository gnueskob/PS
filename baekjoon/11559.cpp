// PuyoPuyo
// https://www.acmicpc.net/problem/11559
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

typedef tuple<int, int> t2;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

char grid[12][6];
bool visit[12][6];
char shiftPuyo[6][12];

bool searchSamePuyo(int row, int col);
void display(int chainCounter);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/11559.txt", "r", stdin);

  for (int i=11; i>=0; i--) for (int j=0; j<6; j++)
    cin >> grid[i][j];

  bool exist4ChainPuyo = false;
  int chainCounter = 0;
  display(chainCounter);
  do {
    exist4ChainPuyo = false;
    // find 4-chain puyo from first row
    for (int r=0; r<12; r++) {
      for (int c=0; c<6; c++)
        // count empty cell of current row
        if (grid[r][c] == '.') continue;
        else if (!visit[r][c] && searchSamePuyo(r, c)) exist4ChainPuyo = true;
    }
    if (exist4ChainPuyo) chainCounter++;

    // after remove 4-chain puyo, set position of remaining puyos
    int shiftIdx = 0;
    for (int c=0; c<6; c++) {
      shiftIdx = 0;
      for (int r=0; r<12; r++)
        if (grid[r][c] != '.') shiftPuyo[c][shiftIdx++] = grid[r][c];
      for (int r=0; r<12; r++) {
        grid[r][c] = r <= shiftIdx - 1 ? shiftPuyo[c][r] : '.';
      }
    }

    // reset visit flag
    for (int r=0; r<12; r++) for (int c=0; c<6; c++) visit[r][c] = false;

    display(chainCounter);
  } while (exist4ChainPuyo);

  cout << chainCounter;
  return 0;
}

// find same puyo using BFS
bool searchSamePuyo(int r, int c) {
  cout << "[search start] : " << r << ',' << c << endl;
  char currentPuyo = grid[r][c];
  queue<t2> puyo;
  puyo.push(make_tuple(r,c));
  t2 tempCellBefore4[3]; // to store cells(max 3) until find 4-chain puyo
  tempCellBefore4[0] = puyo.front();
  int linkedCounter = 1;

  while (!puyo.empty()) {
    int currentRow, currentCol;
    tie(currentRow, currentCol) = puyo.front(); puyo.pop();
    visit[currentRow][currentCol] = true;
    cout << "Looking : " << currentRow << ", " << currentCol << endl;
    // check 4 direction : dr[4], dc[4]
    for (int i=0; i<4; i++) {
      int nr = currentRow + dr[i], nc = currentCol + dc[i];
      if (0 <= nr && nr < 12 && 0 <= nc && nc < 6
      && !visit[nr][nc] && grid[nr][nc] == currentPuyo) {
        t2 samePuyo = make_tuple(nr, nc);
        puyo.push(samePuyo);
        linkedCounter++;
        if (linkedCounter < 4) tempCellBefore4[linkedCounter - 1] = samePuyo;
        else { grid[nr][nc] = '.'; }
      }
    }
  }
  // if this puyo chain is longer than 4, remove the first 3 puyos
  if (linkedCounter >= 4)
    for (int i=0; i<3; i++) {
      int notYetDeletedRow, notYetDeletedCol;
      tie(notYetDeletedRow, notYetDeletedCol) = tempCellBefore4[i];
      grid[notYetDeletedRow][notYetDeletedCol] = '.';
    }
  cout << "Puyo : " << currentPuyo << ' ' << linkedCounter << endl;
  return linkedCounter >= 4;
}

void display(int chainCounter) {
  cout << "chain : " << chainCounter << endl;
  for (int r=0; r<12; r++) {
    for (int c=0; c<6; c++)
      cout << grid[r][c] << ' ';
    cout << endl;
  }
}