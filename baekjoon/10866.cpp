// 덱
// https://www.acmicpc.net/problem/10866
#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  deque<int> dq;
  string str; char c;
  int N, n; cin >> N;
  while(N--) {
    cin >> str;
    c = str.at(1);
    if(c == 'i') cout << dq.size() << '\n';
    else if(c == 'm') cout << dq.empty() << '\n';
    else if(c == 'r')
      if(dq.empty()) cout << -1 << '\n';
      else cout << dq.front() << '\n';
    else if(c == 'a')
      if(dq.empty()) cout << -1 << '\n';
      else cout << dq.back() << '\n';
    else if((c=str.at(5)) == 'f') { cin >> n; dq.push_front(n); }
    else if(c == 'b') { cin >> n; dq.push_back(n); }
    else if(c == 'r') {
      if(dq.empty()) cout << -1 << '\n';
      else { cout << dq.front() << '\n'; dq.pop_front(); }
    } else {
      if(dq.empty()) cout << -1 << '\n';
      else { cout << dq.back() << '\n'; dq.pop_back(); }
    }
  }
  return 0;
}