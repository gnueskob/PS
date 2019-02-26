// 쉬운 계단 수
// https://www.acmicpc.net/problem/10844
#include<iostream>
using namespace std;

const int mod = 1e9;
int p[10], n[10];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N; cin >> N;
  for(int j=1; j<10; j++) n[j] = 1;
  for(int i=1; i<N; i++) {
    for(int j=0; j<10; j++) p[j] = n[j], n[j] = 0;
    n[0] = p[1], n[9] = p[8];
    for(int j=1; j<9; j++) n[j] = (p[j-1] + p[j+1]) % mod;
  }
  int sum = 0;
  for(int j=0; j<10; j++) sum += n[j], sum %= mod;
  cout << sum;
  return 0;
}