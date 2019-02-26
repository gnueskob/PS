// 파일 합치기
// https://www.acmicpc.net/problem/11066
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 501;
int chapter[MAX][MAX];
int sum[MAX];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, K; cin >> T;
  while(T--) {
    cin >> K;
    for(int i=1; i<=K; i++) {
      int v; cin >> v;
      sum[i] = sum[i-1] + v;
    }
    for(int i=1; i<K; i++)
      for(int x=1; x+i<=K; x++) {
        int y=x+i;
        unsigned int int_max = -1; int_max >>= 1;
        chapter[x][y] = int_max;
        int subSum = sum[y] - sum[x-1];
        for(int k=x; k<y; k++)
          chapter[x][y] = min(chapter[x][y], chapter[x][k] + chapter[k+1][y] + subSum);
      }
    cout << chapter[1][K] << '\n';
  }
  return 0;
}