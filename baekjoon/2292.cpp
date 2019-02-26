// 벌집
// https://www.acmicpc.net/problem/2292
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, path=0, last=1; cin >> n;
  while(++path) {
    if(n <= (path-1)*6 + last) break;
    last += (path-1)*6;
  }
  cout << path;
  return 0;
}