// 효율적인 해킹
// https://www.acmicpc.net/problem/1325
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

inline int readInt() {int a;scanf("%d",&a);return a;}
inline void writeChar(char x) {printf("%c",x);}
template <typename T> inline
void writeInt(T x,char e) {if(x<0)writeChar(45),x=-x;char s[24]{};int l=0;while(x||!l)s[l++]=x%10,x/=10;while(l--)writeChar(s[l]+48);if(e)writeChar(e);}

const int MAX = 1e4 + 1;
int discover[MAX], r, cnt, scc[MAX], sccNum[MAX], connectCnt[MAX];
bool visit[MAX];
stack<int> st;
vector<vector<int>> vt, sccvt;

int dfs(int here) {
  discover[here] = ++cnt;
  int ret = discover[here], t;
  st.push(here);
  for(int there : vt[here]) {
    if(!discover[there]) ret = min(ret, dfs(there));
    else if(!scc[there]) ret = min(ret, discover[there]);
  }
  if(ret == discover[here]) {
    r++;
    do {
      t = st.top(); st.pop();
      scc[t] = r;
      sccNum[r]++;
    } while(t != here);
  }
  return ret;
}

int dfsSCC(int here) {
  int cnt = sccNum[here];
  for(int there:sccvt[here]) if(!visit[there]) {
    visit[there] = true;
    cnt += dfsSCC(there);
  }
  return cnt;
}

int main() {
  int N = readInt(), M = readInt(), i, maxCnt=-1;
  vt.resize(N+1);
  sccvt.resize(N+1);
  for (i=0; i<M; i++) {
    int t = readInt(), s = readInt();
    vt[s].push_back(t);
  }
  for(i=1; i<=N; i++) if(!discover[i]) dfs(i);

  for(i=1; i<=N; i++) for(int n:vt[i])
    if(scc[i]^scc[n]) sccvt[scc[i]].push_back(scc[n]);
  for(int i=1; i<=r; i++)
    sort(sccvt[i].begin(), sccvt[i].end()),
    sccvt[i].erase(unique(sccvt[i].begin(), sccvt[i].end()), sccvt[i].end());

  for(i=1; i<=r; i++)
    memset(visit, 0, r),
    maxCnt = max(maxCnt, connectCnt[i] = dfsSCC(i));

  for(i=1; i<=N; i++) if(maxCnt == connectCnt[scc[i]]) printf("%d ",i);
  return 0;
}