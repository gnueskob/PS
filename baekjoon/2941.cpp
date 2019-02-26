// 크로아티아 알파벳
// https://www.acmicpc.net/problem/2941
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string str; cin >> str;
  int len = str.size(), ans=0;
  char next, nnext;
  for(int i=0; i<len; i++) {
    ans++;
    next = i<len-1 ? str.at(i+1) : 0;
    nnext = i<len-2 ? str.at(i+2) : 0;
    switch (str.at(i)) {
      case 'c': if(next=='='||next=='-') i++; break;
      case 'd': if(next=='-') i++; else if(next=='z' && nnext=='=') i+=2; break;
      case 'l':
      case 'n': if(next=='j') i++; break;
      case 's':
      case 'z': if(next=='=') i++; break;
      default: break;
    }
  }
  cout << ans;
  return 0;
}