// 단어 정렬
// https://www.acmicpc.net/problem/1181
#include<iostream>
#include<cstring>
#include<set>
using namespace std;

static const int buf_size = 1 << 12;

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

inline void readString(char* str) {
  char c, idx=0;
  while((c = getChar()) != '\n' || c != ' ' && c > 32) {
    str[idx++] = c;
  }
  str[idx] = 0;
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
  if(end) writeChar(end);
}

inline void writeWord(const string& s, char end) {
  int len = s.size();
  for(int i=0; i<len; i++) writeChar(s.at(i));
  if(end) writeChar(end);
}

struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

typedef pair<int, string> p;

int main() {
  freopen("./input/1181.txt", "r", stdin);
  int n;
  char str[50];
  set<p> s;
  n = readInt();
  while(n--) { readString(str); s.insert({strlen(str), string(str)}); }
  for(auto& t : s) writeWord(t.second,'\n');
}