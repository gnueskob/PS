// 헨리
// https://www.acmicpc.net/problem/10253
#include<iostream>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T; ll a, b, x; cin >> T;
  while(T--) {
    cin >> a >> b;
    while(a) {
      x = b%a ? b/a + 1 : b/a;
      a *= x, a -= b, b *= x;
    }
    cout << x << '\n';
  }
  return 0;
}