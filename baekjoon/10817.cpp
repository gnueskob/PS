// 세 수
// https://www.acmicpc.net/problem/10817
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/10817.txt", "r", stdin);
  int n[3]; cin >> n[0] >> n[1] >> n[2];
  sort(n, n+3);
  cout << n[1];
  return 0;
}