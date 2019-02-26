// LCS 2
// https://www.acmicpc.net/problem/9251
#include<iostream>
#include<string>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int lcs[1001][1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s1, s2; cin >> s1 >> s2;
  for(int i=1; i<=s1.size(); i++)
    for(int j=1; j<=s2.size(); j++)
      if(s1.at(i-1) == s2.at(j-1)) lcs[i][j] = lcs[i-1][j-1] + 1;
      else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
  int lcsLen = lcs[s1.size()][s2.size()];

  string res(lcsLen, 0);
  int idx = lcsLen - 1;
  int i = s1.size(), j = s2.size();
  while(true) {
    int v = lcs[i][j];
    if(v > lcs[i-1][j-1] && v > lcs[i-1][j] && v > lcs[i][j-1]) {
      res.at(idx) = s1.at(i-1);
      i--, j--, idx--;
    } else if(v > lcs[i-1][j] && v == lcs[i][j-1]) j--;
    else i--;
    if(idx < 0) break;
  }

  cout << lcsLen << '\n' << res;
  return 0;
}