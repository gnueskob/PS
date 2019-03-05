// 별 찍기 - 10
// https://www.acmicpc.net/problem/2447
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 2187;
char star[MAX*(MAX+1)];
int N;

void drawCanvas(int N) {
  memset(star,' ', N*(N+1));
  for(int h=0; h<N; h++) *(star + h*(N+1) + N) = '\n';
}
int dr[] = {-1,-1,-1,0,1,1,1,0};
int dc[] = {-1,0,1,1,1,0,-1,-1};
void drawSquare(int r, int c, int h) {
  if(h==1) { *(star + (r)*(N+1) + c) = '*'; return; }
  int d = h/3;
  for(int i=0; i<8; i++) drawSquare(r+d*dr[i], c+d*dc[i], h/3);
}

int main() {
  scanf("%d",&N);
  drawCanvas(N);
  drawSquare(N/2, N/2, N);
  printf("%s",star);
  return 0;
}