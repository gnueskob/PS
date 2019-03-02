// 수열의 합
// https://www.acmicpc.net/problem/1024
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, L, s, t; cin >> N >> L;
  for(int len=L; len<101; len++) {
    int sum = N/len*len + (len%2 == 0 ? len/2 : 0);
    s = N/len - len/2 + !(len%2);
    if(s >= 0 && sum == N) {
      for(int i=s; i-s<len; i++) cout << i << ' ';
      return 0;
    }
  }
  cout << -1;
  return 0;
}