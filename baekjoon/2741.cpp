// N 찍기
// https://www.acmicpc.net/problem/2741
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("./input/2741.txt", "r", stdin);
  int N;
  cin >> N;
  for(int i=1; i<=N; i++) cout << i << '\n';
  return 0;
}