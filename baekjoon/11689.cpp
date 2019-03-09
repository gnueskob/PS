// GCD(n, k) = 1
// https://www.acmicpc.net/problem/11689
#include <cstdio>

typedef long long ll;

int main() {
  ll n;
  scanf("%lld", &n);
  ll pi = n;
  if(isPrimeEx(n)) return !printf("%d",n-1);
  if(!(n & 1)) {
    pi >>= 1;
    n /= n & -n;
  }
  ll prime = 3;
  while (prime * prime <= n) {
    if (!(n%prime)) pi = pi / prime * ~-prime;
    while(!(n%prime)) n = n / prime;
    prime += 2;
  }
  if (n > 1) pi = pi / n * ~-n;
  printf("%lld", pi);
  return 0;
}

