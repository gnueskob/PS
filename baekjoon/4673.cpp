// 셀프 넘버
// https://www.acmicpc.net/problem/4673
#include<iostream>
using namespace std;

const int MAX = 10001;
bool notSelfNum[MAX];

void setNotSelfNum(int n) {
  int nextNum = n;
  do { nextNum += n%10; } while(n/=10);
  if(nextNum < MAX) notSelfNum[nextNum] = true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for(int i=1; i<MAX; i++) setNotSelfNum(i);
  for(int i=1; i<MAX; i++) if(!notSelfNum[i]) cout << i << '\n';
  return 0;
}