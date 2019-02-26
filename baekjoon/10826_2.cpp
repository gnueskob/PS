// 피보나치 수 4
// https://www.acmicpc.net/problem/10826
#include<cstdio>
#include<vector>
using namespace std;
typedef unsigned long long ull;
const ull MAX = (ull)1e18;
typedef vector<ull> vl;
vl ans(1,0), n(1,1), t;

int main() {
  int N, i, carry; scanf("%d",&N);
  while(N--) {
    t.resize(n.size()); carry = 0;
    for(i=0; i<ans.size(); i++) {
      t[i] = (ans[i] + n[i] + carry) % MAX;
      carry = (ans[i] + n[i] + carry) >= MAX;
    }
    if(n.size() > ans.size()) t[i] = n[i] + carry;
    else if(carry) t.push_back(1);
    ans = n;
    n = t;
  }
  printf("%llu",ans[ans.size()-1]);
  for(i=ans.size()-2; i>=0; i--) printf("%018llu",ans[i]);
  return 0;
}