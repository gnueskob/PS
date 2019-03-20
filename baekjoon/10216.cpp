// Count Circle Groups
// https://www.acmicpc.net/problem/10216
#include<bits/stdc++.h>
using namespace std;

inline int readInt() {int a;scanf("%d",&a);return a;}

using t3 = tuple<short,short,short>;

bool near(t3& p1, t3& p2) {
  int x1, y1, r1, x2, y2, r2;
  tie(x1,y1,r1) = p1;
  tie(x2,y2,r2) = p2;
  int powdist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  return powdist <= (r1+r2)*(r1+r2);
}

int main() {
  int T = readInt();
  while(T--) {
    int N = readInt(), i, j, ans=0;
    vector<t3> pos;
    pos.reserve(N);
    for(i=0; i<N; i++) {
      short x=readInt(), y=readInt(), r=readInt();
      pos.push_back({x,y,r});
    }
    vector<vector<short>> u(N);
    vector<bool> visit(N,0);
    for(i=0; i<N; i++) for(j=0; j<N; j++) {
      if(i==j) continue;
      if(near(pos[i],pos[j])) {
        u[i].push_back(j);
        u[j].push_back(i);
      }
    }
    for(int i=0; i<N; i++) {
      if(visit[i]) continue;
      ans++;
      queue<short> q;
      q.push(i);
      visit[i] = true;
      while(!q.empty()) {
        int p = q.front(); q.pop();
        for(int n:u[p]) if(!visit[n]) {
          visit[n] = true;
          q.push(n);
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}