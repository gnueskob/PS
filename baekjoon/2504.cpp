// 괄호의 값
// https://www.acmicpc.net/problem/2504
#include<iostream>
#include<string>
#include<stack>
#include<utility>
using namespace std;

const int MUL = 0, ADD = 1;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s;
  int len, ans=0, t;
  stack<pair<int, int>> st;
  pair<int, int> top;
  cin >> s;
  len = s.size();
  for(int i=0; i<len; i++) {
    char c = s.at(i); t=0;
    if(c=='(') st.push({2,MUL});
    else if(c=='[') st.push({3,MUL});
    else while(true) {
      if(st.empty()) { cout << 0; return 0; }
      top = st.top();
      if(top.second == ADD) { t += top.first; st.pop(); }
      else if(top.second == MUL) {
        if((c==')' && top.first != 2)
        || (c==']' && top.first != 3)) { cout << 0; return 0; }
        t *= top.first; st.pop();
        st.push({t?t:top.first, ADD});
        break;
      }
    }
  }
  while(!st.empty()) {
    if(st.top().second == MUL) { cout << 0; return 0; }
    ans += st.top().first; st.pop();
  }
  cout << ans;
  return 0;
}