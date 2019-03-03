// 종이의 개수
// https://www.acmicpc.net/problem/1780
#include<bits/stdc++.h>
using namespace std;

char grid[2187][2187];
int n[3];

inline int readInt() { int a; scanf("%d",&a); return a; }

void divide(int size, int r, int c) {
  if(size == 1) { n[grid[r][c]+1]++; return; }
  int cell = grid[r][c];
  for(int i=r; i<r+size; i++) for(int j=c; j<c+size; j++)
    if(cell != grid[i][j]) {
      for(int dr=r; dr<r+size; dr+=size/3) for(int dc=c; dc<c+size; dc+=size/3)
        divide(size/3, dr, dc);
      return;
    }
  n[cell+1]++;
}

int main() {
  int N = readInt();
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) grid[i][j] = readInt();
  divide(N, 0, 0);
  printf("%d\n%d\n%d",n[0],n[1],n[2]);
  return 0;
}