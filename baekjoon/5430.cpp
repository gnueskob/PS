// AC
// https://www.acmicpc.net/problem/5430
#include<iostream>
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

inline int readWord(char* str) {
  char c; int len=0;
  while((c=getChar()) != '\n' && c != ' ' && c > 32) *str++=c, len++; *str=0;
  return len;
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

inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}

struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

char p[100001];
int num[100000];

int main() {
  freopen("./input/5430.txt", "r", stdin);
  int T, n, len, h, t; T=readInt();
  bool r, e;
  while(T--) {
    len=readWord(p); n=readInt();
    h=0; t=n; r=false; e=false; getChar();
    for(int i=0; i<n; i++) num[i]=readInt(); getChar(); !n?getChar():0;
    for(int i=0; i<len; i++) {
      if(p[i] == 'R') r=!r;
      else {
        r ? t-=1 : h+=1;
        if(h>t) { e=true; break; }
      }
    }
    if(e) writeWord("error\n");
    else {
      writeChar('[');
      if(h<t)
        if(r) { writeInt(num[t-1],0); for(int i=t-2; i>=h; i--) { writeChar(','); writeInt(num[i],0); }}
        else { writeInt(num[h],0); for(int i=h+1; i<t; i++) { writeChar(','); writeInt(num[i],0); }}
      writeWord("]\n");
    }
  }
  return 0;
}