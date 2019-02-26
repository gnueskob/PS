// 한수
// https://www.acmicpc.net/problem/1065
#include<iostream>
using namespace std;

bool isValid(int N) {
  if(N<100) return true;
  int mod = N%10; N /= 10;
  int diff = mod - N%10;
  while(N>=10) {
    mod = N%10; N /= 10;
    if(diff != mod - N%10) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, cnt=0; cin >> N;
  for(int i=1; i<=N; i++) if(isValid(i)) cnt++;
  cout << cnt;
  return 0;
}