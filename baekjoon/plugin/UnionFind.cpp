#include<iostream>
using namespace std;

/**
 * Union Find Alogrithm
 * Disjoint Set 서로소 집합 자료구조
 * make-set(x) : 초기화 - x를 유일한 원소로 하는 새로운 집합을 만든다.
 * union(x, y) : 합하기 - x가 속한 집합과 y가 속한 집합을 합친다. 즉, x와 y가 속한 두 집합을 합치는 연산
 * find(x) : 찾기 - x가 속한 집합의 대표값(루트 노드 값)을 반환한다. 즉, x가 어떤 집합에 속해 있는지 찾는 연산
 * Reference: https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html
 */

/* 초기화 */
const int MAX = 20;
int root[MAX];
int height[MAX]; // 트리의 높이를 저장할 배열
int nodeCnt[MAX]; // 트리의 원소개수를 저장할 배열

/* find(x): 재귀 이용 */
int find(int x) {
  return root[x] == x
  ? x // 루트 노드는 부모 노드 번호로 자기 자신을 가진다..
  : root[x] = find(root[x]);
  // 각 노드의 부모 노드를 찾아 올라간다.
  // "경로 압축(Path Compression)"
  // find 하면서 만난 모든 값의 부모 노드를 root로 만든다
}

/* union(x, y) */
int uni(int x, int y) {
  // 각 원소가 속한 트리의 루트 노드를 찾는다.
  x = find(x);
  y = find(y);
  if(x == y) return nodeCnt[x];
  // root[y] = x; // 1. 최적화 없을 시 naive한 union

  // 2. "union-by-rank 최적화"
  // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다.
  // 즉, 높이가 더 높은 쪽을 root로 삼음
  if(height[x] < height[y]) {
    root[x] = y; // x의 root를 y로 변경

    // union으로 연결된 node의 개수까지 파악하기
    nodeCnt[y] += nodeCnt[x]; // y의 node 수에 x의 node 수를 더한다.
    nodeCnt[x] = 1; // y에 붙은 x의 node 수는 1로 초기화
    return nodeCnt[y]; // 가장 root의 node 수 반환
  } else {
    root[y] = x; // y의 root를 x로 변경
    if(height[x] == height[y]) height[x]++; // 만약 높이가 같다면 합친 후 (x의 높이 + 1)

    // union으로 연결된 node의 개수까지 파악하기
    nodeCnt[x] += nodeCnt[y]; // x의 node 수에 y의 node 수를 더한다.
    nodeCnt[y] = 1; // x에 붙은 y의 node 수는 1로 초기화
    return nodeCnt[x]; // 가장 root의 node 수 반환
  }
}

int main() {
  /* 초기화 */
  for(int i=0; i<MAX; i++) root[i] = i;
  for(int i=0; i<MAX; i++) nodeCnt[i] = 1;

  // {0,1,2,3,4}, {5,6,7}, {8,9,10,11}
  for(int i=1; i<5; i++) uni(i-1,i);
  for(int i=6; i<8; i++) uni(i-1,i);
  for(int i=9; i<12; i++) uni(i-1,i);

  // 각 node의 root 번호
  cout << "{0,1,2,3,4}, {5,6,7}, {8,9,10,11}\n";
  cout << "root of node ";
  for(int i=0; i<12; i++) cout << i << "->" << root[i] << ", ";
  // 각 node를 root로 하는 tree의 node 개수
  cout << "\nnode Count ";
  for(int i=0; i<12; i++) cout << i << " : " << nodeCnt[i] << ", ";

  // {0,1,2,3,4,5,6,7}, {8,9,10,11}
  cout << "\n{0,1,2,3,4,5,6,7}, {8,9,10,11}\n";
  cout << "combined between 4 & 5 node, tree Conunt : " << uni(4,5) << '\n';
  cout << "\nroot of node ";
  for(int i=0; i<12; i++) cout << i << "->" << root[i] << ", ";
  cout << "\nnode Count ";
  for(int i=0; i<12; i++) cout << i << " : " << nodeCnt[i] << ", ";
  return 0;
}