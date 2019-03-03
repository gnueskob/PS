#include<iostream>
using namespace std;

/**
 * A^B % C 구하기
 * O(logB) 만에 거듭제곱을 구할 수 있다.
 * B를 반씩 나눠가며 A를 거듭제곱 시켜나간다
 * B가 홀수인 경우 거듭제곱 되어있는 A를 해답(ans)에 곱해준다.
 */

typedef long long ll;

// 재귀함수
ll pow(ll a, ll b, ll c) {
  if(b==0) return 1LL;
  ll val = pow(a, b/2, c);
  val = val*val % c;
  if(b&1) return val*a % c;
  else return val;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  ll A, B, C, ans=1, rA, rB;
  cin >> A >> B >> C;
  rA = A, rB = B;

  // 반복문
  while(B) {
    if(B&1) ans=ans*A%C;
    A=A*A%C;
    B/=2;
  }
  cout << ans << '\n';

  cout << pow(rA,rB,C);
  return 0;
}