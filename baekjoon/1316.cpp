// 그룹 단어 체커
// https://www.acmicpc.net/problem/1316
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  const int MAX_CHAR_SiZE = 26;
  bool ch[MAX_CHAR_SiZE], isGroupWord = true;
  int T, ans=0, size; cin >> T;
  string str;
  char prev;
  while(T--) {
    memset(ch, 0, MAX_CHAR_SiZE);
    isGroupWord = true;
    cin >> str;
    size = str.length();
    prev = str.at(0);
    ch[prev-'a'] = true;
    for(int i=1; i<size; i++) {
      if(prev != str.at(i)) {
        if(ch[str.at(i)-'a']) { isGroupWord = false; break; }
        ch[str.at(i)-'a'] = true;
      }
      prev = str.at(i);
    }
    if(isGroupWord) ans++;
  }
  cout << ans;
  return 0;
}