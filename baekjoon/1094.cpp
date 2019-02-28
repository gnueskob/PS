// 막대기
// https://www.acmicpc.net/problem/1094
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int stick[] = {64,32,16,8,4,2,1}, c = 0, x, ans = 0;
  cin >> x;
  for(int i=0; i<7; i++)
    if(x == c + stick[i]) { ans++; break; }
    else if(x > c + stick[i]) c += stick[i], ans++;
  cout << ans;
  return 0;
}