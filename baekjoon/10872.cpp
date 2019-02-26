// 팩토리얼
// https://www.acmicpc.net/problem/10872
#include<iostream>
using namespace std;

int main() {
  int N, one=0, five=0, t; cin >> N;
  for(int i=1; i<=N; i++) {
    t=i; while(!(t%2)) { one++; t/=2; }
    while(!(t%5)) { five++; t/=5; }
  }
  cout << (one < five ? one : five);
  return 0;
}