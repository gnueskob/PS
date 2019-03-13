// 일곱 난쟁이
// https://www.acmicpc.net/problem/2309
#include<cstdio>
#include<algorithm>
using namespace std;

int tall[9];
bool isDwarf[9];

bool solve(int idx, int sum, int cnt) {
  isDwarf[idx] = true;
  cnt++;
  sum += tall[idx];
  if(cnt >= 7) {
    if(cnt == 7 && sum == 100) {
      for(int i=0; i<9; i++) if(isDwarf[i]) printf("%d\n",tall[i]);
      return true;
    }
    isDwarf[idx] = false;
    return false;
  }

  for(int i=idx+1; i<9; i++) if(solve(i, sum, cnt)) return true;
  isDwarf[idx] = false;
  return false;
}

int main() {
  for(int i=0; i<9; i++) scanf("%d",&tall[i]);
  sort(tall, tall+9);
  solve(0, 0, 0);
  return 0;
}