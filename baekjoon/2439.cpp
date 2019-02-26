// 별 찍기 - 2
// https://www.acmicpc.net/problem/2439
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/2438.txt", "r", stdin);
  int N;
  cin >> N;
  for(int i=1; i<=N; i++) {
    for(int j=N; j>=1; j--) {
      if(j<=i) cout << '*';
      else cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}