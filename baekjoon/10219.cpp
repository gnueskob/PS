// Meats On The Grill
// https://www.acmicpc.net/problem/10219
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, H, W; cin >> T;
  char grid[12];
  while(T--) {
    cin >> H >> W;
    while(H--) {
      cin >> grid;
      for(int i=W-1; i>=0; i--) cout << grid[i];
      cout << '\n';
    }
  }
  return 0;
}