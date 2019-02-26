// 단어 정렬
// https://www.acmicpc.net/problem/1181
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int MAXN = 20000;
string str[MAXN];

bool cmp(const string& str1, const string& str2) {
  if(str1.length() != str2.length()) return str1.length() < str2.length();
  else return str1 < str2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N; cin >> N;
  for(int i=0; i<N; i++) cin >> str[i];
  sort(str, str+N, cmp);
  cout << str[0] << '\n';
  for(int i=1; i<N; i++) if(str[i-1] != str[i]) cout << str[i] << '\n';
  return 0;
}