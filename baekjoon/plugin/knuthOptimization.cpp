#include<iostream>
using namespace std;

/**
 * Knuth optimization (크누스 최적화)
 * 2차원 배열 DP에서 점화식이 특정 조건을 만족할 때 활용 가능한 최적화 기법
 * Time Complexity : O(n^3) => O(n^2)
 * Reference : https://blog.myungwoo.kr/98
 *
 * cond.1) DP[i][j] = min_{i<k<j}(DP[i][k] + DP[k][j]) + C[i][j]
 * cond.2) Quadrangle Inequality : C[a][c] + C[b][d] <= C[a][d] + C[b][c], when a <= b <= c <= d
 * cond.3) Monotonicity : C[b][c] <= C[a][d], when a <= b <= c <= d
 *
 * 위의 세 조건을 만족할 때, DP[i][j]를 최소화 하는 k(=P[i][j])는 다음의 조건을 만족
 * P[i][j-1] <= P[i][j] (= k) <= P[i+1][j]
 * 이 부등식을 통해 O(n^3)을 O(n^2)로 해결 가능
 *
 * 보통 조건 1에서, DP[i][j] = min_{i<=k<j}(DP[i][k] + DP[k+1][j]) + C[i][j] 인 경우가 많음
 * E[i][j] = DP[i+1][j] 로 치환하여 사용
 * E[i][j] = min_{i<k<j}(E[i][j] + E[k][j]) + C[i+1][j]
 *
 * 또한 DP[i][j] = max_{i<k<j}(DP[i][k] + DP[k][j]) + C[i][j] 일 경우
 * DP`[i][j] = -DP[i][j]로 치환,
 * DP`[i][j] = min_{i<k<j}(DP`[i][k] + DP`[k][j]) - C[i][j] 로 풀이
 */

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
    for(int i=2; i<=K; i++)
      for(int x=0; x+i<=K; x++) {
        int y = x + i;
        chapter[x][y] = int_max;
        for(int k=p[x][y-1]; k<=p[x+1][y]; k++) {
          int v = chapter[x][k] + chapter[k][y] + sum[y] - sum[x];
          if(chapter[x][y] > v) chapter[x][y] = v, p[x][y] = k;
        }
      }
    cout << chapter[0][K] << '\n';
  }
  return 0;
}