// 통계학
// https://www.acmicpc.net/problem/2108
#include<iostream>
#include<cmath>
using namespace std;

static const int buf_size = 1 << 16;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
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

inline void writeWord(const char *s, char end) {
  while (*s) writeChar(*s++);
  if (end) writeChar(end);
}

struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

const int MAXN = 4000;
int num[2*MAXN + 1] = {0,};

int main() {
  // freopen("input/2108.txt", "r", stdin);
  int N = readInt(), med=9999, fre1=2*MAXN, fre2=2*MAXN, min=4000, max=-4000, n, cnt=0;
  double aver = 0.0;
  for(int i=0; i<N; i++) {
    n = readInt();
    aver += (1.0)*n/N;
    min = min > n ? n : min;
    max = max < n ? n : max;
    num[n+MAXN]++;
  }
  for(int i=2*MAXN; i>=0; i--) {
    int tempFrequency = num[i];
    if(num[fre1] <= tempFrequency) { fre2 = fre1; fre1 = i; }
    while(tempFrequency-- && med==9999) if(cnt++ == N/2) { med = i; break; }
  }
  if(abs(aver-(int)aver) >= 0.5) aver = aver > 0 ? aver+1 : aver-1;
  if(num[fre1] == num[fre2]) fre1 = fre2;
  int ans[] = {(int)aver, med-MAXN, fre1-MAXN, max-min};
  for(int i=0; i<4; i++) writeInt(ans[i],'\n');
  return 0;
}