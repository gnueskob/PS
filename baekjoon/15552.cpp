// 빠른 A+B
// https://www.acmicpc.net/problem/15552
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/15552.txt", "r", stdin);
  int T, a, b;
  cin >> T;
  while(T--) {
    cin >> a >> b;
    cout << a+b << '\n';
  }
  return 0;
}