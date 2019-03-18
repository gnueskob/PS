#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> solution(string &S, vector<int> &P, vector<int> &Q);
int main() {
  string S = "CAGCCTA";
  vector<int> P = {2, 5, 0};
  vector<int> Q = {4, 5, 6};
  vector<int> ans = solution(S, P, Q);
  int size = ans.size();
  for(int i=0; i<size; i++) cout << ans[i] << ' ';
  return 0;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  // write your code in C++14 (g++ 6.2.0)
  int size = S.length();
  int genom[3][100001];
  int a=0, c=0, g=0;
  for (int i=0; i<size; i++) {
    switch(S.at(i)) {
      default: break;
      case 'A': a++; break;
      case 'C': c++; break;
      case 'G': g++; break;
    }
    genom[0][i+1] = a; genom[1][i+1] = c; genom[2][i+1] = g;
  }
  int M = P.size(), impactFactor;
  vector<int> ans;
  for(int i=0; i<M; i++) {
    if(genom[0][Q[i]+1] - genom[0][P[i]] > 0) impactFactor = 1;
    else if(genom[1][Q[i]+1] - genom[1][P[i]] > 0) impactFactor = 2;
    else if(genom[2][Q[i]+1] - genom[2][P[i]] > 0) impactFactor = 3;
    else impactFactor = 4;
    ans.push_back(impactFactor);
  }
  return ans;
}