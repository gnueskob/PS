// X보다 작은 수
// www.acmicpc.net/problem/10871
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./input/10871.txt", "r", stdin);
  int num, N, X;
  cin >> N >> X;
  for(int i=0; i<N; i++) {
    cin >> num;
    if(num < X) { cout << num << ' '; }
  }
  return 0;
}