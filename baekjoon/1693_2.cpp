// 트리 색칠하기
// https://www.acmicpc.net/problem/1693
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

inline int readInt() {int a;cin>>a;return a;}

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX = 100002;
vector<int> g[MAX];
int cache[MAX]={(int)1e9,}, best[MAX], dp[MAX], delta[MAX];

void dfs(int u, int p) {
  int subsz = 0;
  for(int v:g[u]) if(v!=p) dfs(v,u), subsz++;

  if(!subsz) {
    best[u] = dp[u] = delta[u] = 1;
    return;
  }

  int sum = 0;
  for(int i=1; i<=subsz+2; i++) cache[i] = i;
  for(int v:g[u]) if(v!=p) {
    sum += dp[v];
    cache[best[v]] += delta[v];
  }

  int f=0, s=0;
  for(int i=1; i<=subsz+2; i++) {
    if(cache[s] > cache[i]) s = i;
    if(cache[f] > cache[s]) swap(f,s);
  }
  best[u] = f;
  dp[u] = cache[f] + sum;
  delta[u] = cache[s] - cache[f];
  return;
}

int main(){
  int n = readInt();
  while(--n) {
    int a = readInt(), b = readInt();
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,1);
  printf("%d",dp[1]);
}
