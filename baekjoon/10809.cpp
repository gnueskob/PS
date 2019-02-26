// 알파벳 찾기
// https://www.acmicpc.net/problem/10809
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string str;
  cin >> str;
  int size = str.length();
  int ch[26] = {-1,};
  memset(ch, 0xFF, 26*sizeof(int));
  for(int i=0; i<size; i++)
    if(ch[str.at(i)-'a'] == -1) { ch[str.at(i)-'a'] = i; }
  for(int i=0; i<26; i++) cout << ch[i] << ' ';
  return 0;
}