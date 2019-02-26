// 조세퍼스 문제 0
// https://www.acmicpc.net/problem/11866
#include<iostream>
#include<queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, cnt, idx=0; cin >> N >> M;
  queue<int> q;
  for(int i=1; i<=N; i++) q.push(i);
  cout << '<';
  while(!q.empty()) {
    cnt = M;
    while(--cnt) { q.push(q.front()); q.pop(); }
    cout << q.front(); q.pop();
    if(!q.empty()) cout << ", ";
  }
  cout << '>';
  return 0;
}