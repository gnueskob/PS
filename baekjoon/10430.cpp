// 나머지
// https://www.acmicpc.net/problem/10430
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("./input/10430.txt", "r", stdin);
  int a,b,c;
  cin >> a >> b >> c;
  cout << (a+b)%c << '\n' << (a%c+b%c)%c << '\n' << (a*b)%c << '\n' << (a%c*b%c)%c;
  return 0;
}