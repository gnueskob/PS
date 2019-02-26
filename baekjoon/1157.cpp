// 단어 공부
// https://www.acmicpc.net/problem/1157
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  const int MAX_CHAR_SIZE = 26;
  int ch[MAX_CHAR_SIZE], size, idx, max1=0, max2=0, maxIdx;
  memset(ch, 0, MAX_CHAR_SIZE*sizeof(int));
  string str;
  cin >> str;
  size = str.length();
  for(int i=0; i<size; i++) {
    if(str.at(i) >= 'a') idx = str.at(i) - 'a';
    else idx = str.at(i) - 'A';
    ch[idx]++;
    if(ch[idx] >= max2) { max1 = max2; max2 = ch[idx]; maxIdx = idx; }
  }
  if(max2 == max1) cout << '?';
  else { char c = maxIdx+'A'; cout << c; }
  return 0;
}