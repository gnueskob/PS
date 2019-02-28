// 지능형 기차
// https://www.acmicpc.net/problem/2455
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int max = 0, d, c = 0;
  for(int i=0; i<4; i++) {
    cin >> d; c -= d;
    cin >> d; c += d;
    max = max > c ? max : c;
  }
  cout << max;
  return 0;
}