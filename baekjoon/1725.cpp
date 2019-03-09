// 히스토그램
// https://www.acmicpc.net/problem/1725
#include<bits/stdc++.h>
using namespace std;

int readInt() {int a; cin>>a; return a;}

pair<int, int> stk[100000];
int sid;

int main() {
  int n=readInt(); long long max, area;
  area = max = sid = 0;
  for(int i=0; i<n; i++) {
    int h = readInt();
    while(sid && stk[sid-1].second > h) {
      int htop = stk[sid-1].second; sid--;
      area = (long long) htop*(sid ? i - stk[sid - 1].first - 1 : i);
      max = area > max ? area : max;
    }
    stk[sid].first = i;
    stk[sid++].second = h;
  }
  while(sid) {
    int htop = stk[sid-1].second; sid--;
    area = (long long) htop*(sid ? n - stk[sid - 1].first - 1 : n);
    max = area > max ? area : max;
  }
  printf("%lld\n", max);
  return 0;
}