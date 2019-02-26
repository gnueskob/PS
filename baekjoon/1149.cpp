// RGB거리
// https://www.acmicpc.net/problem/1149
#include<iostream>
using namespace std;
inline int min(int a, int b) { return a > b ? b : a; }

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, R, G, B, r=0, g=0, b=0; cin >> T;
  for(int i=0; i<T; i++) {
    cin >> R >> G >> B;
    R += min(g,b), G += min(r,b), B += min(r,g);
    r = R, g = G, b = B;
  }
  cout << min(r,min(g,b));
  return 0;
}