// 피보나치 수 4
// https://www.acmicpc.net/problem/10826
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class num {
private:
  vector<long long> n;
  const static int MAX = (int)1e9;
  const static int MAXLEN = 9;
public:
  num() {}
  num(long long _n) { if(!_n) n.push_back(0); while(_n) { n.push_back(_n%MAX); _n/=MAX; }
  }
  ~num() { n.clear(); }
  bool found() { return !n.empty(); }
  const num operator+ (const num& op) const {
    num res;
    int size = n.size(), sizeOP = op.n.size();
    int N = size > sizeOP ? size : sizeOP;
    int carry = 0;
    for(int i=0; i<N; i++) {
      int a = (i<size?n[i]:0) + (i<sizeOP?op.n[i]:0) + carry;
      if(a >= MAX) { carry = 1; a -= MAX; }
      else carry = 0;
      res.n.push_back(a);
    }
    if(carry) res.n.push_back(carry);
    return res;
  }
  const num operator* (const num& op) const {
    num res;
    int size = n.size(), sizeOP = op.n.size();
    const num& b = (size < sizeOP ? op : *this);
    const num& s = (size < sizeOP ? *this : op);
    int bSize = size < sizeOP ? sizeOP : size;
    int sSize = size < sizeOP ? size : sizeOP;
    int resSize = bSize + sSize - 1;
    res.n.assign(resSize, 0);
    for(int i=0; i<bSize; i++)
      for(int j=0; j<sSize; j++) {
        long long a = b.n[i] * s.n[j];
        int carry = a/MAX, k=1; a %= MAX;
        res.n[i+j] += a;
        carry += res.n[i+j]/MAX; res.n[i+j] %= MAX;
        while(carry) {
          if(i+j+k == res.n.size()) res.n.push_back(0);
          res.n[i+j+k] += carry;
          carry = res.n[i+j+k]/MAX;
          res.n[i+j+k] %= MAX;
          k++;
        }
      }
    return res;
  }
  void prt() const {
    int size = n.size();
    cout << n[size-1];
    for(int i=size-2; i>=0; i--) {
      cout.width(MAXLEN); cout.fill('0');
      cout << n[i];
    }
  }
};

typedef vector<vector<num>> Matrix;

Matrix operator * (const Matrix& a, const Matrix& b) {
  int size = a.size();
  Matrix res(size, vector<num>(size,0));
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      for(int k=0; k<size; k++)
        res[i][j] = res[i][j] + a[i][k] * b[k][j];
  return res;
}

num F[10001];

num fibo(int n) {
  if(F[n].found()) return F[n];
  if(n&1) {
    int p = (n+1)/2, pp = p-1;
    return fibo(p)*fibo(p) + fibo(pp)*fibo(pp);
  } else {
    int h = n/2;
    return (fibo(h-1) + fibo(h+1))*fibo(h);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // O(log n)
  // F[0]=0, F[1]=1, F[2]=1;
  // int n; cin >> n;
  // fibo(n).prt();

  // O(log n)
  int n; cin >> n;
  if(n<=1) { cout << n ; return 0; }
  Matrix ans = {{1,0},{0,1}};
  Matrix I = {{1,1},{1,0}};
  while(n) {
    if(n&1) ans = ans * I;
    I = I * I;
    n/=2;
  }
  ans[0][1].prt();

  // O(n)
  // int n; cin >> n;
  // num a(1), ans(0), t;
  // while(n--) {
  //   t = ans + a;
  //   ans = a;
  //   a = t;
  // }
  // ans.prt();
  return 0;
}