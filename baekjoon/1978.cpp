// 소수 찾기
// https://www.acmicpc.net/problem/1978
#include<iostream>
using namespace std;

int num[100];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, ans; cin >> N;
  for(int i=0; i<N; i++) { cin >> num[i]; if(num[i]==1) N--, i--;  }
  ans=N;
  for(int i=0; i<N; i++)
    for(int j=2; j*j<=num[i]; j++)
      if(num[i]%j == 0) { ans--; break; }
  cout << ans;
  return 0;
}