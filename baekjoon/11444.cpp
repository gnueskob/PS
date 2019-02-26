// 피보나치 수 6
// https://www.acmicpc.net/problem/11444
#include<iostream>
#include<vector>
using namespace std;

const int mod = (int)1e9+7;

typedef vector<vector<long long>> Matrix;

Matrix operator * (const Matrix& a, const Matrix& b) {
  int size = a.size();
  Matrix res(size, vector<long long>(size,0));
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++) {
      for(int k=0; k<size; k++)
        res[i][j] += a[i][k]*b[k][j];
      res[i][j] %= mod;
    }
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  long long n; cin >> n;
  if(n<=1) { cout << n; return 0; }
  Matrix ans = {{1,0},{0,1}};
  Matrix I = {{1,1},{1,0}};
  while(n) {
    if(n&1) ans = ans * I;
    I = I * I;
    n/=2;
  }
  cout << ans[0][1];
  return 0;
}