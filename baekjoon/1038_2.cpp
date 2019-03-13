#include<cstdio>
#include<algorithm>
int a[10];
main() {
  int i,j,n;
  scanf("%d",&n);
  for(i=1; i<=10; i++) {
    for(j=0; j<i; j++) a[9-j]=1;
    do {
      if(!n--) {
        for(j=0; j<10; j++) if(a[j]) printf("%d",9-j);
        return 0;
      }
    } while(std::next_permutation(a,a+10));
  }
  puts("-1");
}