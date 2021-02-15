// https://www.acmicpc.net/problem/10814
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <fstream>

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL); std::cin.tie(NULL);

//     std::ifstream file("./baekjoon/input/10814.txt");
//     if (file.is_open() == false)
//         return 0;
//     std::cin.rdbuf(file.rdbuf()); // swap

//     std::vector<std::string> man[200];
//     int N, age;
//     std::string name;
//     std::cin >> N;

//     while (N--)
//     {
//         std::cin >> age >> name;
//         man[age].emplace_back(name);
//     }

//     for (int i = 0; i < 200; ++i)
//     {
//         if (man[i].empty() == false)
//             for (auto const& name_str : man[i])
//                 std::cout << i + 1 << ' ' << name_str << '\n';
//     }
// }

// https://www.acmicpc.net/problem/10814
#include <iostream>
#include <vector>

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

int main()
{
    freopen("./baekjoon/input/10814.txt", "r", stdin);

    std::vector<std::string> names[201];
    int N = readInt();

    char name[101];
    while (N--)
    {
        int age = readInt();
        readWord(name);
        std::string name_str(name);
        names[age].emplace_back(std::move(name_str));
    }

    for (int i = 1; i < 201; ++i)
    {
        if (names[i].empty() == false)
        {
            for (const auto& name : names[i])
                std::cout << i << ' ' << name << '\n';
        }
    }
}