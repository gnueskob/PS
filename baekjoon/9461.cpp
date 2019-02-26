// 파도반 수열
// https://www.acmicpc.net/problem/9461
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, n; cin >> T;
  long long p[100] = {1,1,1,2,2,};
  for(int i=5; i<100; i++) p[i] = p[i-1] + p[i-5];
  while(T--) { cin >> n; cout << p[n-1] << '\n'; }
  return 0;
}