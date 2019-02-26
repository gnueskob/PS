// 문자열 반복
// https://www.acmicpc.net/problem/2675
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, R, size; cin >> T;
  string str;
  while(T--) {
    cin >> R;
    cin >> str;
    size = str.length();
    for(int i=0; i<size; i++) for(int j=0; j<R; j++) cout << str.at(i);
    cout << '\n';
  }
  return 0;
}