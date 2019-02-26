#include<iostream>
#include<vector>
using namespace std;

typedef vector<long long> vll;

const int MAX = (int) 1e9, MAXLEN = 9;
vll bigInt(1,1);

// 큰 수 v에 num을 곱하는 함수 (num < MAX)
void mul(vll& v, int num) {
  int j;
  for(j=0; j<v.size(); j++) v[j] *= num;
  for(j=0; j<v.size()-1; j++) { v[j+1] += v[j]/MAX; v[j] %= MAX; }
  if(v[j] >= MAX) { v.push_back(v[j]/MAX); v[j] %= MAX; }
}

// 큰 수 v를 num으로 나누는 함수 (나머지 버림) (num < MAX)
void div(vll& v, int num) {
  for(int j=v.size()-1; j>0; j--) {
    v[j-1] += v[j]%num*MAX; v[j] /= num;
    if(j==v.size()-1 && v[j]==0) v.pop_back();
  }
  v[0] /= num;
}

/**
 * 큰 수 bigInt 곱셈, 나눗셈 구현
 * 각 자리수당 MAX (1,000,000,000) 미만의 값까지 표현 가능
 */
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int N, M, i; cin >> N >> M;

  bigInt[0] = 1;
  for(i=0; i<M; i++) mul(bigInt, N-i);
  for(i=0; i<M-1; i++) div(bigInt, M-i);

  // 출력 방식
  cout << bigInt[bigInt.size()-1];
  for(i=bigInt.size()-2; i>=0; i--) { cout.width(MAXLEN); cout.fill('0'); cout << bigInt[i]; }
  return 0;
}