// 찍기 N
// https://www.acmicpc.net/problem/2742
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("./input/2741.txt", "r", stdin);
  int N;
  cin >> N;
  for(int i=N; i>0; i++) cout << i << '\n';
  return 0;
}