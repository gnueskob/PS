#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;
const ll MAXN = (ll) 1e9;
bool prime[MAXN+1];
/**
 * Seieve of Eratosthenes
 * O(nlog(logn)))
 * prime 배열의 모든 index가 전부 소수라는 가정으로 시작
 *
 * 3부터 시작하여 index를 2씩 증가시켜 나감으로써 for loop 시간 단축 (2는 소수로 미리 세팅)
 * 소수의 배수를 unset시킴으로써 소수가 아님을 나타냄
 *
 * 특정 소수의 배수를 unset 시킬 때 해당 소수의 제곱에 해당하는 index부터 삭제시켜 나감
 * 특정 소수 n을 검사할 시점에는 이미 [1, n-1]까지의 수를 검사하며 n의 배수 index를 unset시켰기 때문
 * 따라서 n(n-1) 까지 이미 소수 검사가 끝나있는 상태이며 n*n index부터 unset시켜나가도 무방함
 */
void getAllPrime(int N) {
  memset(prime, 1, sizeof(N+1));
  cout << "Seieve of Eratosthenes\n";
  if(2 > N) return;
  prime[0] = prime[1] = 0;
  for(ll i=3; i<=N; i+=2)
    if(i*i<=N && prime[i])
      for(ll j=i*i; j<=N; j+=i) prime[j] = false;

  cout << 2 << '\n';
  for(ll i=3; i<=N; i+=2) if(prime[i]) cout << i << '\n';
}

/**
 * 주어진 수가 소수인지 아닌지만 판별
 * O(sqrt(N))
 * 에라토스테네스의 체보다 빠르게 주어진 수에 대해서만 판단
 */
bool isPrime(int N) {
  if(!(N%2)) return false;
  for(long long i=3; i*i<=N; i+=2)
    if(!(N%i)) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N; cin >> N;
  getAllPrime(N);
  cout << N << " is prime ? : " << boolalpha << isPrime(N);
  return 0;
}