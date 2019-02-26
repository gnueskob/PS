// 조합
// https://www.acmicpc.net/problem/2407
#include<iostream>
#include<vector>
using namespace std;

typedef vector<long long> vll;

const int MAX = (int) 1e9, MAXLEN = 9;
vll numer(1,1);

void mul(vll& v, int num) {
  int j;
  for(j=0; j<v.size(); j++) v[j] *= num;
  for(j=0; j<v.size()-1; j++) { v[j+1] += v[j]/MAX; v[j] %= MAX; }
  if(v[j] >= MAX) { v.push_back(v[j]/MAX); v[j] %= MAX; }
}

void div(vll& v, int num) {
  for(int j=v.size()-1; j>0; j--) {
    v[j-1] += v[j]%num*MAX; v[j] /= num;
    if(j==v.size()-1 && v[j]==0) v.pop_back();
  }
  v[0] /= num;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, i; cin >> N >> M;
  if(M > N/2) M = N-M;
  numer[0] = 1;
  for(i=0; i<M; i++) mul(numer, N-i);
  for(i=0; i<M-1; i++) div(numer, M-i);
  cout << numer[numer.size()-1];
  for(i=numer.size()-2; i>=0; i--) { cout.width(MAXLEN); cout.fill('0'); cout << numer[i]; }
  return 0;
}