// 트리의 높이와 너비
// https://www.acmicpc.net/problem/2250
#include<bits/stdc++.h>
using namespace std;

inline int readInt() {int a;cin>>a;return a;}
inline void writeChar(char x) {cout<<x;}
template <typename T> inline
void writeInt(T x,char e) {if(x<0)writeChar(45),x=-x;char s[24]{};int l=0;while(x||!l)s[l++]=x%10,x/=10;while(l--)writeChar(s[l]+48);if(e)writeChar(e);}

class Node {
  public:
  short parent;
  short left;
  short right;
  Node() { parent = left = right = 0; }
};

vector<Node> tree;
vector<pair<short, short>> w;
int maxH;

void order(int root, int h) {
  if(!root) return;
  static int idx = 1;
  order(tree[root].left, h+1);
  if(!w[h].first) w[h].first = idx;
  else if(w[h].second < idx) w[h].second = idx;
  idx++;
  order(tree[root].right, h+1);
  if(maxH < h) maxH = h;
}

int main() {
  int N = readInt();
  tree.assign(N+1,Node());
  w.assign(N+1,{0, 0});
  for(int i=N; i--;) {
    int p=readInt(), l=readInt(), r=readInt();
    if(l > 0) tree[p].left = l, tree[l].parent = p;
    if(r > 0) tree[p].right = r, tree[r].parent = p;
  }
  int root = 0;
  for(int i=1; i<=N; i++) if(!tree[i].parent) { root = i; break; }
  order(root, 1);
  int maxW = 1, height = 1;
  for(int i=2; i<=maxH; i++) {
    int width = w[i].second - w[i].first + 1;
    if(maxW < width) maxW = width, height = i;
  }
  printf("%d %d",height,maxW);
  return 0;
}