// problem_name
// url
#include<bits/stdc++.h>
using namespace std;

// #include "_fileRead.hpp"
// GNUES::FileRead f("__.txt");

inline int readInt() {int a;scanf("%d",&a);return a;}
inline void writeChar(char x) {printf("%c",x);}
template <typename T> inline
void writeInt(T x,char e) {if(x<0)writeChar(45),x=-x;char s[24]{};int l=0;while(x||!l)s[l++]=x%10,x/=10;while(l--)writeChar(s[l]+48);if(e)writeChar(e);}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  // freopen("./input/1918.txt", "r", stdin);
  std::ifstream file("./baekjoon/input/10951.txt");
  if (file.is_open() == false)
      return 0;
  std::cin.rdbuf(file.rdbuf()); // swap

  return 0;
}