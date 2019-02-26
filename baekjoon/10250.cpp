// ACM 호텔
// https://www.acmicpc.net/problem/10250
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, W, H, n; cin >> T;
  cout.fill('0');
  while(T--) {
    cout.width(1);
    cin >> H >> W >> n;
    cout << (n%H == 0 ? H : n%H);
    cout.width(2);
    cout << (n-1)/H + 1 << '\n';
  }
  return 0;
}