// 평균
// https://www.acmicpc.net/problem/1546
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/1546.txt", "r", stdin);
  int N; double aver = 0.0, p, M;
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> p;
    aver += p;
    M = p > M ? p : M;
  }
  aver *= 100.0/(M*(double)N);
  cout << aver;
  return 0;
}