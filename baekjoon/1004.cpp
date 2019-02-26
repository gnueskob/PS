// 어린 왕자
// https://www.acmicpc.net/problem/1004
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("./input/1004.txt", "r", stdin);
  int T, n, sx, sy, ax, ay, cx, cy, r, ans;
  bool s, a;
  cin >> T;
  while(T--) {
    ans = 0;
    cin >> sx >> sy >> ax >> ay >> n;
    while(n--) {
      cin >> cx >> cy >> r;
      s = (cx-sx)*(cx-sx) + (cy-sy)*(cy-sy) < r*r ? true : false;
      a = (cx-ax)*(cx-ax) + (cy-ay)*(cy-ay) < r*r ? true : false;
      if (s^a) ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}