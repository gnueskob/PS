// 큐
// https://www.acmicpc.net/problem/10845
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  queue<int> q;
  int N, len, X; string cmd;
  cin >> N;
  while(N--) {
    cin >> cmd;
    len = cmd.size();
    if(len == 3)
      if(q.empty()) { cout << -1 << '\n'; }
      else { cout << q.front() << '\n'; q.pop(); }
    else if(len == 4)
      if(cmd.at(0) == 'p') { cin >> X; q.push(X); }
      else if(cmd.at(0) == 's') { cout << q.size() << '\n'; }
      else if(q.empty()) { cout << -1 << '\n'; }
      else { cout << q.back() << '\n'; }
    else {
      if(cmd.at(0) == 'e') {
        if(q.empty()) cout << 1 << '\n';
        else cout << 0 << '\n';
      } else if(q.empty()) { cout << -1 << '\n'; }
      else { cout << q.front() << '\n'; }
    }
  }
  return 0;
}