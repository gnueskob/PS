// 분수찾기
// https://www.acmicpc.net/problem/1193
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, lv=1; cin >> n;
  while(true)
    if(n > lv*(lv+1)/2) lv++;
    else break;
  int diff = lv*(lv+1)/2 - n;
  if(lv&1) cout << 1+diff << '/' << lv-diff;
  else cout << lv-diff << '/' << 1+diff;
  return 0;
}