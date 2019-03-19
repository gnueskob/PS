#include<cstdio>
char p[101];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }
int main() {
  int n, m, i, u, v, ans=0;
  scanf("%d%d",&n,&m);
  for(i=1; i<=n; i++) p[i] = i;
  for(i=0; i<m; i++) scanf("%d%d",&u,&v), p[f(u)] = f(v);
  for(i=2; i<=n; i++) ans += f(1)==f(i);
  printf("%d",ans);
  return 0;
}