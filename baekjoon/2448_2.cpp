// 별 찍기 - 11
// https://www.acmicpc.net/problem/2448
#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 3 << 11;
const int MAXH = 3 << 10;
char star[MAXH*(MAX+1)];
int N, w;

void drawCanvas(int N) {
  memset(star,' ', N*(w+1));
  for(int h=0; h<N; h++) *(star + h*(w+1) + w) = '\n';
}
void drawTriangle(int r, int c, int h) {
  if(h==3) {
    *(star + (r-1)*(w+1) + c) = '*';
    *(star + r*(w+1) + c-1) = '*';
    *(star + r*(w+1) + c+1) = '*';
    memset(star + (r+1)*(w+1) + c-2, '*', 5);
    return;
  }
  drawTriangle(r-(h>6?h/4:2), c, h/2);
  drawTriangle(r+h/4, c - h/2, h/2);
  drawTriangle(r+h/4, c + h/2, h/2);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N; w = 2*N - 1;
  drawCanvas(N);
  drawTriangle(N/2, w/2, N);
  cout << star;
  return 0;
}