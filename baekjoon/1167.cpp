// 트리의 지름
// https://www.acmicpc.net/problem/1167
#include<bits/stdc++.h>
using namespace std;

inline int readInt() {int a;cin>>a;return a;}
inline void writeChar(char x) {cout<<x;}
template <typename T> inline
void writeInt(T x,char e) {if(x<0)writeChar(45),x=-x;char s[24]{};int l=0;while(x||!l)s[l++]=x%10,x/=10;while(l--)writeChar(s[l]+48);if(e)writeChar(e);}
void resetBuf() {}

#define I first
#define W second

int N;
vector<pair<int, int>> node[100001];

int maxD, u;
int dfs(int s, int p, int d) {
  for(auto& tw : node[s]) {
    int t = tw.I, w = tw.W;
    if(t != p) dfs(t, s, d+w);
  }
  if(maxD < d) maxD = d, u = s;
}

int main() {
  N = readInt();
  for(int i=0; i<N; i++) {
    int s = readInt();
    while(1) {
      int t = readInt();
      if(t == -1) break;
      int w = readInt();
      node[s].emplace_back(make_pair(t, w));
    }
  }
  dfs(1,1,0);
  dfs(u,u,0);
  printf("%d",maxD);
  return 0;
}