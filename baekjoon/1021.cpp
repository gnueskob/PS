// 회전하는 큐
// https://www.acmicpc.net/problem/1021
#include<iostream>
#include<cmath>
using namespace std;

int num[50];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for(int i=0; i<50; i++) num[i] = i+1;
  int N, M, n, idx=0, ans=0; cin >> N >> M;
  while(M--) {
    cin >> n;
    if(num[idx] != n)
      for(int i=1; i<N; i++) {
        if(num[(idx+i)%N] == n) { ans+=i; idx=(idx+i)%N; break; }
        if(num[(idx-i+N)%N] == n) { ans+=i; idx=(idx-i+N)%N; break; }
      }
    for(int i=idx; i<N-1; i++) num[i] = num[i+1]; N--; if(idx==N) idx=0;
  }
  cout << ans;
  return 0;
}