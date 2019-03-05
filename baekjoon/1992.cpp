// 쿼드트리
// https://www.acmicpc.net/problem/1992
#include<bits/stdc++.h>
using namespace std;

bool grid[64][64];

void compress(int n, int r, int c) {
  if(n==1) { cout << grid[r][c]; return; }
  bool cell = grid[r][c], same = true;
  for(int i=r; i<r+n; i++) for(int j=c; j<c+n; j++)
    if(cell != grid[i][j]) {
      int h = n/2;
      cout << '(';
      compress(h, r, c);
      compress(h, r, c+h);
      compress(h, r+h, c);
      compress(h, r+h, c+h);
      cout << ')';
      return;
    }
  cout << cell;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t, n, i=0; string str;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> str;
    for(int j=0; j<str.size(); j++)
      grid[i][j] = str.at(j) - 48;
  }

  compress(n, 0, 0);
  return 0;
}