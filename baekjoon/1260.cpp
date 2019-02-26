// DFS와 BFS
// https://www.acmicpc.net/problem/1260
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1000;
bool visit[MAXN];
vector<vector<int>> g;

void dfs(int v) {
  cout << v+1 << ' ';
  for(int it: g[v]) if(!visit[it]) { visit[it] = true; dfs(it); }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, V, s, t; cin >> N >> M >> V; V--;
  g.resize(N);
  for(int i=0; i<M; i++) {
    cin >> s >> t; s--, t--;
    g[s].push_back(t);
    g[t].push_back(s);
  }
  for(int i=0; i<N; i++) sort(g[i].begin(), g[i].end());
  visit[V] = true;
  dfs(V);

  cout << '\n';
  memset(visit, 0, sizeof(visit));

  queue<int> q;
  q.push(V); visit[V] = true;
  while(!q.empty()) {
    int v = q.front(); q.pop();
    cout << v+1 << ' ';
    for(int it: g[v]) if(!visit[it]) { q.push(it); visit[it] = true; }
  }
  return 0;
}