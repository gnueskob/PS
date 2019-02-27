// 택시 기하학
// https://www.acmicpc.net/problem/3053
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  const double PI = acos(-1); // 3.141592653589793;
  int r; cin >> r;
  cout << fixed << setprecision(6) << r*r*PI << '\n';
  cout << r*r*2. << '\n';
  return 0;
}