// 떨어지는 개미
// https://www.acmicpc.net/problem/3163
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include <functional>
using namespace std;

static const int rbuf_size = 1 << 20;
static const int wbuf_size = 1 << 8;

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

int main() {
  freopen("./baekjoon/input/3163.txt", "r", stdin);
  int T, N, L, k; T=readInt();
  vector<pair<int, int>> ants;
  vector<int> left, right;
  while(T--) {
    N=readInt(), L=readInt(), k=readInt();
    int ln=0, rn=0, i;
    ants.clear(); left.clear(); right.clear();
    ants.reserve(N); left.reserve(N); right.reserve(N);
    for(i=0; i<N; i++) {
      int pos=readInt(), id=readInt();
      if(id>0) pos = L - pos;
      pair<int, int> ant(0,id);
      ants.push_back(ant);
      if(id>0) right.push_back(pos), rn++;
      else left.push_back(pos), ln++;
    }
    int idx=0;
    for(i=0; i<ln; i++) ants[idx++].first = left[i];
    for(i=0; i<rn; i++) ants[idx++].first = right[i];
    sort(ants.begin(), ants.end());
    if(N-k < k) k=N-k+1, nth_element(ants.begin(), ants.begin() + k-1, ants.end(), greater<pair<int, int>>());
    else nth_element(ants.begin(), ants.begin() + k-1, ants.end());
    // nth_element(ants.begin(), ants.begin() + k-1, ants.end());
    writeInt(ants[k-1].second,'\n');
  }
  return 0;
}