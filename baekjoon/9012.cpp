// 괄호
// https://www.acmicpc.net/problem/9012
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, len, cnt; cin >> T;
  string ps;
  while(T--) {
    cnt = 0;
    cin >> ps;
    len = ps.size();
    for(int i=0; i<len; i++) {
      if(ps.at(i) == '(') cnt++;
      else cnt--;
      if(cnt<0) break;
    }
    if(cnt) cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }
  return 0;
}