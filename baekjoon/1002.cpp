// 터렛
// https://www.acmicpc.net/problem/1002
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/1002.txt", "r", stdin);
  int T, x[2], y[2], r[2], tr, tr2, td;
  cin >> T;
  while(T--) {
    cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];
    tr = (r[0]+r[1])*(r[0]+r[1]);
    tr2 = (r[0]-r[1])*(r[0]-r[1]);
    td = (x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]);
    if (td == 0 && tr2 == 0) { cout << "-1\n"; }
    else if (tr < td || tr2 > td) { cout << "0\n"; }
    else if (tr == td || tr2 == td) { cout << "1\n"; }
    else { cout << "2\n"; }
  }
  return 0;
}