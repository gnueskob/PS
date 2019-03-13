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
int dist[100001];

int bfs(int s) {
  fill(dist, dist+N+1, -1);
  queue<int> q;
  dist[s] = 0, q.push(s);
  while(!q.empty()) {
    int n = q.front(); q.pop();
    for(int i=node[n].size(); i--;) {
      int t = node[n][i].I, w = node[n][i].W;
      if(dist[t] > -1) continue;
      dist[t] = dist[n] + w;
      q.push(t);
    }
  }
  int res = 1;
  for(int i=2; i<=N; i++) res = dist[res] < dist[i] ? i : res;
  return res;
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
  resetBuf();
  int u = bfs(1);
  int v = bfs(u);
  printf("%d",dist[v]);
  return 0;
}