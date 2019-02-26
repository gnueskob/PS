// 프린터 큐
// https://www.acmicpc.net/problem/1966
#include<iostream>
#include<cstring>
using namespace std;

int priCnt[11];
int pri[100*101/2];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T, N, M, max; cin >> T;
  while(T--) {
    memset(priCnt, 0, sizeof(priCnt));
    max = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
      cin >> pri[i];
      priCnt[pri[i]]++;
      max = max < pri[i] ? pri[i] : max;
    }
    int remain = N;
    for(int i=0; i<N*(N+1)/2; i++) {
      if(pri[i] < max) { pri[i+remain] = pri[i]; if(M==i) M+=remain; }
      else {
        remain--; priCnt[max]--;
        if(M==i) { cout << N-remain << '\n'; break; }
        for(int j=max; j>=1; j--) if(priCnt[j]) { max = j; break; }
      }
    }
  }
  return 0;
}