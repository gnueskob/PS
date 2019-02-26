// OX퀴즈
// https://www.acmicpc.net/problem/8958
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int T, size, seq, sum;
  cin >> T;
  string res;
  while(T--) {
    sum = 0, seq = 0;
    cin >> res;
    size = res.length();
    for(int i=0; i<size; i++) {
      if(res.at(i) == 'O') { seq++; sum += seq; }
      else seq=0;
    }
    cout << sum << '\n';
  }
  return 0;
}