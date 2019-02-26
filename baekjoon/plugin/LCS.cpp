#include<iostream>
#include<string>
#include<tuple>
using namespace std;

/**
 * LCS(Longest Common Subsequence) : 최장 공통 수열
 * Reference : https://hsp1116.tistory.com/37
 * Simulation : http://lcs-demo.sourceforge.net/
 *
 * LCS(X_i, Y_j) = 0                                        if i = 0 or j = 0 (1)
 *               = LCS(X_i-1, Y_j-1) + 1                    if X_i == Y_j     (2)
 *               = max(LCS(X_i, Y_j-1), LCS(X_i-1, Y_j))    if X_i != Y_i     (3)
 */

inline int max(int a, int b) { return a > b ? a : b; }

const int MAX = 1e3 + 1;

/**
 * 최장 공통 수열의 길이만을 구하는 경우
 * 실제 수열을 구할 필요가 없으므로 1-dimension array만을 통해
 * 최장 길이만을 DP로 계속 구해나감
 */
int lcsOnlyLength(string& s1, string& s2) {
  int temp, prev=0;
  int lcs[MAX]{};
  for(int i=1; i<=s1.size(); i++) {
    for(int j=1; j<=s2.size(); j++) {
      temp = lcs[j];
      if(s1.at(i-1) == s2.at(j-1)) { lcs[j] = prev + 1; } // 점화식 (2)
      else { lcs[j] = max(lcs[j-1], lcs[j]); }            // 점화식 (3)
      prev = temp;
    }
    prev = 0;
  }
  return lcs[s2.size()];
}

/**
 * 최장 공통 수열의 길이와 더불어 Subsequence까지 구하는 경우
 * 2-dimension array를 통해 각 위치의 정보를 모두 저장해두고
 * Subsequence를 찾는 데에 사용
 */
int lcs[MAX][MAX];
tuple<int, string> lcsWithSubseq(string& s1, string& s2) {
  for(int i=1; i<=s1.size(); i++)
    for(int j=1; j<=s2.size(); j++)
      if(s1.at(i-1) == s2.at(j-1)) { lcs[i][j] = lcs[i-1][j-1] + 1; } // 점화식 (2)
      else { lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]); }             // 점화식 (3)
  int lcsLen = lcs[s1.size()][s2.size()];

  // 최대 길이를 얻은 부분 부터 backtracking
  // 점화식 (2)에 해당하는 글자를 추적해나가는 방식
  string res(lcsLen, 0);
  int idx = lcsLen - 1;
  int i = s1.size(), j = s2.size();
  while(true) {
    int v = lcs[i][j];
    if(v > lcs[i-1][j-1] && v > lcs[i-1][j] && v > lcs[i][j-1]) { // 점화식 (2) 였던 부분
      res.at(idx) = s1.at(i-1);
      i--, j--, idx--;
    } else if(v > lcs[i-1][j]) j--; // 점화식 (3) 이었던 부분
    else i--;
    if(idx < 0) break;
  }
  return { lcsLen, res };
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s1, s2; cin >> s1 >> s2;
  int len; string res;
  tie(len, res) = lcsWithSubseq(s1, s2);
  cout << lcsOnlyLength(s1, s2) << endl;
  cout << len << endl;
  cout << res;
  return 0;
}