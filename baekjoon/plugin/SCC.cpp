#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 1;
/**
 * SCC(Strong Connected Component, 강 연결 요소) 알고리즘
 * Reference: https://jason9319.tistory.com/98
 *
 * vt: 주어진 그래프
 * rvt: 주어진 그래프의 역방향 그래프
 * sccvt: SCC 요소로 이루어진 그래프(vt에서 cycle을 이루는 node들을 하나로 취급)
 * scc: 해당 노드가 속하는 scc(cycle 그룹)
 * sccNum: SCC 요소의 개수
 * sccDetail: 해당 SCC 요소에 포함된 Node list
 */
int discover[MAX], sccNum, cnt, scc[MAX];
stack<int> st;
vector<vector<int>> vt, rvt, sccvt, sccDetail;

/**
 * Tarjan Algorithm(타잔 알고리즘)
 * Time Complexity : O(V + E) (V: 노드 개수, E: 간선개수, dfs이용)
 * directed graph(유향 그래프)를 한 번의 dfs로 순회하여 SCC를 구할 수 있음
 * discover: dfs로 검색하는 노드의 순서
 */
int dfsT(int here) {
  discover[here] = ++cnt;
  int ret = discover[here], t;
  st.push(here);
  for(int there : vt[here]) {
    if(!discover[there]) ret = min(ret, dfsT(there));
    else if(!scc[there]) ret = min(ret, discover[there]);
  }
  if(ret == discover[here]) {
    sccNum++;
    do {
      t = st.top(); st.pop();
      scc[t] = sccNum;
      sccDetail[sccNum].emplace_back(t);
    } while(t != here);
    sort(sccDetail[sccNum].begin(), sccDetail[sccNum].end());
  }
  return ret;
}

bool visit[MAX];
/**
 * Kosaraju Algorithm(코사라주 알고리즘)
 * Time Complexity : O(V + E) (V: 노드 개수, E: 간선개수, dfs이용)
 * 그래프와 역그래프를 이용해 두 번의 dfs로 SCC를 구할 수 있음
 * 역 그래프를 저장해야 하므로 타잔 알고리즘 보다 메모리가 추가로 필요
 */
void dfsK(int here) {
  visit[here] = true;
  for(int there : vt[here]) if(!visit[there]) dfsK(there);
  st.push(here);
}

void dfsK2(int here) {
  int i;
  scc[here] = sccNum;
  sccDetail[sccNum].push_back(here);
  for(int there : rvt[here]) if(!scc[there]) dfsK2(there);
}

int main() {
  freopen("./baekjoon/input/1325.txt", "r", stdin);
  // N : node number, M : edge number
  int N, M, i, maxCnt=0;
  cin >> N >> M;
  vt.resize(N+1);
  rvt.resize(N+1);
  sccvt.resize(N+1);
  sccDetail.resize(N+1);
  for (i=0; i<M; i++) {
    int t, s; cin >> t >> s;
    vt[s].push_back(t);
    rvt[t].push_back(s); // 코사라주 알고리즘을 위한 역그래프
  }

  // 타잔 알고리즘을 통해 SCC를 생성
  for(i=1; i<=N; i++) if(!discover[i]) dfsT(i);  // 각 노드별로 SCC 그룹 할당

  // 코사라주 알고리즘을 통해 SCC를 생성
  // for(i=1; i<=N; i++) if(!visit[i]) dfsK(i);
  // while(!st.empty()) {
  //   int here = st.top(); st.pop();
  //   if(!scc[here]) {
  //     sccNum++;
  //     dfsK2(here);  // 각 노드별로 SCC 그룹 할당
  //     sort(sccDetail[sccNum].begin(), sccDetail[sccNum].end());
  //   }
  // }

  // 노드를 순회하며 SCC 그룹 끼리의 유향그래프(sccvt) 생성
  for(i=1; i<=N; i++) for(int n:vt[i])
    if(scc[i]^scc[n]) sccvt[scc[i]].push_back(scc[n]);

  // 중복된 SCC 유향 그래프 요소 제거
  for(i=1; i<=sccNum; i++)
    sort(sccvt[i].begin(), sccvt[i].end()), // * 정렬 후 erase시 더 빠름
    sccvt[i].erase(unique(sccvt[i].begin(), sccvt[i].end()), sccvt[i].end());

  puts("SCC Detail components");
  for(i=1; i<=sccNum; i++) {
    printf("[%d] SCC group, size : %d / ",i,sccDetail[i].size());
    for(int n:sccDetail[i]) printf("%d, ",n);
    puts("");
  }

  puts("SCC group graph");
  for(i=1; i<=sccNum; i++) {
    printf("[%d] SCC group -> ",i);
    for(int n:sccvt[i]) printf("%d, ",n);
    puts("");
  }

  return 0;
}