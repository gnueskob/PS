// 바이러스
// https://www.acmicpc.net/problem/2606
#include<cstdio>
#include<vector>
using namespace std;

int main() {
  int n, m, front(0), back(0), ans(0);
  bool visit[101]{};
  char q[100];
  vector<char> com[101];
  scanf("%d%d",&n,&m);
  while(m--) {
    int s, t;
    scanf("%d%d",&s,&t);
    com[s].emplace_back(t);
    com[t].emplace_back(s);
  }
  q[back++] = 1;
  visit[1] = true;
  while(front != back) {
    int s = q[front++];
    for(auto t:com[s]) if(!visit[t]) {
      visit[t] = true;
      ans++;
      q[back++] = t;
    }
  }
  printf("%d",ans);
  return 0;
}