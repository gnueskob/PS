// 열 개씩 끊어 출력하기
// https://www.acmicpc.net/problem/11721
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/11720.txt", "r", stdin);
  string str;
  cin >> str;
  int len = str.size();
  for(int i=0; i<len; i+=10) cout << str.substr(i, 10) << '\n';
  return 0;
}