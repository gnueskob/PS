// 포도주 시식
// https://www.acmicpc.net/problem/2156
#include<iostream>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, v, pf, f, s;
  cin >> n;
  pf = f = s = 0;
  for(int i=0; i<n; i++) {
    cin >> v;
    int t = pf; pf = max(pf, max(f,s));
    s = f + v;
    f = t + v;
  }
  cout << max(pf, max(f, s));
  return 0;
}