// LCS
// https://www.acmicpc.net/problem/9251
#include<iostream>
#include<string>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int lcs[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s1, s2; cin >> s1 >> s2;
  int temp, prev=0;
  for(int i=1; i<=s1.size(); i++) {
    for(int j=1; j<=s2.size(); j++) {
      temp = lcs[j];
      if(s1.at(i-1) == s2.at(j-1)) lcs[j] = prev + 1;
      else lcs[j] = max(lcs[j-1], lcs[j]);
      prev = temp;
    }
    prev = 0;
  }
  cout << lcs[s2.size()];
  return 0;
}