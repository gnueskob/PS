// 소수
// https://www.acmicpc.net/problem/2581
#include<iostream>
using namespace std;

int num[9999];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, n, ans=0, min=0; cin >> M >> N;
  n = N; if(M==1) M++;
  for(int i=0; i<N-M+1; i++) num[i] = n--;
  bool isPrime;
  for(int i=0; i<N-M+1; i++) {
    isPrime = true;
    for(int j=2; j*j<=num[i]; j++)
      if(num[i]%j == 0) { isPrime = false; break; }
    if(isPrime) ans += num[i], min = num[i];
  }
  if(!ans) ans--; cout << ans << '\n';
  if(min) cout << min;
  return 0;
}