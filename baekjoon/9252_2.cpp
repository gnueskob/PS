// LCS 2
// https://www.acmicpc.net/problem/9251
#include<cstdio>
bool l[1001][1001];
int lcs[1001];
int main() {
  char s1[1002], s2[1002], res[1001]; scanf("%s%s",s1+1,s2+1);
  int i, j, len, idx;
  int t, p=0;
  for(i=1; s1[i]; i++) {
    for(j=1; s2[j]; j++) {
      t = lcs[j];
      if(s1[i] == s2[j]) lcs[j] = p + 1;
      else if(lcs[j-1] > lcs[j]) { lcs[j] = lcs[j-1]; l[i][j] = true; }
      p = t;
    }
    p = 0;
  }
  i--,j--; idx = len = lcs[j];
  res[idx-1] = 0;
  while(idx) {
    printf("%d %d\n", i, j);
    if(s1[i] == s2[j]) { res[idx-1] = s1[i]; i--, j--, idx--; }
    else if(l[i][j]) j--;
    else i--;
  }
  printf("%d\n%s",len,res);
  return 0;
}