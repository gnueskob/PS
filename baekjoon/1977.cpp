// 완전제곱수
// https://www.acmicpc.net/problem/1977
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
  int min=0, sum=0, M, N; scanf("%d%d",&M,&N);
  for(int i=1; i*i<=N; i++)
    if(M<=i*i && i*i<=N) {
      if(!min) min = i*i;
      sum += i*i;
    }
  if(min) printf("%d\n%d",sum,min);
  else puts("-1");
  return 0;
}