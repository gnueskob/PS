// 동전 1
// https://www.acmicpc.net/problem/2293
#include<iostream>
using namespace std;

int coin[100], value[10001] = {1,};

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, k; cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> coin[i];
    for(int j=coin[i]; j<=k; j++)
      value[j] += value[j-coin[i]];
  }
  cout << value[k];
  return 0;
}