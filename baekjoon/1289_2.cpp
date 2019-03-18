#include<vector>
#include<utility>
#include<cstdio>
using namespace std;

inline int readInt() {int a;scanf("%d",&a);return a;}

#define T first
#define W second
using graph = vector<pair<int,int>>;
using ll = long long;

graph adj[100'001];
ll cost;
const ll MOD = 1'000'000'007;

ll dfs(int s, int p) {
  ll t, st = 1;
  for(auto& e:adj[s]) if(e.T^p) {
    t = (dfs(e.T,s)*e.W) % MOD;
    cost += t*st, cost %= MOD;
    st += t, st %= MOD;
  }
  return st;
}

int main() {
  int n = readInt();
  while(--n) {
    int s = readInt(), t = readInt(), w = readInt();
    adj[s].push_back({t,w});
    adj[t].push_back({s,w});
  }
  dfs(1,0);
  printf("%lld",cost);
  return 0;
}