// 트리의 순회
// https://www.acmicpc.net/problem/2263
#include<bits/stdc++.h>
using namespace std;

inline int readInt() {int a;cin>>a;return a;}
inline void writeChar(char x) {cout<<x;}
template <typename T> inline
void writeInt(T x,char e) {if(x<0)writeChar(45),x=-x;char s[24];int l=0;while(x)s[l++]=x%10,x/=10;while(l--)writeChar(s[l]+48);if(e)writeChar(e);}

const int MAX = 100000;
int idx[MAX+1], in[MAX], post[MAX];

void makeTree(int l_in, int r_in, int l_post, int r_post) {
  if(l_post>r_post) return;
  int root = post[r_post];
  writeInt(root,' ');
  int m = idx[root];
  makeTree(l_in, m-1, l_post, l_post + m - l_in - 1);
  makeTree(m+1, r_in, r_post - r_in + m, r_post-1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n; n=readInt();
  for(int i=0; i<n; i++) in[i]=readInt(), idx[in[i]] = i;
  for(int i=0; i<n; i++) post[i]=readInt();
  makeTree(0, n-1, 0, n-1);
  return 0;
}