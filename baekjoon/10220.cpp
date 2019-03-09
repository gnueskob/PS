// Self Representing Seq
// https://www.acmicpc.net/problem/10220
#include<cstdio>
using namespace std;

int main() {
  int T, n;
  scanf("%d",&T);
  while(T--) {
    int ans;
    scanf("%d",&n);
    switch (n) {
      case 1:
      case 2:
      case 3:
      case 6: ans=0; break;
      case 4: ans=2; break;
      default: ans=1; break;
    }
    printf("%d\n",ans);
  }
  return 0;
}