// 사칙연산
// https://www.acmicpc.net/problem/10869
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  freopen("./input/10869.txt", "r", stdin);
  int a, b;
  cin >> a >> b;
  cout << a+b << '\n' << a-b << '\n' << a*b << '\n' << a/b << '\n' << a%b;
  return 0;
}