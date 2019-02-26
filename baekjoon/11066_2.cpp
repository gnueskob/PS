// 파일 합치기
// https://www.acmicpc.net/problem/11066
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 501;
int chapter[MAX][MAX], p[MAX][MAX], sum[MAX];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, K; cin >> T;
  int int_max = (unsigned int) -1 >> 1;
  while(T--) {
    cin >> K;
    for(int i=1; i<=K; i++) {
      int v; cin >> v;
      sum[i] = sum[i-1] + v;
      p[i-1][i] = i;
    }
    // # 크누스 최적화
    // # Knuth optimization
    for(int i=2; i<=K; i++)
      for(int x=0; x+i<=K; x++) {
        int y = x + i;
        chapter[x][y] = int_max;
        for(int k=p[x][y-1]; k<=p[x+1][y]; k++) {
          int v = chapter[x][k] + chapter[k][y];
          if(chapter[x][y] > v) chapter[x][y] = v, p[x][y] = k;
        }
        chapter[x][y] += sum[y] - sum[x];
      }
    cout << chapter[0][K] << '\n';
  }
  return 0;
}