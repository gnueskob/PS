// 이항 계수 2
// https://www.acmicpc.net/problem/11051
#include<iostream>
using namespace std;

const int mod = 10007;
int dp[1001];
// int com[1001][1001];

// int getCom(int n, int k) {
//   if(k==0 || n==k) return 1;
//   else if(com[n][k]) return com[n][k];
//   int sum = getCom(n-1,k-1) + getCom(n-1,k);
//   if(sum >= mod) sum %= mod;
//   com[n][k] = sum;
//   return sum;
// }

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, K, ans=1; cin >> N >> K;
  // cout << getCom(N, K);
  if(K==0 || N==K) { cout << 1; return 0; }
  else if(K==1 || N-K==1) { cout << N; return 0; }
  dp[0] = 1;
  for(int i=1; i<=N; i++)
    for(int j=i/2; j>=1; j--)
      if(!(i&1) && j==i/2) dp[j] = (2*dp[j-1])%mod;
      else dp[j] = (dp[j-1] + dp[j])%mod;
  if(K>N/2) K = N-K;
  cout << dp[K];
  return 0;
}