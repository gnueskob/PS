// 정수 삼각형
// https://www.acmicpc.net/problem/1932
#include<iostream>
using namespace std;

static const int rbuf_size = 1 << 16;
static const int wbuf_size = 1 << 16;

inline int getChar() {
  static char buf[rbuf_size];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, rbuf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32) c = getChar();
  return c;
}

template <class T = int>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

static int write_pos = 0;
static char write_buf[wbuf_size];

inline void writeChar(int x) {
  if (write_pos == wbuf_size)
    fwrite(write_buf, 1, wbuf_size, stdout), write_pos = 0;
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

struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

int sum[500];

int main() {
  freopen("./input/1932.txt", "r", stdin);
  int n, pprev, prev, next; n=readInt();
  for(int i=1; i<=n; i++) {
    for(int j=0; j<i; j++) {
      next=readInt();
      prev = sum[j];
      if(!j) sum[j] += next;
      else if(j == i-1) sum[j] = pprev + next;
      else { sum[j] = (prev > pprev ? prev : pprev) + next; }
      pprev = prev;
    }
  }
  int max = sum[0];
  for(int i=0; i<n; i++) max = max < sum[i] ? sum[i] : max;
  writeInt(max,0);
  return 0;
}