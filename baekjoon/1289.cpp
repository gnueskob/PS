// 트리의 가중치
// https://www.acmicpc.net/problem/1289
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
int d[100'001];
ll cost;
const ll MOD = 1'000'000'007;

void dfs(int s, int p) {
  ll stSum = 0, stSub = 0;
  for(auto& e:adj[s]) if(e.T^p) {
    dfs(e.T,s);
    ll el = (ll)(d[e.T] + 1)*e.W % MOD;
    stSum += el, stSum %= MOD;
    stSub += el*el % MOD, stSub %= MOD;
  }
  ll deltaCost = (stSum*stSum - stSub) % MOD;
  if(deltaCost&1) deltaCost += MOD;
  d[s] = stSum;
  cost += deltaCost/2 + d[s], cost %= MOD;
}

int main() {
  int n = readInt();
  while(--n) {
    int s = readInt(), t = readInt(), w = readInt();
    adj[s].push_back({t,w});
    adj[t].push_back({s,w});
  }
  dfs(1,1);
  printf("%lld",cost);
  return 0;
}