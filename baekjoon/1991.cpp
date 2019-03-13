// 트리 순회
// https://www.acmicpc.net/problem/1991
#include<cstdio>

class Node {
public:
  Node* left;
  Node* right;
  char val;
};

void order(Node* root, int flag) {
  if(root == nullptr) return;
  if(flag & 1) printf("%c",root->val);
  order(root->left, flag);
  if(flag & 2) printf("%c",root->val);
  order(root->right, flag);
  if(flag & 4) printf("%c",root->val);
}

int main() {
  int N; scanf("%d",&N);
  Node tree[26];
  for(int i=0; i<N; i++) tree[i].val = i + 'A';
  for(int i=0; i<N; i++) {
    char c, l, r;
    scanf("\n%c %c %c", &c, &l, &r);
    auto root = &tree[c-'A'];
    root->left = l == '.' ? nullptr : &tree[l-'A'];
    root->right = r == '.' ? nullptr : &tree[r-'A'];
  }
  order(&tree[0], 1); puts("");
  order(&tree[0], 2); puts("");
  order(&tree[0], 4);
  return 0;
}