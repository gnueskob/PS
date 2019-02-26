// 연속합
// https://www.acmicpc.net/problem/1912
#include<iostream>
using namespace std;

const int rbuf_size = 1 << 16;
char buf[rbuf_size];
int len = 0, pos = 0;

inline int getChar() {
  if (pos == len) pos = 0, len = fread(buf, 1, rbuf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32) c = getChar();
  return c;
}

inline int readInt() {
  int s = 1, c = readChar();
  int x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

inline int max(int a, int b) { return a > b ? a : b; }

int n, ans = -1001, mans, maxEnd;
int main() {
  freopen("./input/1912.txt", "r", stdin);
  n = readInt();
  for(int i=0; i<n; i++) ans = max(ans, maxEnd = max(maxEnd, 0) + readInt());
  cout << ans;
  return 0;
}