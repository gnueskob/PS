#include<bits/stdc++.h>
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
  memset(prime, 1, (N+1)*sizeof(bool));
	// fill(prime, prime+N+1, 1);
  cout << "Seieve of Eratosthenes\n";
  if(2 > N) return;
  prime[0] = prime[1] = 0;
  for(ll i=3; i*i<=N; i+=2)
    if(prime[i])
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
  for(ll i=3; i*i<=N; i+=2)
    if(!(N%i)) return false;
  return true;
}

// 빠른 제곱 확장
inline ll power(ll n, ll d, ll m) {
	ll k = 1;
	while(d) {
		if(d & 1) k = (k * n) % m;
		n = (n * n) % m;
		d >>= 1;
	}
	return k;
}

// 소수 확인 확장 (밀러 라빈, 64비트 이내 자연수에서 항상 정확함)
// O(klog^3 n) : n 검사할 숫자, k : 소수 판별법을 몇 회 실시할지 결정하는 인자
bool isPrimeEx(ll n) {
	static const ll aPrimes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	static const ll bPrimes[13] = {0, 2047, 1373653, 25326001, 3215031751, 2152302898747, 3474749660383, 341550071728321, 0, 3825123056546413051, 0, 0, 1ll<<63};

	if(n <= 1) return false;
	for(int i = 0; i < 12; i++)
		if(n % aPrimes[i] == 0)
			return n == aPrimes[i];

	ll m = n - 1, s = __builtin_ctzll(m), d = m >> s;
	for(ll i = 0; n > bPrimes[i]; i++) {
		ll x = power(aPrimes[i], d, n), r = 0;
		if(x != 1) {
			for(r = 0; r < s && x != m; r++) x = (x * x) % n;
			if(r == s) return false;
		}
	}
	return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N; cin >> N;
  getAllPrime(N);
  cout << N << " is prime ? : " << boolalpha << isPrime(N) << '\n';
	cout << N << " is prime ? : " << boolalpha << isPrimeEx(N) << " (with isPrimeEx func.)";
  return 0;
}