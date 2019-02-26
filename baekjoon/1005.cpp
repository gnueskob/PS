// ACM Craft
// https://www.acmicpc.net/problem/1005
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define max(a,b) (a>b?a:b)
vector<vector<int>> vertex;
int delay[1000], time[1000];

int findMinTime(int n) {
  if(time[n] >= 0) return time[n];
  int prevMax = 0;
  for(auto prev:vertex[n]) {
    if (time[prev] < 0) findMinTime(prev);
    prevMax = max(prevMax, time[prev]);
  }
  time[n] = prevMax + delay[n];
  return time[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("./input/1005.txt", "r", stdin);
  int T, N, K, D, s, t, W;
  cin >> T;
  while(T--) {
    memset(time, -1, sizeof(time));
    cin >> N >> K;
    vertex.clear();
    vertex.resize(N);
    for(int i=0; i<N; i++) cin >> delay[i];
    while(K--) {
      cin >> s >> t;
      vertex[t-1].push_back(s-1);
    }
    cin >> W;
    cout << findMinTime(W-1) << '\n';
  }
  return 0;
}