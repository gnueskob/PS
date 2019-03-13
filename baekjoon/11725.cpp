// 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
#include<bits/stdc++.h>
using namespace std;

inline int readInt() {int a;cin>>a;return a;}
inline void writeChar(char x) {cout<<x;}
template <typename T> inline
void writeInt(T x,char e) {if(x<0)writeChar(45),x=-x;char s[24]{};int l=0;while(x||!l)s[l++]=x%10,x/=10;while(l--)writeChar(s[l]+48);if(e)writeChar(e);}

int p[100001];
stack<pair<int, int>> stk, stk2;

void update(int n1, int n2, stack<pair<int, int>>& _stk) {
  if(n1 == 1) p[n2] = 1;
  else if(n2 == 1) p[n1] = 1;
  else if(p[n1]) p[n2] = n1;
  else if(p[n2]) p[n1] = n2;
  else _stk.push({n1, n2});
}

int main() {
  int N = readInt();

  for(int i=0; i<N-1; i++) {
    int n1 = readInt(), n2 = readInt();
    update(n1, n2, stk);
  }
  while(!stk.empty() || !stk2.empty()) {
    while(!stk.empty()) {
      int n1, n2;
      tie(n1, n2) = stk.top(); stk.pop();
      update(n1, n2, stk2);
    }
    while(!stk2.empty()) {
      int n1, n2;
      tie(n1, n2) = stk2.top(); stk2.pop();
      update(n1, n2, stk);
    }
  }

  for(int i=2; i<=N; i++) writeInt(p[i],'\n');
  return 0;
}