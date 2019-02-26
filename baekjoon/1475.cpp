// 방 번호
// https://www.acmicpc.net/problem/1475
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int num[9]={0,}, ans=0, digit, size;
  string n; cin >> n;
  size = n.size();
  for(int i=0; i<size; i++)
    if(n.at(i) == '9') num[6]++;
    else num[n.at(i)-'0']++;
  for(int i=0; i<9; i++)
    if(i==6 && ans < (num[i]+1)/2) ans = (num[i]+1)/2;
    else if(i != 6 && ans < num[i]) ans = num[i];
  cout << ans;
  return 0;
}