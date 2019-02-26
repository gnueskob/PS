// 소트인사이드
// https://www.acmicpc.net/problem/1427
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int num[10] = {0,}, N; cin >> N;
  while(N) { num[N%10]++; N/=10; }
  for(int i=9; i>=0; i--) while(num[i]--) cout << i;
  return 0;
}