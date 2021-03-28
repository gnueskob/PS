#include<iostream>

/**
 * Linux OS based memory mapping code to read input very fast.
 */
/**
 * Normally used form of stat & mmap
 * But can not declare struct stat.
 * struct stat buf; fstat(0, &buf);
 * char* s = (char*) mmap(0, buf.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, 0, 0), *c = s;
 */
/**
 * After read all about input, the memory (*c: used to store input with mmap) is not used anymore.
 * So, we use this memory to store output characters what we write with 'write' function of linux.
 * When reading input is done, the starting memory address(sma) of mmap should be set to c again.
 * This is why we should use resetBuf() function (c = s) before write characters.
 * After assign all of output characters to c, then, c-s will be the length of output characters.
 * if 'write(1, s, c-s)' is called, the characters what we stored to write in 'c' will be output to stdout.
 * Notice: Writing with 'c' should be done only when the number of output characters is fewer than input length.
 */
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/mman.h>
// int buf[36];
// char* s = (char*) mmap(0, buf[12], 3, 2, 0, fstat(0, (struct stat*)buf)), *c = s;
// inline int readInt() {
//   int x=0; bool e;
//   c += e = *c == '-';
//   while(*c >= '0') x = x*10 + *c++ - '0';
//   ++c;
//   return e ? -x : x;
// }
// inline void writeChar(char x) { *c++ = x; }
// template <class T>
// inline void writeInt(T x, char end = 0) {
//   if(x < 0) writeChar('-'), x = -x;
//   char s[24];
//   int n = 0;
//   while(x || !n) s[n++] = '0' + x % 10, x /= 10;
//   while(n--) writeChar(s[n]);
//   if(end) writeChar(end);
// }
// inline void writeWord(const char* s) { while (*s) writeChar(*s++); }
// inline void resetBuf() { c = s; }
// struct Flusher {
//   ~Flusher() { write(1, s, c-s); }
// } flusher;


static const int rbuf_size = 1 << 21;
static const int wbuf_size = 1 << 21;

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

int main() {
  int n = readInt();
  writeInt(n, '\n');
  writeWord("string");
  return 0;
}