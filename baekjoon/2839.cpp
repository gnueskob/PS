// 설탕 배달
// https://www.acmicpc.net/problem/2839
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/2839.txt", "r", stdin);
  int N, mod, b=0, s=0;
  cin >> N;
  b += N/5; mod = N%5;
  while(true) {
    if(mod%3==0) { cout << b+mod/3; return 0; }
    else { b--; mod += 5; }
    if(b<0) { cout << -1; return 0; }
  }
  return 0;
}