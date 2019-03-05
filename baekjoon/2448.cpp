// 별 찍기 - 11
// https://www.acmicpc.net/problem/2448
#include<iostream>
#include<sstream>
using namespace std;
const int MAX = 3 << 11;
const int MAXH = 3 << 10;
char star[MAXH][MAX];

void drawTriangle(int N) {
  int width = 2*N-1;
  for(int h=N; h>0; h--)
  for(int h=N; h>0; h--)
    for(int i=0; i<width; i++)
      if(N-h<=i && i<width-N+h) star[h-1][i] = '*';
      else star[h-1][i] = ' ';
}
void makeEmpty(int r, int c, int h) {
  if(h==3) { star[r+1][c] = ' '; return; }
  int width = h-1, pad = 0, delLen = width;
  for(int height=r+h/2;;height++) {
    if(delLen < 1) break;
    int del = c - width/2 + pad++;
    for(int i=del; i<del+delLen; i++) star[height][i] = ' ';
    delLen -= 2;
  }
  makeEmpty(r, c, h/2);
  makeEmpty(r+h/2, c - width/2 - 1, h/2);
  makeEmpty(r+h/2, c + width/2 + 1, h/2);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/2448.txt", "r", stdin);
  int N; cin >> N;
  drawTriangle(N);
  makeEmpty(0, N-1, N);
  stringstream ss;
  for(int i=0; i<N; i++) { for(int j=0; j<2*N-1; j++) ss << star[i][j]; cout << ss.str() << '\n'; ss.clear(); ss.str(""); }
  return 0;
}