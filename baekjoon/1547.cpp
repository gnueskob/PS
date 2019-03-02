// 공
// https://www.acmicpc.net/problem/1547
#include<iostream>
using namespace std;
#define swap(a,b) (a^=b,b^=a,a^=b)

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int M, c[3]={1,2,3}, s, t; cin >> M;
  while(M--) {
    cin >> s >> t;
    swap(c[s-1],c[t-1]);
  }
  for(int i=0; i<3; i++) if(c[i]==1) cout << i+1;
  return 0;
}