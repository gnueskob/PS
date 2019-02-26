// 조세퍼스 문제
// https://www.acmicpc.net/problem/1158
#include<iostream>
#include<list>
using namespace std;

int main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, cnt, idx=0; cin >> N >> M;
  list<int> li;
  for(int i=1; i<=N; i++) li.push_back(i);
  cout << '<';
  auto it = li.begin();
  while(!li.empty()) {
    cnt = M;
    while(--cnt) { it++; if(it==li.end()) it=li.begin(); }
    cout << *it; it=li.erase(it); if(it==li.end()) it=li.begin();
    if(!li.empty()) cout << ", ";
  }
  cout << '>';
  return 0;
}