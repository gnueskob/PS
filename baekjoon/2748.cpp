// 피보나치 수 2
// https://www.acmicpc.net/problem/2748
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  unsigned long long n, p=1, pp=0, ans=0; cin >> n;
  if(n==1) ans=1;
  else for(unsigned long long i=2; i<=n; i++) ans=(pp+p)%1000000, pp=p, p=ans;
  cout << ans;
  return 0;
}