// 가장 가까운 두 점
// https://www.acmicpc.net/problem/2261
#include<bits/stdc++.h>
using namespace std;

inline int readInt() {int a;cin>>a;return a;}
inline void writeChar(char x) {cout<<x;}
template <typename T> inline
void writeInt(T x,char e) {if(x<0)writeChar(45),x=-x;char s[24];int l=0;while(x||!l)s[l++]=x%10,x/=10;while(l--)writeChar(s[l]+48);if(e)writeChar(e);}

#define X first
#define Y second
#define mp make_pair
typedef pair<short, short> ps;

const short INF = 30000;
int powd(const ps& a, const ps& b) {
  int x = a.X - b.X, y = a.Y - b.Y;
  return x*x + y*y;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // freopen("./baekjoon/input/4.in", "r", stdin);
  set<ps> bst;
  int n=readInt();
  vector<ps> p(n);
  for(int i=0; i<n; i++) p[i].X = readInt(), p[i].Y = readInt();
  sort(p.begin(), p.end());
  bst.insert(mp(p[0].Y, p[0].X));
  bst.insert(mp(p[1].Y, p[1].X));

  int d = powd(p[0], p[1]);
  int last = 0;
  for(int i=2; i<n; i++) {
    while(last<i) {
      int dx = p[i].X - p[last].X;
      if(d >= dx*dx) break;
      else bst.erase(mp(p[last].Y, p[last].X)), last++;
    }
    double delta = sqrt(d);
    auto lb = bst.lower_bound(mp(p[i].Y-delta, -INF));
    auto ub = bst.upper_bound(mp(p[i].Y+delta, INF));
    for(auto it=lb; it!=ub; it++) d = min(d,powd(mp(p[i].Y, p[i].X), *it));
    bst.insert(mp(p[i].Y, p[i].X));
    if(!d) { cout << 0; return 0; }
  }
  writeInt(d,0);
  return 0;
}