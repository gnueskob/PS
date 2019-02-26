// 부녀회장이 될테야
// https://www.acmicpc.net/problem/2775
#include<iostream>
using namespace std;
int pop[15];
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, k, n; cin >> T;
  while(T--) {
    cin >> k >> n;
    pop[0] = 0;
    for(int i=1; i<=n; i++) pop[i] = pop[i-1] + i;
    for(int i=1; i<k; i++) for(int j=2; j<=n; j++) pop[j] += pop[j-1];
    cout << pop[n] << '\n';
  }
  return 0;
}