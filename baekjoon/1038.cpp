// 감소하는 수
// https://www.acmicpc.net/problem/1038
#include<cstdio>

typedef long long ll;

int C[10][5];
int offset = 0;

int comb(int n, int r) {
  if(n <= 1 || r==0 || n==r) return 1;
  r = n-r > r ? r : n-r;
  if(C[n][r]) return C[n][r];
  int prevComb = comb(n-1, r);
  int prevComb2 = comb(n-1, r-1);
  C[n][r] = prevComb + prevComb2;
  return C[n][r];
}

bool dfs(int s, int len, ll num) {
  if(!len) {
    if(!offset) { printf("%lld", num); return true; }
    offset--;
    return false;
  }
  for(int i=s-1; i>=len-1; i--) {
    if(dfs(i, len-1, num*10 + i)) return true;
  }
}

void findNthDecNum(int n) {
  int prev = 9, next;
  for(int i=2; i<11; i++) {
    for(int j=i-1; j<10; j++) {
      next = prev + comb(j,i-1);
      prev = next;
      if(n <= next) { offset = next-n; dfs(j, i-1, j); return; }
    }
  }
}

int main() {
  int n; scanf("%d",&n);
  if(n<=10) { printf("%d",n); return 0; }
  else if(n>1022) { printf("-1"); return 0; }
  findNthDecNum(n);
  return 0;
}