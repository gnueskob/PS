// 합
// https://www.acmicpc.net/problem/8393
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/8393.txt", "r", stdin);
  int N;
  cin >> N;
  cout << N*(N+1)/2;
  return 0;
}