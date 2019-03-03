#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

/**
 * Segment Tree (구간 합)
 * Reference: https://www.acmicpc.net/blog/view/9
 *
 * 필요 상황
 * 1.구간 l, r (l ≤ r)이 주어졌을 때, A[l] + A[l+1] + ... + A[r-1] + A[r]을 구해서 출력하기
 * 2.i번째 수를 v로 바꾸기. A[i] = v
 *
 * 세그먼트 트리를 이용하면, 1번 연산을 O(lgN), 2번 연산도 O(lgN)만에 수행가능
 *
 * 세그먼트 트리의 노드
 * - 리프 노드: 배열의 그 수 자체
 * - 다른 노드: 왼쪽 자식과 오른쪽 자식의 합
 * - 노드의 번호가 x일때, 왼쪽 자식의 번호는 2*x, 오른쪽 자식의 번호는 2*x+1
 */

/**
 * Segment Tree 생성 및 초기화
 * input: input 배열
 * sgmtTree: 세그먼트 트리
 * node: 세그먼트 트리 노드 번호
 * node가 담당하는 합의 범위가 start ~ end (input 기준의 범위)
 */
ll init(vll &input, vll &sgmtTree, int node, int start, int end) {
  if (start == end) {
    return sgmtTree[node] = input[start]; // leaf node
  } else {
    return sgmtTree[node] = init(input, sgmtTree, node * 2, start, (start + end) / 2)        // left child node
                          + init(input, sgmtTree, node * 2 + 1, (start + end) / 2 + 1, end); // right child node
  }
}

/**
 * node가 담당하는 구간이 start ~ end이고, 구해야하는 합의 범위는 left ~ right
 * start ~ end, left ~ right : input 기준의 범위
 * 1.[left,right]와 [start,end]가 겹치지 않는 경우
 * 2.[left,right]가 [start,end]를 완전히 포함하는 경우
 * 3.[start,end]가 [left,right]를 완전히 포함하는 경우
 * 4.[left,right]와 [start,end]가 겹쳐져 있는 경우 (1, 2, 3 제외한 나머지 경우)
 */
ll sum(vll &tree, int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0; // (1)
  if (left <= start && end <= right) return tree[node]; // (2)
  return sum(tree, node*2, start, (start+end)/2, left, right)
        + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

/**
 * 중간에 어떤 수를 변경한다면, 그 숫자가 포함된 구간을 담당하는 노드를 모두 변경
 * index번째 수를 val로 변경, diff = val - a[index]
 * start ~ end, index : input 기준의 범위
 * 1.[start,end]에 index가 포함되는 경우
 * 2.[start,end]에 index가 포함되지 않는 경우
 */
void update(vll &tree, int node, int start, int end, int index, ll diff) {
  if (index < start || index > end) return;
  tree[node] = tree[node] + diff;
  if (start != end) {
    update(tree,node*2, start, (start+end)/2, index, diff);
    update(tree,node*2+1, (start+end)/2+1, end, index, diff);
  }
}

int main() {
  vll input, sgmtTree;

  // Node N개
  int N; cin >> N; input.resize(N+1);
  for(int i=1; i<=N; i++) input[i] = i;

  // segment Tree size : 2^(floor(log(2*N-1))) - 1
  // vector에서는 0번째 index를 사용하지 않고 1번 index부터 사용하는 것이
  // left, right child를 쉽게 접근할 수 있으므로 size를 1개 더 늘려서 사용
  int treeSize, lgN = 0, t = 2*N - 1;
  while(t) lgN++, t>>=1;
  treeSize = 1<<lgN;
  sgmtTree.resize(treeSize);

  // segment tree initialize
  // sgmtTree의 1번 노드(root Node)가 input의 1 ~ N번 노드 합을 담당
  init(input, sgmtTree, 1, 1, N);

  // sgmtTree의 1번 노드부터 시작해서 input의 1 ~ N번 노드 합을 출력
  cout << sum(sgmtTree, 1, 1, N, 1, N) << '\n';
  // input의 1 ~ N/2번 노드 합을 출력
  cout << sum(sgmtTree, 1, 1, N, 1, N/2) << '\n';
  // input의 N/2 + 1 ~ N번 노드 합을 출력
  cout << sum(sgmtTree, 1, 1, N, N/2 + 1, N) << '\n';

  // input의 N/2번 노드에 -1만큼 변화가 생길 시, sgmtTree 갱신
  update(sgmtTree, 1, 1, N, N/2, -1);

  // 갱신 후 input의 N/2 ~ N/2 + 1번 노드 합을 출력
  cout << sum(sgmtTree, 1, 1, N, N/2, N/2+1);
  return 0;
}