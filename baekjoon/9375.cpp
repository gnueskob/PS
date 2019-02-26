// 패션왕 신해빈
// https://www.acmicpc.net/problem/9375
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, n, ans=1; cin >> T;
  map<string, int> m;
  string s;
  while(T--) {
    cin >> n;
    ans = 1; m.clear();
    while(n--) {
      cin >> s >> s;
      auto res = m.insert({s, 1});
      if(!res.second) res.first->second++;
    }
    for(auto& it : m) ans *= it.second + 1;
    cout << --ans << '\n';
  }
  return 0;
}