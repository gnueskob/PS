// 검
// https://www.acmicpc.net/problem/2981
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int getGCD(int a, int b) {
  int c;
  while(b) c=a%b, a=b, b=c;
  return a;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, a, b, gcd;
  cin >> N >> a >> b;
  gcd = abs(a-b), N -= 2;
  while(N--) {
    a = b;
    cin >> b;
    gcd = getGCD(gcd, abs(a-b));
  }
  vector<int> d;
  long long i;
  for(i=2; i*i<gcd; i++) if(gcd%i == 0) { cout << i << ' '; d.push_back(gcd/i); }
  if(i*i == gcd) cout << i << ' ';
  for(auto it = d.rbegin(); it != d.rend(); it++) cout << *it << ' ';
  cout << gcd;
  return 0;
}