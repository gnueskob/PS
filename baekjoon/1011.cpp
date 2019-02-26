// Fly me to the Alpha Centauri
// https://www.acmicpc.net/problem/1011
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, s, t, idx; cin >> T;
  long long n;
  while(T--) {
    cin >> s >> t;
    t -= s, n = 0;
    while(++n) if(n*n >= t) break;
    if(n*(n-1) >= t) { n--; cout << 2*n << '\n'; }
    else { cout << 2*n-1 << '\n'; }
  }
  return 0;
}