#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 가변 크기의 N*N 행렬
typedef vector<vector<int>> Matrix;

// N*N 행렬의 곱연산 overiding
Matrix operator * (const Matrix& a, const Matrix& b) {
  int size = a.size();
  Matrix res(size, vector<int>(size,0));
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      for(int k=0; k<size; k++)
        res[i][j] = res[i][j] + a[i][k] * b[k][j];
  return res;
}

// N*N 행렬의 합연산 overiding
Matrix operator + (const Matrix& a, const Matrix& b) {
  int size = a.size();
  Matrix res(size, vector<int>(size,0));
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      res[i][j] = a[i][j] + b[i][j];
  return res;
}

// 행렬 outputStream overiding
ostream& operator << (ostream& os, const Matrix& a) {
  int size = a.size();
  for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++)
      os << a[i][j] << ' ';
    os << '\n';
  }
  return os;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  // 2*2 행렬 선언 & 초기화
  Matrix ans = {{1,0},{0,1}};
  Matrix I = {{1,1},{1,0}};

  cout << ans;
  cout << I;
  cout << ans*I;

  // 3*3 행렬 선언 & 초기화
  Matrix m3 = {{1,0,0},{0,1,0},{0,0,1}};
  Matrix m3_2 = {{1,2,3},{3,1,2},{2,3,1}};

  cout << m3 << m3_2 << m3*m3_2;

  return 0;
}