// 피보나치 함수
// https://www.acmicpc.net/problem/1003
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("./input/1003.txt", "r", stdin);
  int T, n, ppz, ppo, pz, po, ansZ, ansO;
  cin >> T;
  while(T--) {
    ppz=1, ppo=0, pz=0, po=1;
    cin >> n;
    if (n==0) { cout << "1 0\n"; continue; }
    else if (n==1) { cout << "0 1\n"; continue; }
    for (int i=2; i<=n; i++) {
      ansZ = ppz + pz;
      ppz = pz;
      pz = ansZ;
      ansO = ppo + po;
      ppo = po;
      po = ansO;
    }
    cout << ansZ << ' ' << ansO << '\n';
  }
  return 0;
}