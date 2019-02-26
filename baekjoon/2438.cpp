// 별 찍기 - 1
// https://www.acmicpc.net/problem/2438
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/2438.txt", "r", stdin);
  int N;
  cin >> N;
  for(int i=1; i<=N; i++) {
    for(int j=0; j<i; j++) cout << '*';
    cout << '\n';
  }
  return 0;
}