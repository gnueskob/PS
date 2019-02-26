// 내리막 길
// https://www.acmicpc.net/problem/1520
#include<iostream>
using namespace std;

static const int rbuf_size = 1 << 10;
static const int wbuf_size = 1 << 4;

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

int N, M, ans, grid[500][500];
int visit[500][500];
int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
inline bool isInGrid(int r, int c) { return 0 <= r && r < N && 0 <= c && c < M; }

bool dfs(int r, int c) {
  if(r == N-1 && c == M-1) return true;
  else if(visit[r][c] == -1) return false;
  bool isGoal = false;
  for(int d=0; d<4; d++) {
    int nr = r + dr[d], nc = c + dc[d];
    if(isInGrid(nr, nc) && grid[r][c] > grid[nr][nc]
    && (visit[nr][nc] > 0 || !visit[nr][nc] && dfs(nr, nc))) {
      visit[r][c] += visit[nr][nc];
      isGoal = true;
    }
  }
  if(!isGoal) visit[r][c] = -1;
  return isGoal;
}

int main() {
  freopen("./input/1520.txt", "r", stdin);
  N = readInt(); M = readInt(); visit[N-1][M-1] = 1;
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) grid[i][j] = readInt();
  dfs(0, 0);
  writeInt(visit[0][0], 0);
  return 0;
}