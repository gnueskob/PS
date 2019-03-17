// 트리의 지름
// https://www.acmicpc.net/problem/1967
#include<cstdio>

inline int readInt() {int a; scanf("%d",&a); return a; }

int N;
short parent[10001], weight[10001], childCnt[10001];
int dist[10001][2];

int main() {
  N = readInt();
  int s, t, w;
  for(int i=1; i<N; i++) {
    s = readInt(), t = readInt(), w = readInt();
    parent[t] = s;
    weight[t] = w;
    childCnt[s]++;
  }
  int p = 0, max = 0;
  for(int i=N; i>=1; i--) {
    if(!childCnt[i]) {
      p = parent[i];
      childCnt[p]--;
      w = weight[i] + dist[i][0];
      if(dist[p][0] < w) {
        dist[p][1] = dist[p][0];
        dist[p][0] = w;
      } else if(dist[p][1] < w) {
        dist[p][1] = w;
      }
      int sum = dist[p][0] + dist[p][1];
      max = max < sum ? sum : max;
    }
  }
  printf("%d",max);
  return 0;
}