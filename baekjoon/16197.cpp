// 두 동전
// https://www.acmicpc.net/problem/16197
#include<iostream>
#include<tuple>
#include<queue>
using namespace std;

char board[20][20];
int n, m, ans = -1;
typedef tuple<int, int, int, int, int> t5;
queue<t5> bfs;

bool isVaildCell(int r1, int c1, int r2, int c2, int ud, int lr, int cnt);

int main() {
  freopen("./input/16197.txt", "r", stdin);

  cin >> n;
  if(cin.eof()) return 0;
  cin >> m;

  int coinCnt = 0;
  int r1, r2, c1, c2;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      char c;
      while((c = cin.get()) == ' ' || c == '\n');
      board[i][j] = c;
      if (c == 'o')
        if (coinCnt == 0) { r1 = i; c1 = j; coinCnt++; }
        else { r2 = i; c2 = j; }
    }
  }

  t5 coinPos = make_tuple(r1, c1, r2, c2, 0);
  bfs.push(coinPos);

  int cnt;
  while(!bfs.empty()) {
    bool coin1 = false, coin2 = false;
    t5 currentCoinPos = bfs.front();
    bfs.pop();
    r1 = get<0>(currentCoinPos);
    c1 = get<1>(currentCoinPos);
    r2 = get<2>(currentCoinPos);
    c2 = get<3>(currentCoinPos);
    cnt = get<4>(currentCoinPos);

    cnt++;
    if (cnt > 10) break;
    if (isVaildCell(r1, c1, r2, c2, -1, 0, cnt) // UP
      || isVaildCell(r1, c1, r2, c2, 1, 0, cnt) // DOWN
      || isVaildCell(r1, c1, r2, c2, 0, -1, cnt) // LEFT
      || isVaildCell(r1, c1, r2, c2, 0, 1, cnt)) // RIGHT
      break;
  }

  cout << ans;
  return 0;
}

bool isVaildCell(int r1, int c1, int r2, int c2, int ud, int lr, int cnt) {
  bool coin1 = false, coin2 = false;
  if (c1 + lr >= m || c1 + lr < 0) coin1 = true;
  else if (board[r1][c1 + lr] != '#') c1 = c1 + lr;
  if (c2 + lr >= m || c2 + lr < 0) coin2 = true;
  else if (board[r2][c2 + lr] != '#') c2 = c2 + lr;

  if (r1 + ud >= n || r1 + ud < 0) coin1 = true;
  else if (board[r1 + ud][c1] != '#') r1 = r1 + ud;
  if (r2 + ud >= n || r2 + ud < 0) coin2 = true;
  else if (board[r2 + ud][c2] != '#') r2 = r2 + ud;

  if (coin1 ^ coin2) {
    ans = cnt;
    return true;
  } else if (!coin1 && !coin2)
    bfs.push(make_tuple(r1, c1, r2, c2, cnt));

  return false;
}