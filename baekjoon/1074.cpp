// Z
// https://www.acmicpc.net/problem/1074
#include<bits/stdc++.h>
using namespace std;

int ans, r, c;
int dr[]={0,0,1,1}, dc[]={0,1,0,1};

void solve(int row, int col, int size) {
  if(size == 1) { printf("%d",ans); return; }
  int s = size/2;
  if(r < row + s && c < col + s) solve(row,col,s);
  else ans += s*s;
  if(r < row + s && c >= col + s) solve(row,col+s,s);
  else ans += s*s;
  if(r >= row + s && c < col + s) solve(row+s,col,s);
  else ans += s*s;
  if(r >= row + s && c >= col + s) solve(row+s,col+s,s);
  else ans += s*s;
}

int main() {
  int N; scanf("%d%d%d",&N,&r,&c);
  int size = 1<<N;
  solve(0,0,size);
  return 0;
}