// 베르트랑 공준
// https://www.acmicpc.net/problem/4948
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 123456;
bool prime[MAXN*2];

int main() {
  int N, ans;
  memset(prime, 1, sizeof(prime));
  prime[1] = false;
  for(long long i=3; i*i<MAXN*2; i+=2)
    if(prime[i]) for(int j=i*i; j<MAXN*2; j+=i) prime[j]=false;
  while(true) {
    scanf("%d",&N); ans=0; int i = N+1;
    if(N==0) return 0;
    else if(N==1) { printf("1\n"); continue; }
    else if(N%2 == 1) i++;
    for(; i<2*N; i+=2) if(prime[i]) ans++;
    printf("%d\n",ans);
  }
  return 0;
}