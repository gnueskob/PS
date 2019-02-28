// 토너먼트
// https://www.acmicpc.net/problem/1057
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, a, b, idx=0, r=1;
  cin >> n >> a >> b;
  if(a>b) a^=b, b^=a, a^=b;
  while(n-1) {
    if(a+1 == b && b%2 == 0) break;
    a = (a+1)/2, b = (b+1)/2;
    r++, n = (2*n-1)/2;
  }
  if(n==1) r = -1;
  cout << r;
  return 0;
}