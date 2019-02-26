// 스택
// https://www.acmicpc.net/problem/10828
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  stack<int> st;
  int N, len, X; string cmd;
  cin >> N;
  while(N--) {
    cin >> cmd;
    len = cmd.size();
    if(len == 3)
      if(st.empty()) { cout << -1 << '\n'; }
      else { cout << st.top() << '\n'; if(cmd.at(0) == 'p') st.pop(); }
    else if(len == 4)
      if(cmd.at(0) == 'p') { cin >> X; st.push(X); }
      else { cout << st.size() << '\n'; }
    else if(st.empty()) cout << 1 << '\n';
    else cout << 0 <<'\n';
  }
  return 0;
}