// 음계
// https://www.acmicpc.net/problem/2920
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int num[8];
  bool asc=true, desc=true;
  for(int i=0; i<8; i++) cin >> num[i];
  for(int i=1; i<8; i++) {
    if(asc && num[i-1] > num[i]) asc = false;
    if(desc && num[i-1] < num[i]) desc = false;
  }
  if(asc&&!desc) cout << "ascending";
  else if(!asc&&desc) cout << "descending";
  else cout << "mixed";
  return 0;
}