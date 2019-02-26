// 단어의 개수
// https://www.acmicpc.net/problem/1152
#include<iostream>
#include<sstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/1152.txt", "r", stdin);

  string str;
  stringstream ss;
  getline(cin, str);
  ss.str(str);
  string a;
  int ans = 0;
  while(ss >> a) ans++;
  cout << ans;
  return 0;
}