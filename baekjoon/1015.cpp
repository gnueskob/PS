// 수열 정렬
// https://www.acmicpc.net/problem/1015
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;

#define mp make_pair
typedef pair<int, int> pii;

int main() {
  int n; scanf("%d",&n);
  pii A[50], sortA[50];
  map<pii, int> m;
  for(int i=0; i<n; i++) {
    int num; scanf("%d",&num);
    sortA[i] = A[i] = mp(num, i);
    m.insert(mp(A[i],0));
  }
  sort(sortA, sortA+n);
  for(int i=0; i<n; i++) { m.find(sortA[i])->second = i; }
  for(int i=0; i<n; i++) { printf("%d ",m.find(A[i])->second); }
  return 0;
}