// 제곱 ㄴㄴ 수
// https://www.acmicpc.net/problem/1016
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
vector<int> prime;

void getPrime(const int pmax) {
  prime.reserve(74980);
  prime.push_back(2);
  vector<bool> isC(pmax+1,0);

  for(ll i=3; i<=pmax; i+=2)
    if(!isC[i]) {
      prime.push_back(i);
      for(ll j = i*i; j<=pmax; j+=i) isC[j] = true;
    }
}

int main() {
  ll min, max;
  scanf("%lld%lld",&min,&max);
  ll sum = max - min + 1;
  int pmax = sqrt(max);
  getPrime(pmax);
  vector<bool> no(max-min+1,0);
  for(auto p : prime) {
    ll pp = (ll) p*p;
    ll s = ceil(min/(double)pp)*pp;
    for(; s<=max; s+=pp) sum -= no[s-min]==false, no[s-min] = true;
  }
  printf("%d",sum);
  return 0;
}