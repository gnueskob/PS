// 피보나치 수
// https://www.acmicpc.net/problem/2747
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, p=1, pp=0, ans=0; cin >> n;
  if(n==1) ans=1;
  else for(int i=2; i<=n; i++) ans=pp+p, pp=p, p=ans;
  cout << ans;
  return 0;
}