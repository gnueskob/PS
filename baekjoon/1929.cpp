// 소수 구하기
// https://www.acmicpc.net/problem/1929
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

static const int buf_size = 1 << 16;

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end) {
  if (x < 0) writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n--) writeChar(s[n]);
  if (end) writeChar(end);
}

inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}

struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

const int MAXN = 1000000;
bool prime[MAXN+1];

int main() {
  freopen("./input/1929.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  int M, N; cin >> M >> N; if(M == 1) M++;
  memset(prime, 1, sizeof(prime));
  if(M <= 2 && 2 <= N) writeInt(2,'\n');
  for(long long i=3; i<=N; i+=2) {
    if(i*i<=N && prime[i]) for(int j=i*i; j<=N; j+=i) prime[j]=false;
    if(M <= i && i <= N) if(prime[i]) writeInt(i,'\n');
  }
  return 0;
}