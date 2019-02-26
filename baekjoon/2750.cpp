// 수 정렬하기
// https://www.acmicpc.net/problem/2750
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  const int MAXN = 1000;
  bool num[2*MAXN+1] = {0,};
  int n, in; cin >> n;
  for(int i=0; i<n; i++) { cin >> in; num[in+MAXN] = true; }
  for(int i=0; i<2*MAXN+1; i++) if(num[i]) cout << i-MAXN << '\n';
  return 0;
}