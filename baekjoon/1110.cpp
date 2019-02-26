// 더하기 사이클
// https://www.acmicpc.net/problem/1110
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/1110.txt", "r", stdin);
  int N, a, b, newN, cnt=0; cin >> N;
  newN = N;
  do {
    a = newN/10; b = newN%10;
    newN = 10*b + (a+b)%10;
    cnt++;
  } while(newN != N);
  cout << cnt;
  return 0;
}