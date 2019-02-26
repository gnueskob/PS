// 별 찍기 - 3
// https://www.acmicpc.net/problem/2440
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/2438.txt", "r", stdin);
  int N;
  cin >> N;
  for(int i=N; i>=1; i--) {
    for(int j=0; j<i; j++) cout << '*';
    cout << '\n';
  }
  return 0;
}