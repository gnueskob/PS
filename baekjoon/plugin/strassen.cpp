// 행렬 곱셈
// https://www.acmicpc.net/problem/2740
#include<bits/stdc++.h>
using namespace std;

#define max(a,b) (a>b?a:b)

typedef vector<vector<int>> Matrix;

int getCeilPowerOfTwo(int v) {
  v--;
  for(int i=1; i<sizeof(v); i*=2) v |= v >> i;
  return ++v;
}

void setSubMatrix(const Matrix& A, Matrix a[][2], int size) {
  for(int i=0; i<size; i++) for(int j=0; j<size; j++)
    a[0][0][i][j] = A[i][j],
    a[0][1][i][j] = A[i][j+size],
    a[1][0][i][j] = A[i+size][j],
    a[1][1][i][j] = A[i+size][j+size];
}

void opMatrix(Matrix& t, const Matrix& a, const Matrix& b, bool sub) {
  int size = t.size();
  for(int i=0; i<size; i++) for(int j=0; j<size; j++)
    t[i][j] = a[i][j] + b[i][j] * (sub ? -1 : 1);
}

void mulMatrix(Matrix& t, const Matrix& a, const Matrix& b, int size) {
  for(int i=0; i<size; i++) for(int j=0; j<size; j++) {
    t[i][j] = 0;
    for(int k=0; k<size; k++)
      t[i][j] += a[i][k] * b[k][j];
  }
}

void mergeMatrix(Matrix& t, const Matrix c[][2], int size) {
  for(int i=0; i<size; i++) for(int j=0; j<size; j++)
    t[i][j] = c[0][0][i][j],
    t[i][j+size] = c[0][1][i][j],
    t[i+size][j] = c[1][0][i][j],
    t[i+size][j+size] = c[1][1][i][j];
}

int getThreshold(int n) {
	int th;
	double k = floor(log(n) / log(2) - 6);
	th = (int) floor(n / pow(2.0, k)) + 1;
	return th;
}

void strassen(Matrix& C, Matrix& A, Matrix& B, int size) {
  if(size <= 2) { mulMatrix(C, A, B, size); return; }
  int s = size/2;
  Matrix sub(s, vector<int>(s,0));
  Matrix a[2][2] = {{sub,sub},{sub,sub}};
  Matrix b[2][2] = {{sub,sub},{sub,sub}};
  Matrix t[2] = {sub,sub};
  Matrix m[7] = {sub,sub,sub,sub,sub,sub,sub};

  setSubMatrix(A, a, s);
  setSubMatrix(B, b, s);

  opMatrix(t[0], a[0][0], a[1][1], 0);  // A11 + A22
  opMatrix(t[1], b[0][0], b[1][1], 0);  // B11 + B22
  strassen(m[0], t[0], t[1], s);        // M1 = (A11 + A22)*(B11 + B22)

  opMatrix(t[0], a[1][0], a[1][1], 0);  // A21 + A22
  strassen(m[1], t[0], b[0][0], s);     // M2 = (A21 + A22)*B11

  opMatrix(t[0], b[0][1], b[1][1], 1);  // B12 - B22
  strassen(m[2], a[0][0], t[0], s);     // M3 = A11*(B12 - B22)

  opMatrix(t[0], b[1][0], b[0][0], 1);  // B21 - B11
  strassen(m[3], a[1][1], t[0], s);     // M4 = A22*(B21 - B11)

  opMatrix(t[0], a[0][0], a[0][1], 0);  // A11 + A12
  strassen(m[4], t[0], b[1][1], s);     // M5 = (A11 + A12)*B22

  opMatrix(t[0], a[1][0], a[0][0], 1);  // A21 - A11
  opMatrix(t[1], b[0][0], b[0][1], 0);  // B11 + B12
  strassen(m[5], t[0], t[1], s);        // M6 = (A21 - A11)*(B11 + B12)

  opMatrix(t[0], a[0][1], a[1][1], 1);  // A12 - A22
  opMatrix(t[1], b[1][0], b[1][1], 0);  // B21 + B22
  strassen(m[6], t[0], t[1], s);        // (A12 - A22)*(B21 + B22)

  opMatrix(t[0], m[0], m[3], 0);        // M1 + M4
  opMatrix(t[1], t[0], m[4], 1);        // M1 + M4 - M5
  opMatrix(a[0][0], t[1], m[6], 0);     // C11 = M1 + M4 - M5 + M7

  opMatrix(a[0][1], m[2], m[4], 0);     // C12 = M3 + M5

  opMatrix(a[1][0], m[1], m[3], 0);     // C21 = M2 + M4

  opMatrix(t[0], m[0], m[1], 1);        // M1 - M2
  opMatrix(t[1], t[0], m[2], 0);        // M1 - M2 + M3
  opMatrix(a[1][1], t[1], m[5], 0);     // C22 = M1 - M2 + M3 + M6;

  mergeMatrix(C, a, s);
}

Matrix A(128, vector<int>(128,0));
Matrix B(128, vector<int>(128,0));
Matrix C(128, vector<int>(128,0));

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, K, size, t;
  cin >> N >> M;
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> A[i][j];
  cin >> M >> K;
  for(int i=0; i<M; i++) for(int j=0; j<K; j++) cin >> B[i][j];

  size = getCeilPowerOfTwo(N);
  size = max(size,getCeilPowerOfTwo(M));
  size = max(size,getCeilPowerOfTwo(K));
  strassen(C, A, B, size);

  for(int i=0; i<N; i++) {
    for(int j=0; j<K; j++)
      cout << C[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
