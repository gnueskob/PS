// A/B
// https://www.acmicpc.net/problem/1008
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/1008.txt", "r", stdin);
  double a, b;
  cin >> a >> b;
  cout.setf(ios::fixed); cout.precision(10);
  cout << a/b;
  return 0;
}