// 그대로 출력하기 2
// https://www.acmicpc.net/problem/11719
#include<iostream>
#include<string>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  freopen("./input/11719.txt", "r", stdin);
  string s;
  while(!cin.eof()){
    getline(cin, s);
    cout << s << '\n';
  }
}