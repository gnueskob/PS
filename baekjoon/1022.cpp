// 소용돌이 예쁘게 출력하기
// https://www.acmicpc.net/problem/1022
#include<iostream>
#include<iomanip>
using namespace std;
#define abs(a) (a<0?-a:a)
#define max(a,b) (a>b?a:b)

int getCell(int r, int c) {
  int m = max(abs(r),abs(c)), ans;
  int ex = (2*m+1)*(2*m+1);
  if(r == m) { ans = ex - (m - c); }
  else if(c == -m) { ans = ex - 2*m - (m - r); }
  else if(r == -m) { ans = ex - 4*m - (c + m); }
  else { ans = ex - 6*m - (r + m); }
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int m = max(getCell(r1,c1), max(getCell(r1,c2), max(getCell(r2,c1), getCell(r2,c2))));
  int len = 0;
  while(m) { len++; m/=10; }
  for(int r=r1; r<=r2; r++) {
    for(int c=c1; c<=c2; c++)
      cout << setw(len) << getCell(r,c) << ' ';
    cout << '\n';
  }
  return 0;
}