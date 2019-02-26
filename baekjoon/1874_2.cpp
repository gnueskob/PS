// 스택 수열
// https://www.acmicpc.net/problem/1874
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

static const int rbuf_size = 1 << 16;
static const int wbuf_size = 1 << 19;

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

inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}

struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

const int MAXN = 100000;
int num[MAXN+1];

int main() {
  freopen("./input/1874.txt", "r", stdin);
  int N = readInt(), n, max=0, prev, stIdx=0, stNum=1;
  while(N--) {
    n = readInt();
    if(prev < max && n < max && prev < n) { write_pos=0; writeWord("NO"); return 0; }
    if(!stIdx || num[stIdx] < n)
      do { num[++stIdx] = stNum++; writeWord("+\n"); } while(num[stIdx] != n);
    if(stIdx && num[stIdx] >= n)
      do { stIdx--; writeWord("-\n"); } while(num[stIdx+1] != n);
    max = max < n ? n : max;
    prev = n;
  }
  return 0;
}