// 2007년
// https://www.acmicpc.net/problem/1924
#include<iostream>
using namespace std;
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char str[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/1924.txt", "r", stdin);
  int m, d;
  cin >> m >> d;
  for(int i=0; i<m; i++) d += days[i];
  cout << str[d%7];
  return 0;
}