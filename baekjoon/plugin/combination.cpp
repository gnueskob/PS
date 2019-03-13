#include<bits/stdc++.h>
using namespace std;

/**
 * Combination(nCr) 구하기
 * memoization 이용
 * nCr = n-1Cr + n-1Cr-1 임을 이용하여 재귀적으로 구현
 * nCr = nCn-r 을 이용하여 메모리 사용을 반으로 줄임
 */
int C[100][50];

int comb(int n, int r) {
  if(n <= 1 || r==0 || n==r) return 1;
  r = n-r > r ? r : n-r;
  if(C[n][r]) return C[n][r];
  int prevComb = comb(n-1, r);
  int prevComb2 = comb(n-1, r-1);
  C[n][r] = prevComb + prevComb2;
  return C[n][r];
}

int main() {
  int a, b;
  scanf("%d%d",&a, &b);
  printf("%d",comb(a, b));
  return 0;
}
